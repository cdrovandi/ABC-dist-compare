function run_aux_100(run)

% run ABC with summary statistics for dataset of size 100 for dataset number "run" (between 1 and 100)

load('data100.mat')
y = y(:,run);

n = length(y);

load('bsl_input_100.mat') % this contains number of components used in mixture model for forming summaries
numComp = bsl_input_100(run,2);

obj = gmdistribution.fit(y,numComp,'Replicates',1000,'Options',statset('MaxIter',100000,'TolFun',1e-10));

theta_d = [obj.PComponents(1:(numComp-1)) obj.mu' reshape(obj.Sigma,numComp,1)'];

weight_matrix = compute_obs_inf(theta_d,y,obj,numComp);
weight_matrix = inv(weight_matrix);

% tune the ABC tolerance
for i=1:100000
    x = simulate_gk(n,[3 1 2 0.5]);
    grad = compute_grad(theta_d,x,obj,numComp);
    dist(i) = grad*weight_matrix*grad';
end

eps = quantile(dist, 0.01);

% TUNED
cov_rw = [0.00549166661341732,0.0112801170236118,-0.0255611780526848,-0.0163180936020067;0.0112801170236118,0.0926757047779224,0.0263799869794522,-0.165807183816090;-0.0255611780526848,0.0263799869794522,0.292641868551302,-0.0435074048753841;-0.0163180936020067,-0.165807183816090,-0.0435074048753841,0.540229899133093];

% define prior
prior.num_params = 4;
prior.p1 = [0 0 0 0];
prior.p2 = [10 10 10 10];
prior.sampler = @() [unifrnd(prior.p1,prior.p2)]; 
prior.pdf = @(theta) prod(exp(theta)./(1 + exp(theta)).^2);
prior.trans_f = @(theta) [log((theta - prior.p1)./(prior.p2 - theta))];
prior.trans_finv = @(theta) [(prior.p2.*exp(theta) + prior.p1)./(1 + exp(theta))];

tic;
[theta,dist] = bayes_gandk_abc_aux(y,n,eps,1e7,cov_rw,prior,numComp);
finaltime = toc;

save(['results_mcmc_100_aux_run' num2str(run) '.mat'],'theta','dist','finaltime','eps');


end
