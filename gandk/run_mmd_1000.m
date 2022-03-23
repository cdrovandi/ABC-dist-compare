function run_mmd_1000(run)

% run ABC with MMD distance for dataset of size 1000 for dataset number "run" (between 1 and 100)

load('data1000.mat')
y = y(:,run);

n = length(y);

% tune the ABC tolerance
for i=1:100000
    x = simulate_gk(n,[3 1 2 0.5]);
    dist(i) = MMD_dist(x,y);
end

eps = quantile(dist, 0.01);

% TUNED
cov_rw = [0.000635178582705430,0.000935845439246350,-0.00497942651337430,-0.00149513182217215;0.000935845439246350,0.0105653937532278,0.00307199290195290,-0.0152996659549042;-0.00497942651337430,0.00307199290195290,0.0668803523515530,0.00344758039810414;-0.00149513182217215,-0.0152996659549042,0.00344758039810414,0.0312609859916660];

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

save(['results_mcmc_1000_mmd_run' num2str(run) '.mat'],'theta','dist','finaltime','eps');


end
