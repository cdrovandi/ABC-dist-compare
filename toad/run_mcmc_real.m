
% code for running methods on real data


%% plot data

load('radio_converted.mat');
lag = [1, 2, 4, 8];
[ndays, ntoads] = size(Y);

y = summStat(Y,lag);

figure;
subaxis(1,4,1,'SpacingVert',0.005,'MR',0.05,'ML',0.06,'MT',0.01,'PT',0.05,'MB',0.12,'PB',0.04);

subaxis(1);
[f,xi] = ksdensity(y{1,2});
plot(xi,f,'k','LineWidth',2);
xlabel('lag 1 day','FontSize',16);


subaxis(2);
[f,xi] = ksdensity(y{2,2});
plot(xi,f,'k','LineWidth',2);
xlabel('lag 2 days','FontSize',16);


subaxis(3);
[f,xi] = ksdensity(y{3,2});
plot(xi,f,'k','LineWidth',2);
xlabel('lag 4 days','FontSize',16);


subaxis(4);
[f,xi] = ksdensity(y{4,2});
plot(xi,f,'k','LineWidth',2);
xlabel('lag 8 days','FontSize',16);


%% abc cvm


load('radio_converted.mat');
lag = [1, 2, 4, 8];
[ndays, ntoads] = size(Y);


simArgs = struct('ntoads',ntoads,'ndays',ndays,'model',1,'d0',NaN);
sumArgs = struct('lag',lag);


% define prior
prior.num_params = 3;
prior.p1 = [1 0 0];
prior.p2 = [2 100 0.9];
prior.sampler = @() [unifrnd(prior.p1,prior.p2)]; 
prior.pdf = @(theta) prod(exp(theta)./(1 + exp(theta)).^2);
prior.trans_f = @(theta) [log((theta - prior.p1)./(prior.p2 - theta))];
prior.trans_finv = @(theta) [(prior.p2.*exp(theta) + prior.p1)./(1 + exp(theta))];

M = 5e7; 

% TUNED
cov_rw = [0.651084329067819,0.0790435248920266,0.0103421261472039;0.0790435248920266,0.0249726712055342,0.00865787544666166;0.0103421261472039,0.00865787544666166,0.0310277507851869];

load('abc_tol_real_cvm.mat')


[theta, dist] = bayes_toad_abc_cvm(Y,simArgs,sumArgs,eps,M,cov_rw,prior,w);

save('results_mcmc_real_cvm.mat','theta','dist');



%% abc wass


load('radio_converted.mat');
lag = [1, 2, 4, 8];
[ndays, ntoads] = size(Y);


simArgs = struct('ntoads',ntoads,'ndays',ndays,'model',1,'d0',NaN);
sumArgs = struct('lag',lag);


% define prior
prior.num_params = 3;
prior.p1 = [1 0 0];
prior.p2 = [2 100 0.9];
prior.sampler = @() [unifrnd(prior.p1,prior.p2)]; 
prior.pdf = @(theta) prod(exp(theta)./(1 + exp(theta)).^2);
prior.trans_f = @(theta) [log((theta - prior.p1)./(prior.p2 - theta))];
prior.trans_finv = @(theta) [(prior.p2.*exp(theta) + prior.p1)./(1 + exp(theta))];

M = 5e7; 

% TUNED
cov_rw = [0.768387580750783,0.123266418052358,0.0508993210096499;0.123266418052358,0.0483976101591064,0.0200497580517349;0.0508993210096499,0.0200497580517349,0.0337163714970162];

load('abc_tol_real_wass.mat')


[theta, dist] = bayes_toad_abc_wass(Y,simArgs,sumArgs,eps,M,cov_rw,prior,w);

save('results_mcmc_real_wass.mat','theta','dist');




%% abc wass log


load('radio_converted.mat');
lag = [1, 2, 4, 8];
[ndays, ntoads] = size(Y);


simArgs = struct('ntoads',ntoads,'ndays',ndays,'model',1,'d0',NaN);
sumArgs = struct('lag',lag);


% define prior
prior.num_params = 3;
prior.p1 = [1 0 0];
prior.p2 = [2 100 0.9];
prior.sampler = @() [unifrnd(prior.p1,prior.p2)]; 
prior.pdf = @(theta) prod(exp(theta)./(1 + exp(theta)).^2);
prior.trans_f = @(theta) [log((theta - prior.p1)./(prior.p2 - theta))];
prior.trans_finv = @(theta) [(prior.p2.*exp(theta) + prior.p1)./(1 + exp(theta))];

M = 5e7; 

% TUNED
cov_rw = [0.640611577650279,0.0718915419904048,0.0129901404053482;0.0718915419904048,0.0272379517085155,0.00953287332842968;0.0129901404053482,0.00953287332842968,0.0256702747269119];

load('abc_tol_real_wass_log.mat')


[theta, dist] = bayes_toad_abc_wass_log(Y,simArgs,sumArgs,eps,M,cov_rw,prior,w);

save('results_mcmc_real_wass_log.mat','theta','dist');




%% abc MMD


