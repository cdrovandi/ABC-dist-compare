

%% ABC CvM

tic;
load('data/data_stereo_synthetic.mat');
n = length(y);

% define prior
prior.num_params = 3;
prior.p1 = [60 0 -3];
prior.p2 = [130 10 3];
prior.sampler = @() [unifrnd(prior.p1,prior.p2)]; 
prior.pdf = @(theta) prod(exp(theta)./(1 + exp(theta)).^2);
prior.trans_f = @(theta) [log((theta - prior.p1)./(prior.p2 - theta))];
prior.trans_finv = @(theta) [(prior.p2.*exp(theta) + prior.p1)./(1 + exp(theta))];

load('abc_tol_simulated_cvm_count.mat');

% TUNED
cov_rw = [1.11856648570998	-0.328472073882051	0.109612018811495;...
-0.328472073882051	0.181917142323638	-0.0703144924535324;...
0.109612018811495	-0.0703144924535324	0.0293077611420206];

M = 5e7;

[theta, dist] = bayes_stereo_abc_cvm(y,n,eps,M,cov_rw,prior,w1,w2);

finaltime=toc;

save('results_mcmc_simulated_cvm.mat','theta','dist');



%% ABC CvM no count
% 
% load('data/data_stereo_synthetic.mat');
% n = length(y);
% 
% % define prior
% prior.num_params = 3;
% prior.p1 = [60 0 -3];
% prior.p2 = [130 10 3];
% prior.sampler = @() [unifrnd(prior.p1,prior.p2)]; 
% prior.pdf = @(theta) prod(exp(theta)./(1 + exp(theta)).^2);
% prior.trans_f = @(theta) [log((theta - prior.p1)./(prior.p2 - theta))];
% prior.trans_finv = @(theta) [(prior.p2.*exp(theta) + prior.p1)./(1 + exp(theta))];
% 
% load('abc_tol_simulated_cvm.mat');
% 
% % TUNED
% cov_rw = [2.51243548820712,-0.166101825801508,0.0638778753663071;-0.166101825801508,0.248513544647225,-0.0899797153613457;0.0638778753663071,-0.0899797153613457,0.0349710443146523];
% 
% M = 5e7;
% 
% [theta, dist] = bayes_stereo_abc_cvm_nocount(y,n,eps,M,cov_rw,prior);
% 
% save('results_mcmc_simulated_cvm_nocount.mat','theta','dist');



%% ABC Wass

load('data/data_stereo_synthetic.mat');
n = length(y);

% define prior
prior.num_params = 3;
prior.p1 = [60 0 -3];
prior.p2 = [130 10 3];
prior.sampler = @() [unifrnd(prior.p1,prior.p2)]; 
prior.pdf = @(theta) prod(exp(theta)./(1 + exp(theta)).^2);
prior.trans_f = @(theta) [log((theta - prior.p1)./(prior.p2 - theta))];
prior.trans_finv = @(theta) [(prior.p2.*exp(theta) + prior.p1)./(1 + exp(theta))];

load('abc_tol_simulated_wass_count.mat');

% TUNED
cov_rw = [1.12444912709740,-0.231548057838275,0.0548346649573590;-0.231548057838275,0.0814707544796135,-0.0215246283346035;0.0548346649573590,-0.0215246283346035,0.00647337884331666];

M = 5e7;

[theta, dist] = bayes_stereo_abc_wass(y,n,eps,M,cov_rw,prior,w1,w2);

save('results_mcmc_simulated_wass.mat','theta','dist');



%% ABC Aux

load('data/data_stereo_synthetic.mat');
n = length(y);

% define prior
prior.num_params = 3;
prior.p1 = [60 0 -3];
prior.p2 = [130 10 3];
prior.sampler = @() [unifrnd(prior.p1,prior.p2)]; 
prior.pdf = @(theta) prod(exp(theta)./(1 + exp(theta)).^2);
prior.trans_f = @(theta) [log((theta - prior.p1)./(prior.p2 - theta))];
prior.trans_finv = @(theta) [(prior.p2.*exp(theta) + prior.p1)./(1 + exp(theta))];

