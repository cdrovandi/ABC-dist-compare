function run_mmd_log(run)
% run ABC with MMD distance for dataset number "run" (between 1 and 100).  Here the data are log transformed.

load('data100.mat')
y = y(:,run);

% tune the ABC tolerance
for i=1:100000
    x = simulate_mg1([1,5,0.2],length(y)+1);
    x = log(x);
    dist(i) = MMD_dist(x,log(y));
end

eps = quantile(dist, 0.01);

% TUNED
cov_rw = [1.76005365833768,-0.0937808335277701,-0.0307840499233309;-0.0937808335277701,0.152732082478921,0.0318487882091016;-0.0307840499233309,0.0318487882091016,0.0914012450564103];

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
[theta, dist] = bayes_mg1_abc_mmd(y,eps,M,cov_rw,prior,logswitch);
finaltime = toc;

save(['results_mcmc_100_mmd_log_run' num2str(run) '.mat'],'theta','dist','finaltime','eps');


end