load('radio_converted.mat');
lag = [1, 2, 4, 8];
[ndays, ntoads] = size(Y);


simArgs = struct('ntoads',ntoads,'ndays',ndays,'model',1,'d0',NaN);
sumArgs = struct('lag',lag);


% define prior
prior.num_params = 3;
prior.p1 = [1 0 0];
prior.p2 = [2 100 0.9];
prior.sampler = @() [unifrnd(prior.p1,prior.p2)]; 
prior.pdf = @(theta) prod(exp(theta)./(1 + exp(theta)).^2);
prior.trans_f = @(theta) [log((theta - prior.p1)./(prior.p2 - theta))];
prior.trans_finv = @(theta) [(prior.p2.*exp(theta) + prior.p1)./(1 + exp(theta))];

M = 5e7; 

% TUNED
cov_rw = [0.669595072810935,0.0545935422259257,0.00789403953224168;0.0545935422259257,0.0244859754680109,0.00854461026226271;0.00789403953224168,0.00854461026226271,0.0255218379541617];

load('abc_tol_real_mmd.mat')


[theta, dist] = bayes_toad_abc_mmd(Y,simArgs,sumArgs,eps,M,cov_rw,prior,w);

save('results_mcmc_real_mmd.mat','theta','dist');



%% abc MMD log


load('radio_converted.mat');
lag = [1, 2, 4, 8];
[ndays, ntoads] = size(Y);


simArgs = struct('ntoads',ntoads,'ndays',ndays,'model',1,'d0',NaN);
sumArgs = struct('lag',lag);


% define prior
prior.num_params = 3;
prior.p1 = [1 0 0];
prior.p2 = [2 100 0.9];
prior.sampler = @() [unifrnd(prior.p1,prior.p2)]; 
prior.pdf = @(theta) prod(exp(theta)./(1 + exp(theta)).^2);
prior.trans_f = @(theta) [log((theta - prior.p1)./(prior.p2 - theta))];
prior.trans_finv = @(theta) [(prior.p2.*exp(theta) + prior.p1)./(1 + exp(theta))];

M = 5e7; 

% NOT TUNED
cov_rw = [0.669595072810935,0.0545935422259257,0.00789403953224168;0.0545935422259257,0.0244859754680109,0.00854461026226271;0.00789403953224168,0.00854461026226271,0.0255218379541617];

load('abc_tol_real_mmd_log.mat')


[theta, dist] = bayes_toad_abc_mmd_log(Y,simArgs,sumArgs,eps,M,cov_rw,prior,w);

save('results_mcmc_real_mmd_log.mat','theta','dist');





%% abc quantiles


load('radio_converted.mat');
lag = [1, 2, 4, 8];
[ndays, ntoads] = size(Y);

simArgs = struct('ntoads',ntoads,'ndays',ndays,'model',1,'d0',NaN);
sumArgs = struct('lag',lag);


% define prior
prior.num_params = 3;
prior.p1 = [1 0 0];
prior.p2 = [2 100 0.9];
prior.sampler = @() [unifrnd(prior.p1,prior.p2)]; 
prior.pdf = @(theta) prod(exp(theta)./(1 + exp(theta)).^2);
prior.trans_f = @(theta) [log((theta - prior.p1)./(prior.p2 - theta))];
prior.trans_finv = @(theta) [(prior.p2.*exp(theta) + prior.p1)./(1 + exp(theta))];

M = 5e7; 

% TUNED
cov_rw = [0.414886994089183,0.0535507135105633,0.0163040662555874;0.0535507135105633,0.0247430516458557,0.0103422630811919;0.0163040662555874,0.0103422630811919,0.0311585497990659];

load('abc_tol_real_quantiles.mat')

[theta, dist] = bayes_toad_abc_quantiles(Y,simArgs,sumArgs,eps,M,cov_rw,prior,w);

save('results_mcmc_real_quantiles.mat','theta','dist');



%% BSL 

load('radio_converted.mat');
lag = [1, 2, 4, 8];
[ndays, ntoads] = size(Y);

simArgs = struct('ntoads',ntoads,'ndays',ndays,'model',1,'d0',NaN);
sumArgs = struct('lag',lag);

% define prior
prior.num_params = 3;
prior.p1 = [1 0 0];
prior.p2 = [2 100 0.9];
prior.sampler = @() [unifrnd(prior.p1,prior.p2)]; 
prior.pdf = @(theta) prod(exp(theta)./(1 + exp(theta)).^2);
prior.trans_f = @(theta) [log((theta - prior.p1)./(prior.p2 - theta))];
prior.trans_finv = @(theta) [(prior.p2.*exp(theta) + prior.p1)./(1 + exp(theta))];

M = 1e5;
n = 500;

% TUNED
cov_rw = [0.190281397919294,0.0198104584765541,0.00339107366474725;0.0198104584765541,0.0108220319907086,0.00520357252675780;0.00339107366474725,0.00520357252675780,0.0245755361974916];

[theta,loglike] = bayes_sl_vanilla_toad(Y,simArgs,sumArgs,M,n,cov_rw,prior);

save('results_mcmc_real_bsl.mat','theta','loglike');







