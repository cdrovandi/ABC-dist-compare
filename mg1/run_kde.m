function run_kde(run)
% run approximate inference with KDE method for dataset number "run" (between 1 and 100)

load('data100.mat')
y = y(:,run);

% TUNED
cov_rw = [2.05335660267310,-0.00507945477982085,-0.0285511678974247;-0.00507945477982085,0.0560664507232668,-0.000688207623176977;-0.0285511678974247,-0.000688207623176977,0.0404019489428982];

% define prior
prior.num_params = 3;
prior.p1 = [0,min(y),0];
prior.p2 = [min(y),10+min(y),0.5];
prior.sampler = @() [unifrnd(prior.p1,prior.p2)]; 
prior.pdf = @(theta) prod(exp(theta)./(1 + exp(theta)).^2);
prior.trans_f = @(theta) [log((theta - prior.p1)./(prior.p2 - theta))];
prior.trans_finv = @(theta) [(prior.p2.*exp(theta) + prior.p1)./(1 + exp(theta))];

m = 100;

M = 100000; % number of simulations 
logswitch = 0;

tic;
[theta, loglike] = bayes_mg1_kde(y,m,M,cov_rw,prior,logswitch);
finaltime = toc;

save(['results_mcmc_100_kde_run' num2str(run) '.mat'],'theta','loglike','finaltime');


end
