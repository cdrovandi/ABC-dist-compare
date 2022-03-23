function run_mmd_100(run)

% run ABC with MMD distance for dataset of size 100 for dataset number "run" (between 1 and 100)

load('data100.mat')
y = y(:,run);

n = length(y);

% tune the ABC tolerance
for i=1:100000
    x = simulate_gk(n,[3 1 2 0.5]);
    dist(i) = MMD_dist(x,y);
end

eps = quantile(dist, 0.01);

% TUNED
cov_rw = [0.00279908130687883,0.00773512587014727,-0.0242185637192247,-0.00876006048633831;0.00773512587014727,0.0722821140660837,0.0130322029723006,-0.166379786643725;-0.0242185637192247,0.0130322029723006,1.12272596917261,0.0103332833496971;-0.00876006048633831,-0.166379786643725,0.0103332833496971,0.926879891874053];


% define prior
prior.num_params = 4;
prior.p1 = [0 0 0 0];
prior.p2 = [10 10 10 10];
prior.sampler = @() [unifrnd(prior.p1,prior.p2)]; 
prior.pdf = @(theta) prod(exp(theta)./(1 + exp(theta)).^2);
prior.trans_f = @(theta) [log((theta - prior.p1)./(prior.p2 - theta))];
prior.trans_finv = @(theta) [(prior.p2.*exp(theta) + prior.p1)./(1 + exp(theta))];

tic;
[theta,dist] = bayes_gandk_abc_mmd(y,n,eps,1e7,cov_rw,prior);
finaltime = toc;

save(['results_mcmc_100_mmd_run' num2str(run) '.mat'],'theta','dist','finaltime','eps');


end
