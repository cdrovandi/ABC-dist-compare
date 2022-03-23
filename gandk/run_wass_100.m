function run_wass_100(run)

% run ABC with Wass distance for dataset of size 100 for dataset number "run" (between 1 and 100)

load('data100.mat')
y = y(:,run);

n = length(y);

% tune the ABC tolerance
for i=1:100000
    x = simulate_gk(n,[3 1 2 0.5]);
    dist(i) = Wass_stat_M(x,y,1);
end

eps = quantile(dist, 0.01);

% TUNED
cov_rw = [0.00395704157562550	0.00575469238181253	-0.0428438883489085	-0.0115506423087838;...
0.00575469238181253	0.0643904092877776	-0.000659547287101048	-0.162780899868077;...
-0.0428438883489085	-0.000659547287101048	1.11795064638688	0.0584745415184396;...
-0.0115506423087838	-0.162780899868077	0.0584745415184396	0.809135776947481];

% define prior
prior.num_params = 4;
prior.p1 = [0 0 0 0];
prior.p2 = [10 10 10 10];
prior.sampler = @() [unifrnd(prior.p1,prior.p2)]; 
prior.pdf = @(theta) prod(exp(theta)./(1 + exp(theta)).^2);
prior.trans_f = @(theta) [log((theta - prior.p1)./(prior.p2 - theta))];
prior.trans_finv = @(theta) [(prior.p2.*exp(theta) + prior.p1)./(1 + exp(theta))];

tic;
[theta,dist] = bayes_gandk_abc_wass(y,n,eps,1e7,cov_rw,prior);
finaltime = toc;

save(['results_mcmc_100_wass_run' num2str(run) '.mat'],'theta','dist','finaltime','eps');


end
