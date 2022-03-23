function run_bsl_1000(run)

% run BSL with summary statistics for dataset of size 1000 for dataset number "run" (between 1 and 100)

load('data1000.mat')
y = y(:,run);

n = length(y);

load('bsl_input_1000.mat') % this contains number of components used in mixture model for forming summaries
numComp = bsl_input_1000(run,2);

m = 50;

% TUNED
cov_rw = [0.000307902568337377,0.000960665526421218,-0.000617706853215913,-0.000971187432628533;0.000960665526421218,0.00620140065416295,0.000597334226390673,-0.00635172827233088;-0.000617706853215913,0.000597334226390673,0.00564372819090740,0.00130415428728972;-0.000971187432628533,-0.00635172827233088,0.00130415428728972,0.0108445477978650];

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

save(['results_mcmc_1000_bsl_run' num2str(run) '.mat'],'theta','dist','finaltime');


end
