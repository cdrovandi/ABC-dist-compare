function run_cvm_log(run)
% run ABC with CvM distance for dataset number "run" (between 1 and 100).  Here the data is log transformed.

load('data100.mat')
y = y(:,run);

% tune the ABC tolerance
for i=1:100000
    x = simulate_mg1([1,5,0.2],length(y)+1);
    x = log(x);
    dist(i) = cvm_stat_M(x,log(y),2);
end

eps = quantile(dist, 0.01);

% TUNED
cov_rw = [2.07988727526810,-0.0213058445188446,-0.00310340778841822;-0.0213058445188446,0.107698861173707,0.0161845788426849;-0.00310340778841822,0.0161845788426849,0.0706313689047327];

% define prior
prior.num_params = 3;
prior.p1 = [0,min(y),0];
prior.p2 = [min(y),10+min(y),0.5];
prior.sampler = @() [unifrnd(prior.p1,prior.p2)]; 
prior.pdf = @(theta) prod(exp(theta)./(1 + exp(theta)).^2);
prior.trans_f = @(theta) [log((theta - prior.p1)./(prior.p2 - theta))];
prior.trans_finv = @(theta) [(prior.p2.*exp(theta) + prior.p1)./(1 + exp(theta))];

M = 1e7; 
logswitch = 1;

tic;
[theta, dist] = bayes_mg1_abc_cvm(y,eps,M,cov_rw,prior,logswitch);
finaltime = toc;

save(['results_mcmc_100_cvm_log_run' num2str(run) '.mat'],'theta','dist','finaltime','eps');


end
