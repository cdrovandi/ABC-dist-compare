function run_cvm(run)
% run ABC with CvM distance for dataset number "run" (between 1 and 100)

load('data100.mat')
y = y(:,run);

% tune the ABC tolerance
for i=1:100000
    x = simulate_mg1([1,5,0.2],length(y)+1);
    dist(i) = cvm_stat_M(x,y,2);
end

eps = quantile(dist, 0.01);

% TUNED
cov_rw = [2.41420382140709,-0.0390847773715284,-0.103615090013480;-0.0390847773715284,0.148495475002962,0.0786321711818289;-0.103615090013480,0.0786321711818289,0.188345325564286];

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
[theta, dist] = bayes_mg1_abc_cvm(y,eps,M,cov_rw,prior,logswitch);
finaltime = toc;

save(['results_mcmc_100_cvm_run' num2str(run) '.mat'],'theta','dist','finaltime','eps');


end
