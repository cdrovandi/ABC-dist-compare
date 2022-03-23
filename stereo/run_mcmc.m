

%% ABC CvM

load('data/data_stereo_real.mat');
n = length(y);

% define prior
prior.num_params = 3;
prior.p1 = [60 0 -3];
prior.p2 = [130 10 3];
prior.sampler = @() [unifrnd(prior.p1,prior.p2)]; 
prior.pdf = @(theta) prod(exp(theta)./(1 + exp(theta)).^2);
prior.trans_f = @(theta) [log((theta - prior.p1)./(prior.p2 - theta))];
prior.trans_finv = @(theta) [(prior.p2.*exp(theta) + prior.p1)./(1 + exp(theta))];

load('abc_tol_cvm_count.mat');

% TUNED
cov_rw = [0.940382982551639	-0.258269206063027	0.0826481898975044;...
-0.258269206063027	0.120499405109840	-0.0431471162064591;...
0.0826481898975044	-0.0431471162064591	0.0170963786734505];

M = 5e7;

[theta, dist] = bayes_stereo_abc_cvm(y,n,eps,M,cov_rw,prior,w1,w2);

save('results_mcmc_cvm.mat','theta','dist');





%% ABC Wass

load('data/data_stereo_real.mat');
n = length(y);

% define prior
prior.num_params = 3;
prior.p1 = [60 0 -3];
prior.p2 = [130 10 3];
prior.sampler = @() [unifrnd(prior.p1,prior.p2)]; 
prior.pdf = @(theta) prod(exp(theta)./(1 + exp(theta)).^2);
prior.trans_f = @(theta) [log((theta - prior.p1)./(prior.p2 - theta))];
prior.trans_finv = @(theta) [(prior.p2.*exp(theta) + prior.p1)./(1 + exp(theta))];

load('abc_tol_wass_count.mat');

% TUNED
cov_rw = [1.05613847875512,-0.215639379984202,0.0468995104406515;-0.215639379984202,0.117005643375048,-0.0363142971148046;0.0468995104406515,-0.0363142971148046,0.0128136310842210];

M = 5e7;

[theta, dist] = bayes_stereo_abc_wass(y,n,eps,M,cov_rw,prior,w1,w2);

save('results_mcmc_wass.mat','theta','dist');




%% ABC Aux

load('data/data_stereo_real.mat');
n = length(y);

% define prior
prior.num_params = 3;
prior.p1 = [60 0 -3];
prior.p2 = [130 10 3];
prior.sampler = @() [unifrnd(prior.p1,prior.p2)]; 
prior.pdf = @(theta) prod(exp(theta)./(1 + exp(theta)).^2);
prior.trans_f = @(theta) [log((theta - prior.p1)./(prior.p2 - theta))];
prior.trans_finv = @(theta) [(prior.p2.*exp(theta) + prior.p1)./(1 + exp(theta))];

load('abc_tol_aux.mat');

% TUNED
cov_rw = [1.59717118975445	-0.392159352672154	0.106999237158324;...
-0.392159352672154	0.158775337262081	-0.0512684779407574;...
0.106999237158324	-0.0512684779407574	0.0189815741237251];



M = 5e7;

[theta, dist] = bayes_stereo_abc_aux(y,n,eps,M,cov_rw,prior,w1,w2);

save('results_mcmc_aux.mat','theta','dist');





%% ABC MMD

load('data/data_stereo_real.mat');
n = length(y);

% define prior
prior.num_params = 3;
prior.p1 = [60 0 -3];
prior.p2 = [130 10 3];
prior.sampler = @() [unifrnd(prior.p1,prior.p2)]; 
prior.pdf = @(theta) prod(exp(theta)./(1 + exp(theta)).^2);
prior.trans_f = @(theta) [log((theta - prior.p1)./(prior.p2 - theta))];
prior.trans_finv = @(theta) [(prior.p2.*exp(theta) + prior.p1)./(1 + exp(theta))];

load('abc_tol_mmd_count.mat');

% TUNED
cov_rw = [1.35388632410371,-0.329624089743830,0.0917939634314041;-0.329624089743830,0.135009251847113,-0.0432824761245862;0.0917939634314041,-0.0432824761245862,0.0156435311228743];

M = 5e7;

[theta, dist] = bayes_stereo_abc_mmd(y,n,eps,M,cov_rw,prior,w1,w2);

save('results_mcmc_mmd.mat','theta','dist');



%% ABC 4 stats

load('data/data_stereo_real.mat');
n = length(y);

% define prior
prior.num_params = 3;
prior.p1 = [60 0 -3];
prior.p2 = [130 10 3];
prior.sampler = @() [unifrnd(prior.p1,prior.p2)]; 
prior.pdf = @(theta) prod(exp(theta)./(1 + exp(theta)).^2);
prior.trans_f = @(theta) [log((theta - prior.p1)./(prior.p2 - theta))];
prior.trans_finv = @(theta) [(prior.p2.*exp(theta) + prior.p1)./(1 + exp(theta))];

load('abc_tol_4stats.mat')

% TUNED
cov_rw = [1.59523937700256,-0.326499777275925,0.0775091215752223;-0.326499777275925,0.120172647095141,-0.0326762193352584;0.0775091215752223,-0.0326762193352584,0.0100968698980811];
M = 5e7;

[theta, dist] = bayes_stereo_abc_4stats(y,n,eps,M,cov_rw,prior,w);

save('results_mcmc_4stats.mat','theta','dist');



