function run_cvm_1000(run)

% run ABC with CvM distance for dataset of size 1000 for dataset number "run" (between 1 and 100)

load('data1000.mat')
y = y(:,run);

n = length(y);

% tune the ABC tolerance
for i=1:100000
    x = simulate_gk(n,[3 1 2 0.5]);
    dist(i) = cvm_stat_M(x,y,2);
end

eps = quantile(dist, 0.01);

% TUNED
cov_rw = [0.000278911120149644,0.00106953191000241,-0.000422250632770004,-0.00122693526068157;0.00106953191000241,0.00739615036520715,0.000829753313081923,-0.00742668175586823;-0.000422250632770004,0.000829753313081923,0.00552943884669263,0.00299571664385270;-0.00122693526068157,-0.00742668175586823,0.00299571664385270,0.0138842305282867];

% define prior
prior.num_params = 4;
prior.p1 = [0 0 0 0];
prior.p2 = [10 10 10 10];
prior.sampler = @() [unifrnd(prior.p1,prior.p2)]; 
prior.pdf = @(theta) prod(exp(theta)./(1 + exp(theta)).^2);
prior.trans_f = @(theta) [log((theta - prior.p1)./(prior.p2 - theta))];
prior.trans_finv = @(theta) [(prior.p2.*exp(theta) + prior.p1)./(1 + exp(theta))];

tic;
[theta,dist] = bayes_gandk_abc_cvm(y,n,eps,1e7,cov_rw,prior);
finaltime = toc;

save(['results_mcmc_1000_cvm_run' num2str(run) '.mat'],'theta','dist','finaltime','eps');


end
