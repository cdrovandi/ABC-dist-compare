function run_mmd(run)
% run ABC with MMD distance for dataset number "run" (between 1 and 100)

load('data100.mat')
y = y(:,run);

% tune the ABC tolerance
for i=1:100000
    x = simulate_mg1([1,5,0.2],length(y)+1);
    dist(i) = MMD_dist(x,y);
end

eps = quantile(dist, 0.01);

% TUNED
cov_rw = [3.00778007102357,-0.155729310250986,-0.0514946751245833;-0.155729310250986,0.0965009273842893,0.00527934878941661;-0.0514946751245833,0.00527934878941661,0.0730715741960950];

% define prior
prior.num_params = 3;
prior.p1 = [0,min(y),0];
prior.p2 = [min(y),10+min(y),0.5];
prior.sampler = @() [unifrnd(prior.p1,prior.p2)]; 
prior.pdf = @(theta) prod(exp(theta)./(1 + exp(theta)).^2);
prior.trans_f = @(theta) [log((theta - prior.p1)./(prior.p2 - theta))];
prior.trans_finv = @(theta) [(prior.p2.*exp(theta) + prior.p1)./(1 + exp(theta))];

M = 1e7; 
logswitch = 0;

tic;
[theta, dist] = bayes_mg1_abc_mmd(y,eps,M,cov_rw,prior,logswitch);
finaltime = toc;

save(['results_mcmc_100_mmd_run' num2str(run) '.mat'],'theta','dist','finaltime','eps');


end
