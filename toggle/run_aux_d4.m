function run_aux_d4

% run abc with summary statistics for dataset 4

load('d4.mat')

n = length(y);

numComp = 3;

obj = gmdistribution.fit(y,numComp,'Replicates',1000,'Options',statset('MaxIter',100000,'TolFun',1e-10));

theta_d = [obj.PComponents(1:(numComp-1)) obj.mu' reshape(obj.Sigma,numComp,1)'];

weight_matrix = compute_obs_inf(theta_d,y,obj,numComp);
weight_matrix = inv(weight_matrix);

% tune the ABC tolerance
for i=1:100000
    x = simulate_tsw(theta_test);
    grad = compute_grad(theta_d,x,obj,numComp);
    dist(i) = grad*weight_matrix*grad';
end

eps = quantile(dist, 0.01);

%eps = 6.56150332124355;

cov_rw = [0.0343297114832252,-0.00219507004502282,0.00303034630747152,-0.00451897365211353,0.00170773262971147,-0.0101933903986866,0.0591607658699456;-0.00219507004502282,0.00952374703145424,0.0105940536719169,0.000414719121828884,-0.000613077847566162,-0.0201881860170234,-0.0285060957186723;0.00303034630747152,0.0105940536719169,0.0142756917503358,-0.000197869252507411,6.00578462137719e-05,-0.0279231218319003,-0.0273626043773206;-0.00451897365211353,0.000414719121828884,-0.000197869252507411,0.000617575537973225,-0.000130238611124703,0.000798402121135170,-0.00771486431029923;0.00170773262971147,-0.000613077847566162,6.00578462137719e-05,-0.000130238611124703,0.0178835130668865,-0.0720392070520061,0.0892587201354673;-0.0101933903986866,-0.0201881860170234,-0.0279231218319003,0.000798402121135170,-0.0720392070520061,2.24757141666596,0.604622175010458;0.0591607658699456,-0.0285060957186723,-0.0273626043773206,-0.00771486431029923,0.0892587201354673,0.604622175010458,1.45629224888571];

start = theta_test;

% define prior
prior.num_params = 7;
prior.p1 = [250 0.05 0.05 0 0 0 0];
prior.p2 = [400 0.5 0.35 50 7 50 7];
prior.sampler = @() [unifrnd(prior.p1,prior.p2)]; 
prior.pdf = @(theta) prod(exp(theta)./(1 + exp(theta)).^2);
prior.trans_f = @(theta) [log((theta - prior.p1)./(prior.p2 - theta))];
prior.trans_finv = @(theta) [(prior.p2.*exp(theta) + prior.p1)./(1 + exp(theta))];

tic;
[theta,dist] = bayes_toggle_abc_aux(y,n,eps,1e7,cov_rw,prior,numComp,start);
finaltime=toc;

save('results_mcmc_aux_d4.mat','theta','dist','eps');


end
