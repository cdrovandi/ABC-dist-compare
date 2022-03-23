
%% cvm distance n=100

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

[part_vals, part_s, sims, dist_t, p_acc_t] = smc_abc_rw_cvm(y,n,prior,1000,0,0.5,0.01,0.005);
save('results_cvm.mat','part_vals','part_s');



%% number of events distance n=100 

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

[part_vals, part_s, sims, dist_t, p_acc_t] = smc_abc_rw_number(y,n,prior,1000,0,0.5,0.01,0.005);
save('results_number.mat','part_vals','part_s');


%% cvm distance n=100 - BC

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

[part_vals, part_s, sims, dist_t, p_acc_t] = smc_abc_rw_cvm_bc(y,n,prior,1000,0,0.5,0.01,0.005);
save('results_bc.mat','part_vals','part_s');



%% cvm distance n=100 - BC prev

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

[part_vals, part_s, sims, dist_t, p_acc_t] = smc_abc_rw_cvm_bc_prev(y,n,prior,1000,0,0.5,0.01,0.005);
save('results_bc_prev.mat','part_vals','part_s');




%% cvm distance n=100 - BC sum

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

[part_vals, part_s, sims, dist_t, p_acc_t] = smc_abc_rw_cvm_bc_sum(y,n,prior,1000,0,0.5,0.01,0.005);
save('results_bc_sum.mat','part_vals','part_s');