load('abc_tol_simulated_aux.mat');

% TUNED
cov_rw = [1.34057533474425,-0.244594636827232,0.0533657950016298;-0.244594636827232,0.0819979857607617,-0.0216896972458258;0.0533657950016298,-0.0216896972458258,0.00685901075899453];

M = 5e7;

[theta, dist] = bayes_stereo_abc_aux(y,n,eps,M,cov_rw,prior,w1,w2);

save('results_mcmc_simulated_aux.mat','theta','dist');



%% ABC MMD

load('data/data_stereo_synthetic.mat');
n = length(y);

% define prior
prior.num_params = 3;
prior.p1 = [60 0 -3];
prior.p2 = [130 10 3];
prior.sampler = @() [unifrnd(prior.p1,prior.p2)]; 
prior.pdf = @(theta) prod(exp(theta)./(1 + exp(theta)).^2);
prior.trans_f = @(theta) [log((theta - prior.p1)./(prior.p2 - theta))];
prior.trans_finv = @(theta) [(prior.p2.*exp(theta) + prior.p1)./(1 + exp(theta))];

load('abc_tol_simulated_mmd_count.mat');

% TUNED
cov_rw = [1.03907567768685,-0.219018738295251,0.0553226826545996;-0.219018738295251,0.0847175244543419,-0.0254501840644267;0.0553226826545996,-0.0254501840644267,0.00883112375798710];

M = 5e7;

[theta, dist] = bayes_stereo_abc_mmd(y,n,eps,M,cov_rw,prior,w1,w2);

save('results_mcmc_simulated_mmd.mat','theta','dist');





%% ABC 4 stats

load('data/data_stereo_synthetic.mat');
n = length(y);

% define prior
prior.num_params = 3;
prior.p1 = [60 0 -3];
prior.p2 = [130 10 3];
prior.sampler = @() [unifrnd(prior.p1,prior.p2)]; 
prior.pdf = @(theta) prod(exp(theta)./(1 + exp(theta)).^2);
prior.trans_f = @(theta) [log((theta - prior.p1)./(prior.p2 - theta))];
prior.trans_finv = @(theta) [(prior.p2.*exp(theta) + prior.p1)./(1 + exp(theta))];

load('abc_tol_simulated_4stats.mat')

% TUNED
cov_rw = [1.20410494453867,-0.233359298115739,0.0553658134970698;-0.233359298115739,0.0822742164384014,-0.0219915024105020;0.0553658134970698,-0.0219915024105020,0.00661586196837873];
M = 5e7;

[theta, dist] = bayes_stereo_abc_4stats(y,n,eps,M,cov_rw,prior,w);

save('results_mcmc_simulated_4stats.mat','theta','dist');



%% ABC quantiles

load('data/data_stereo_synthetic.mat');
n = length(y);

% define prior
prior.num_params = 3;
prior.p1 = [60 0 -3];
prior.p2 = [130 10 3];
prior.sampler = @() [unifrnd(prior.p1,prior.p2)]; 
prior.pdf = @(theta) prod(exp(theta)./(1 + exp(theta)).^2);
prior.trans_f = @(theta) [log((theta - prior.p1)./(prior.p2 - theta))];
prior.trans_finv = @(theta) [(prior.p2.*exp(theta) + prior.p1)./(1 + exp(theta))];

load('abc_tol_simulated_quantiles.mat')

% TUNED
cov_rw = [2.77440153451744	-1.11188908651138	0.411821080884677;...
-1.11188908651138	1.09091653819751	-0.549557954105182;...
0.411821080884677	-0.549557954105182	0.303209868429152];

M = 5e7;

[theta, dist] = bayes_stereo_abc_quantiles(y,n,eps,M,cov_rw,prior,w);

save('results_mcmc_simulated_quantiles.mat','theta','dist');







%% BSL  112 summaries

load('data/data_stereo_synthetic.mat');
 
%%%%%%%%%%%%%%%%%%%%%%%%%% BSL %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

n = 2000;
M = 25000;

fn_summStat = @(x) summStat_stereo_112(x);

