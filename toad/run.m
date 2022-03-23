
%% quantiles

load('data_toads_model1.mat')
lag = [1, 2, 4, 8];

y = summStat_quantiles3(Y,lag);

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

[part_vals, part_s, sims, dist_t, p_acc_t] = smc_abc_rw_quantiles(y,simArgs,sumArgs,prior,1000,0,0.5,0.01,0.005);

save('results_quantiles.mat','part_vals','part_s');




%% cvm distance

load('data_toads_model1.mat')
lag = [1, 2, 4, 8];

y = summStat(Y,lag);

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

[part_vals, part_s, sims, dist_t, p_acc_t] = smc_abc_rw_cvm(y,simArgs,sumArgs,prior,1000,0,0.5,0.01,0.005);

save('results_cvm.mat','part_vals','part_s');




%% cvm distance - bc

load('data_toads_model1.mat')
lag = [1, 2, 4, 8];

y = summStat(Y,lag);

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

[part_vals, part_s, sims, dist_t, p_acc_t] = smc_abc_rw_cvm_bc(y,simArgs,sumArgs,prior,1000,0,0.5,0.01,0.005);

save('results_cvm_bc.mat','part_vals','part_s');



%% cvm distance - bc sum

load('data_toads_model1.mat')
lag = [1, 2, 4, 8];

y = summStat(Y,lag);

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

[part_vals, part_s, sims, dist_t, p_acc_t] = smc_abc_rw_cvm_bc_sum(y,simArgs,sumArgs,prior,1000,0,0.5,0.01,0.005);

save('results_cvm_bc_sum.mat','part_vals','part_s');



%%


load('data_toads_model1.mat')
lag = [1, 2, 4, 8];

y = summStat_quantiles3(Y,lag);

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

[part_vals, part_s, sims, dist_t, p_acc_t] = smc_abc_rw_quantiles_bc(y,simArgs,sumArgs,prior,1000,0,0.5,0.01,0.005);

save('results_quantiles_bc.mat','part_vals','part_s');












