function run_aux_log(run)
% run ABC with summary statistics for dataset number "run" (between 1 and 100).  Here the data is log transformed.

load('data100.mat')
y = y(:,run);

load('bsl_input_log.mat') % this contains number of components used in mixture model for forming summaries
numComp = bsl_input(run,2);

obj = gmdistribution.fit(log(y),numComp,'Replicates',1000,'Options',statset('MaxIter',100000,'TolFun',1e-10));

theta_d = [obj.PComponents(1:(numComp-1)) obj.mu' reshape(obj.Sigma,numComp,1)'];
weight_matrix = compute_obs_inf(theta_d,log(y),obj,numComp);
weight_matrix = inv(weight_matrix);

% tune the ABC tolerance
for i=1:100000
    x = simulate_mg1([1,5,0.2],length(y)+1);
    grad = compute_grad(theta_d,log(x),obj,numComp);
    dist(i) = grad*weight_matrix*grad';
end

eps = quantile(dist, 0.01);


% TUNED
cov_rw = [1.28721942135199,-0.0273198945290921,-0.0126636729729770;-0.0273198945290921,0.126195657184478,0.00828415485098930;-0.0126636729729770,0.00828415485098930,0.113370320126229];

% define prior
prior.num_params = 3;
prior.p1 = [0,min(y),0];
prior.p2 = [min(y),10+min(y),0.5];
prior.sampler = @() [unifrnd(prior.p1,prior.p2)]; 
prior.pdf = @(theta) prod(exp(theta)./(1 + exp(theta)).^2);
prior.trans_f = @(theta) [log((theta - prior.p1)./(prior.p2 - theta))];
prior.trans_finv = @(theta) [(prior.p2.*exp(theta) + prior.p1)./(1 + exp(theta))];

M = 1e7; % number of simulations
logswitch = 1;

tic;
[theta, dist] = bayes_mg1_abc_aux(y,eps,M,cov_rw,prior,numComp,logswitch);
finaltime = toc;

save(['results_mcmc_100_aux_log_run' num2str(run) '.mat'],'theta','dist','eps','finaltime');


end
