function run_bsl(run)
% run BSL with summary statistics for dataset number "run" (between 1 and 100)

load('data100.mat')
y = y(:,run);

load('bsl_input.mat'); % this contains number of components used in mixture model for forming summaries


% TUNED
cov_rw = [1.70944752202845,-0.0146003389070511,-0.0307353186588756;-0.0146003389070511,0.0492509970843533,-0.00367966381435830;-0.0307353186588756,-0.00367966381435830,0.0587485631184554];

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
[theta, loglike] = bayes_mg1_bsl_aux(y,m,M,cov_rw,prior,bsl_input(run,2),logswitch);
finaltime = toc;

save(['results_mcmc_100_bsl_run' num2str(run) '.mat'],'theta','loglike','finaltime');


end
