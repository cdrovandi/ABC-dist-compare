function run_kde_100(run)

% run approximate inference using KDE method for dataset of size 100 for dataset number "run" (between 1 and 100)

load('data100.mat')
y = y(:,run);

n = 100*length(y);
M=100000;

% TUNED
cov_rw = [0.00296365024122605,0.00750240531022406,-0.00970196884239848,-0.0151302265885181;0.00750240531022406,0.0619500247217126,0.0201086315363547,-0.144569192201989;-0.00970196884239848,0.0201086315363547,0.110826327869204,-0.0317582567025587;-0.0151302265885181,-0.144569192201989,-0.0317582567025587,0.629554371771796];

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

save(['results_mcmc_100_kde_run' num2str(run) '.mat'],'theta','dist','finaltime');


end
