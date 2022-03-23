function run_kde_log(run)
% run approximate inference with KDE method for dataset number "run" (between 1 and 100).  Here the data is log transformed.

load('data100.mat')
y = y(:,run);

% TUNED
cov_rw = [1.48486764304761,-0.0264281818630284,-0.00138304956350000;-0.0264281818630284,0.102499736493811,-0.000472476723505531;-0.00138304956350000,-0.000472476723505531,0.0408659149927459];


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
logswitch = 1;

tic;
[theta, loglike] = bayes_mg1_kde(y,m,M,cov_rw,prior,logswitch);
finaltime = toc;

save(['results_mcmc_100_kde_log_run' num2str(run) '.mat'],'theta','loglike','finaltime');


end