%% ABC quantiles

load('data/data_stereo_real.mat');
n = length(y);

% define prior
prior.num_params = 3;
prior.p1 = [60 0 -3];
prior.p2 = [130 10 3];
prior.sampler = @() [unifrnd(prior.p1,prior.p2)]; 
prior.pdf = @(theta) prod(exp(theta)./(1 + exp(theta)).^2);
prior.trans_f = @(theta) [log((theta - prior.p1)./(prior.p2 - theta))];
prior.trans_finv = @(theta) [(prior.p2.*exp(theta) + prior.p1)./(1 + exp(theta))];

load('abc_tol_quantiles.mat')

% TUNED
cov_rw = [2.63388565201659,-0.561211629567490,0.167804473668226;-0.561211629567490,0.282550178333155,-0.0995555414804843;0.167804473668226,-0.0995555414804843,0.0388688118887866];
M = 5e7;

[theta, dist] = bayes_stereo_abc_quantiles(y,n,eps,M,cov_rw,prior,w);

save('results_mcmc_quantiles.mat','theta','dist');







%% BSL  quantile summaries

load('data/data_stereo_real.mat');
 
%%%%%%%%%%%%%%%%%%%%%%%%%% BSL %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

n = 500;
M = 100000;

fn_summStat = @(x) summStat_stereo_112(x);

% TUNED
cov_rw = [0.806912542956570	-0.219767579011272	0.0570096496144597;...
-0.219767579011272	0.0986923930086253	-0.0279738526389412;...
0.0570096496144597	-0.0279738526389412	0.00901713288324701];

% define prior
prior.num_params = 3;
prior.p1 = [60 0 -3];
prior.p2 = [130 10 3];
prior.sampler = @() [unifrnd(prior.p1,prior.p2)]; 
prior.pdf = @(theta) prod(exp(theta)./(1 + exp(theta)).^2);
prior.trans_f = @(theta) [log((theta - prior.p1)./(prior.p2 - theta))];
prior.trans_finv = @(theta) [(prior.p2.*exp(theta) + prior.p1)./(1 + exp(theta))];

[theta, loglike] = bayes_sl_vanilla_stereo(y,M,n,cov_rw,fn_summStat,prior);

save('results_mcmc_bsl.mat','theta','loglike');



%% BSL  auxiliary summaries

load('data/data_stereo_real.mat');
 
%%%%%%%%%%%%%%%%%%%%%%%%%% BSL %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

n = 100;
M = 5e5;


% TUNED
cov_rw = [0.806912542956570	-0.219767579011272	0.0570096496144597;...
-0.219767579011272	0.0986923930086253	-0.0279738526389412;...
0.0570096496144597	-0.0279738526389412	0.00901713288324701];

% define prior
prior.num_params = 3;
prior.p1 = [60 0 -3];
prior.p2 = [130 10 3];
prior.sampler = @() [unifrnd(prior.p1,prior.p2)]; 
prior.pdf = @(theta) prod(exp(theta)./(1 + exp(theta)).^2);
prior.trans_f = @(theta) [log((theta - prior.p1)./(prior.p2 - theta))];
prior.trans_finv = @(theta) [(prior.p2.*exp(theta) + prior.p1)./(1 + exp(theta))];

[theta,loglike] = bayes_sl_stereo(y,M,n,cov_rw,prior);

save('results_mcmc_bsl_aux.mat','theta','loglike');






%% KDE

load('data/data_stereo_real.mat');

n = 100;
M = 500000;

% TUNED
cov_rw = [2.54933372632096,-0.0642754885043082,0.00979786562268245;-0.0642754885043082,0.0742258110480567,-0.0179804227398415;0.00979786562268245,-0.0179804227398415,0.00517293287034084];

% define prior
prior.num_params = 3;
prior.p1 = [60 0 -3];
prior.p2 = [130 10 3];
prior.sampler = @() [unifrnd(prior.p1,prior.p2)]; 
prior.pdf = @(theta) prod(exp(theta)./(1 + exp(theta)).^2);
prior.trans_f = @(theta) [log((theta - prior.p1)./(prior.p2 - theta))];
prior.trans_finv = @(theta) [(prior.p2.*exp(theta) + prior.p1)./(1 + exp(theta))];

[theta, loglike] = bayes_stereo_kde(y,M,n,cov_rw,prior);

save('results_mcmc_kde.mat','theta','loglike');



%% KDE n = 500

load('data/data_stereo_real.mat');

n = 500;
M = 50000;

fn_summStat = @(x) summStat_stereo_112(x);

% TUNED
cov_rw = [2.54933372632096,-0.0642754885043082,0.00979786562268245;-0.0642754885043082,0.0742258110480567,-0.0179804227398415;0.00979786562268245,-0.0179804227398415,0.00517293287034084];

% define prior
prior.num_params = 3;
prior.p1 = [60 0 -3];
prior.p2 = [130 10 3];
prior.sampler = @() [unifrnd(prior.p1,prior.p2)]; 
prior.pdf = @(theta) prod(exp(theta)./(1 + exp(theta)).^2);
prior.trans_f = @(theta) [log((theta - prior.p1)./(prior.p2 - theta))];
prior.trans_finv = @(theta) [(prior.p2.*exp(theta) + prior.p1)./(1 + exp(theta))];

[theta, loglike] = bayes_stereo_kde(y,M,n,cov_rw,prior);

save('results_mcmc_kde500.mat','theta','loglike');

















