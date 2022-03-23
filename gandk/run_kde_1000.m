function run_kde_1000(run)

% run approximate inference using KDE method for dataset of size 1000 for dataset number "run" (between 1 and 100)

load('data1000.mat')
y = y(:,run);

n = 100*length(y);
M=100000;

% TUNED
cov_rw = [0.000324168781523849,0.00118021913416727,-0.000595390778348646,-0.00120801661101190;0.00118021913416727,0.00837993122285485,0.00119368970687378,-0.00868718303162277;-0.000595390778348646,0.00119368970687378,0.00674123722732964,0.000346164498632220;-0.00120801661101190,-0.00868718303162277,0.000346164498632220,0.0130160227750794];

% define prior
prior.num_params = 4;
prior.p1 = [0 0 0 0];
prior.p2 = [10 10 10 10];
prior.sampler = @() [unifrnd(prior.p1,prior.p2)]; 
prior.pdf = @(theta) prod(exp(theta)./(1 + exp(theta)).^2);
prior.trans_f = @(theta) [log((theta - prior.p1)./(prior.p2 - theta))];
prior.trans_finv = @(theta) [(prior.p2.*exp(theta) + prior.p1)./(1 + exp(theta))];

tic;
[theta,dist] = bayes_gandk_kde(y,n,M,cov_rw,prior);
finaltime=toc;

save(['results_mcmc_1000_kde_run' num2str(run) '.mat'],'theta','dist','finaltime');


end