% TUNED
cov_rw = [3.17605866706251	-0.00910076735371443	0.00251804071331940;...
-0.00910076735371443	0.0713974868068566	-0.0170591055113385;...
0.00251804071331940	-0.0170591055113385	0.00472168357765496];

% define prior
prior.num_params = 3;
prior.p1 = [60 0 -3];
prior.p2 = [130 10 3];
prior.sampler = @() [unifrnd(prior.p1,prior.p2)]; 
prior.pdf = @(theta) prod(exp(theta)./(1 + exp(theta)).^2);
prior.trans_f = @(theta) [log((theta - prior.p1)./(prior.p2 - theta))];
prior.trans_finv = @(theta) [(prior.p2.*exp(theta) + prior.p1)./(1 + exp(theta))];

[theta, loglike] = bayes_sl_vanilla_stereo(y,M,n,cov_rw,fn_summStat,prior);

save('results_mcmc_simulated_bsl.mat','theta','loglike');




%% BSL  auxiliary summaries

load('data/data_stereo_synthetic.mat');
 
%%%%%%%%%%%%%%%%%%%%%%%%%% BSL %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

n = 100;
M = 5e5;


% TUNED
cov_rw = [3.17605866706251	-0.00910076735371443	0.00251804071331940;...
-0.00910076735371443	0.0713974868068566	-0.0170591055113385;...
0.00251804071331940	-0.0170591055113385	0.00472168357765496];

% define prior
prior.num_params = 3;
prior.p1 = [60 0 -3];
prior.p2 = [130 10 3];
prior.sampler = @() [unifrnd(prior.p1,prior.p2)]; 
prior.pdf = @(theta) prod(exp(theta)./(1 + exp(theta)).^2);
prior.trans_f = @(theta) [log((theta - prior.p1)./(prior.p2 - theta))];
prior.trans_finv = @(theta) [(prior.p2.*exp(theta) + prior.p1)./(1 + exp(theta))];

[theta,loglike] = bayes_sl_stereo(y,M,n,cov_rw,prior);

save('results_mcmc_simulated_bsl_aux.mat','theta','loglike');




%% KDE

load('data/data_stereo_synthetic.mat');

n = 100;
M = 500000;


% TUNED
cov_rw = [3.15203075509198,-0.00237265514409312,0.00101872191681372;-0.00237265514409312,0.0721448193932716,-0.0173071034960617;0.00101872191681372,-0.0173071034960617,0.00480920838528775];

% define prior
prior.num_params = 3;
prior.p1 = [60 0 -3];
prior.p2 = [130 10 3];
prior.sampler = @() [unifrnd(prior.p1,prior.p2)]; 
prior.pdf = @(theta) prod(exp(theta)./(1 + exp(theta)).^2);
prior.trans_f = @(theta) [log((theta - prior.p1)./(prior.p2 - theta))];
prior.trans_finv = @(theta) [(prior.p2.*exp(theta) + prior.p1)./(1 + exp(theta))];

[theta, loglike] = bayes_stereo_kde(y,M,n,cov_rw,prior);

save('results_mcmc_simulated_kde.mat','theta','loglike');



%% KDE n = 500

load('data/data_stereo_synthetic.mat');

n = 500;
M = 100000;

fn_summStat = @(x) summStat_stereo_112(x);

% TUNED
cov_rw = [3.15935477350540,-0.0117402605925360,0.00336511366718891;-0.0117402605925360,0.0730006941967922,-0.0174494918630971;0.00336511366718891,-0.0174494918630971,0.00482217582138381];

% define prior
prior.num_params = 3;
prior.p1 = [60 0 -3];
prior.p2 = [130 10 3];
prior.sampler = @() [unifrnd(prior.p1,prior.p2)]; 
prior.pdf = @(theta) prod(exp(theta)./(1 + exp(theta)).^2);
prior.trans_f = @(theta) [log((theta - prior.p1)./(prior.p2 - theta))];
prior.trans_finv = @(theta) [(prior.p2.*exp(theta) + prior.p1)./(1 + exp(theta))];

[theta, loglike] = bayes_stereo_kde(y,M,n,cov_rw,prior);

save('results_mcmc_simulated_kde500.mat','theta','loglike');








