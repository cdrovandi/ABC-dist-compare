function run_cvm_100(run)

% run ABC with CvM distance for dataset of size 100 for dataset number "run" (between 1 and 100)

load('data100.mat')
y = y(:,run);

n = length(y);

% tune the ABC tolerance
for i=1:100000
    x = simulate_gk(n,[3 1 2 0.5]);
    dist(i) = cvm_stat_M(x,y,2);
end

eps = quantile(dist, 0.01);

% TUNED
cov_rw = [0.00265691877765014,0.0101559101959692,-0.00647528131938828,-0.0122273653023901;0.0101559101959692,0.0795050283851931,0.0160623795440823,-0.103650674309476;-0.00647528131938828,0.0160623795440823,0.0899669587349147,0.00438811536556568;-0.0122273653023901,-0.103650674309476,0.00438811536556568,0.214216246486858];

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

save(['results_mcmc_100_cvm_run' num2str(run) '.mat'],'theta','dist','finaltime','eps');


end
