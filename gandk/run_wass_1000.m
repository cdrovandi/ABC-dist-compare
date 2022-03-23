function run_wass_1000(run)

% run ABC with Wass distance for dataset of size 1000 for dataset number "run" (between 1 and 100)

load('data1000.mat')
y = y(:,run);

n = length(y);

% tune the ABC tolerance
for i=1:100000
    x = simulate_gk(n,[3 1 2 0.5]);
    dist(i) = Wass_stat_M(x,y,1);
end

eps = quantile(dist, 0.01);

% TUNED
cov_rw = [0.000378432899109056,0.000870304241575387,-0.00119301265510988,-0.00100724647791958;0.000870304241575387,0.00932908247480363,0.00230605823390673,-0.0114726328901133;-0.00119301265510988,0.00230605823390673,0.0156065112052845,1.44058020925219e-05;-0.00100724647791958,-0.0114726328901133,1.44058020925219e-05,0.0218963220758371];

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

save(['results_mcmc_1000_wass_run' num2str(run) '.mat'],'theta','dist','finaltime','eps');


end
