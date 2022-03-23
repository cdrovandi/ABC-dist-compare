function run_wass_log(run)
% run ABC with Wass distance for dataset number "run" (between 1 and 100).  Here the data are log transformed.

load('data100.mat')
y = y(:,run);

% tune the ABC tolerance
for i=1:100000
    x = simulate_mg1([1,5,0.2],length(y)+1);
    x = log(x);
    dist(i) = Wass_stat_M(x,log(y),1);
end

eps = quantile(dist, 0.01);

% TUNED
cov_rw = [1.43617896600781,-0.00245026052549059,-0.00938394208904029;-0.00245026052549059,0.0686744587555909,0.0105395885415880;-0.00938394208904029,0.0105395885415880,0.0880618850945090];


% define prior
prior.num_params = 3;
prior.p1 = [0,min(y),0];
prior.p2 = [min(y),10+min(y),0.5];
prior.sampler = @() [unifrnd(prior.p1,prior.p2)]; 
prior.pdf = @(theta) prod(exp(theta)./(1 + exp(theta)).^2);
prior.trans_f = @(theta) [log((theta - prior.p1)./(prior.p2 - theta))];
prior.trans_finv = @(theta) [(prior.p2.*exp(theta) + prior.p1)./(1 + exp(theta))];

M = 1e7; 
logswitch = 1;

tic;
[theta, dist] = bayes_mg1_abc_wass(y,eps,M,cov_rw,prior,logswitch);
finaltime = toc;

save(['results_mcmc_100_wass_log_run' num2str(run) '.mat'],'theta','dist','finaltime','eps');


end
