function run_bsl_100(run)

% run BSL with summary statistics for dataset of size 100 for dataset number "run" (between 1 and 100)

load('data100.mat')
y = y(:,run);

n = length(y);

load('bsl_input_100.mat') % this contains number of components used in mixture model for forming summaries
numComp = bsl_input_100(run,2);

m = 50;

% TUNED
cov_rw = [0.00354862371705708,0.0100432715000140,-0.00892228604398757,-0.0115360428708387;0.0100432715000140,0.0583090115606533,-0.000835188303313756,-0.0757252081004190;-0.00892228604398757,-0.000835188303313756,0.0653624479615574,0.0107535785728523;-0.0115360428708387,-0.0757252081004190,0.0107535785728523,0.167430224841150];

% define prior
prior.num_params = 4;
prior.p1 = [0 0 0 0];
prior.p2 = [10 10 10 10];
prior.sampler = @() [unifrnd(prior.p1,prior.p2)]; 
prior.pdf = @(theta) prod(exp(theta)./(1 + exp(theta)).^2);
prior.trans_f = @(theta) [log((theta - prior.p1)./(prior.p2 - theta))];
prior.trans_finv = @(theta) [(prior.p2.*exp(theta) + prior.p1)./(1 + exp(theta))];

tic;
[theta,dist] = bayes_gandk_bsl_aux(y,n,m,100000,cov_rw,prior,numComp);
finaltime=toc;

save(['results_mcmc_100_bsl_run' num2str(run) '.mat'],'theta','dist','finaltime');


end
