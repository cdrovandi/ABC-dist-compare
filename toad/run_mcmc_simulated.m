

%% abc cvm


load('data_toads_model1.mat')
lag = [1, 2, 4, 8];

%y = summStat(Y,lag);

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
cov_rw = [0.113943128757737,0.0130190587498409,0.000300444373559938;0.0130190587498409,0.00558100124353318,0.00134006423416988;0.000300444373559938,0.00134006423416988,0.00612369400881889];


load('abc_tol_simulated_cvm.mat')


[theta, dist] = bayes_toad_abc_cvm(Y,simArgs,sumArgs,eps,M,cov_rw,prior,w);

save('results_mcmc_simulated_cvm.mat','theta','dist');



%% abc wass


load('data_toads_model1.mat')
lag = [1, 2, 4, 8];

%y = summStat(Y,lag);

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
cov_rw = [0.212265912870808,0.0307720584122869,0.00899112919078923;0.0307720584122869,0.0129974424556814,0.00428662953833214;0.00899112919078923,0.00428662953833214,0.00748145351728231];


load('abc_tol_simulated_wass.mat')


[theta, dist] = bayes_toad_abc_wass(Y,simArgs,sumArgs,eps,M,cov_rw,prior,w);

save('results_mcmc_simulated_wass.mat','theta','dist');





%% abc wass log


load('data_toads_model1.mat')
lag = [1, 2, 4, 8];

%y = summStat(Y,lag);

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
cov_rw = [0.131858338112440,0.0151810914307206,0.00495867634367605;0.0151810914307206,0.00653736970290452,0.00154442809913876;0.00495867634367605,0.00154442809913876,0.00623590645968874];


load('abc_tol_simulated_wass_log.mat')


[theta, dist] = bayes_toad_abc_wass_log(Y,simArgs,sumArgs,eps,M,cov_rw,prior,w);

save('results_mcmc_simulated_wass_log.mat','theta','dist');







%% abc quantiles


load('data_toads_model1.mat')
lag = [1, 2, 4, 8];

%y = summStat_quantiles3(Y,lag);

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
cov_rw = [0.130241491063229	0.0158187820639640	0.00161021604472211;...
0.0158187820639640	0.00615095902243446	0.00179305564442133;...
0.00161021604472211	0.00179305564442133	0.00660668716241171];

load('abc_tol_simulated_quantiles.mat')


[theta, dist] = bayes_toad_abc_quantiles(Y,simArgs,sumArgs,eps,M,cov_rw,prior,w);

save('results_mcmc_simulated_quantiles.mat','theta','dist');



%% abc auxiliary summaries


load('data_toads_model1.mat')
lag = [1, 2, 4, 8];


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

M = 1e7; 

% TUNED
cov_rw = [0.136853606617024,0.0154368754740582,0.00226930433776421;0.0154368754740582,0.00707118277816869,0.00171483167430105;0.00226930433776421,0.00171483167430105,0.00814328372741746];

load('abc_tol_simulated_aux.mat')


[theta, dist] = bayes_toad_abc_aux(Y,simArgs,sumArgs,eps,M,cov_rw,prior,w);

save('results_mcmc_simulated_aux.mat','theta','dist');


%% BSL 



load('data_toads_model1.mat')
lag = [1, 2, 4, 8];

%y = summStat_quantiles3(Y,lag);

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
cov_rw = [0.0723577127261181,0.00810822745180408,-0.00176930774868591;0.00810822745180408,0.00302637280954942,0.000267860261642377;-0.00176930774868591,0.000267860261642377,0.00409310032764696];

[theta,loglike] = bayes_sl_vanilla_toad(Y,simArgs,sumArgs,M,n,cov_rw,prior);

save('results_mcmc_simulated_bsl.mat','theta','loglike');




%% KDE 



load('data_toads_model1.mat')
lag = [1, 2, 4, 8];

%y = summStat_noret(Y,lag);

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

M = 1e4;
n = 500;

% NOT TUNED
cov_rw = [0.130241491063229,0.0158187820639640,0.00161021604472211;0.0158187820639640,0.00615095902243446,0.00179305564442133;0.00161021604472211,0.00179305564442133,0.00660668716241171];

[theta,loglike] = bayes_toad_kde(Y,simArgs,sumArgs,M,n,cov_rw,prior);













%% BSL  - auxiliary summaries



load('data_toads_model1.mat')
lag = [1, 2, 4, 8];

%y = summStat_quantiles3(Y,lag);

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

M = 1e4;
n = 500;

% NOT TUNED
cov_rw = [0.0920794067744887,0.00684943908897195,0.00192715699495489;0.00684943908897195,0.00305231431629487,0.000409759957320244;0.00192715699495489,0.000409759957320244,0.00398588505648624];

[theta,loglike] = bayes_sl_vanilla_toad_aux(Y,simArgs,sumArgs,M,n,cov_rw,prior);

save('results_mcmc_simulated_bsl.mat','theta','loglike');








