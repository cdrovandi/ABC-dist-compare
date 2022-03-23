function run_bsl_log(run)
% run BSL with summary statistics for dataset number "run" (between 1 and 100).  Here the data is log transformed.

load('data100.mat')
y = y(:,run);

load('bsl_input_log.mat'); % this contains number of components used in mixture model for forming summaries


% TUNED
cov_rw = [0.937179460646337,-0.000708766076338926,-0.0153089796149005;-0.000708766076338926,0.121099900570322,0.0183203118165271;-0.0153089796149005,0.0183203118165271,0.0624082041543859];

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
[theta, loglike] = bayes_mg1_bsl_aux(y,m,M,cov_rw,prior,bsl_input(run,2),logswitch);
finaltime = toc;

save(['results_mcmc_100_bsl_log_run' num2str(run) '.mat'],'theta','loglike','finaltime');


end
