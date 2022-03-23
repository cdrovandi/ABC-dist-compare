function theta0_post = bayes_exact_posterior(y, numiter, eta_prop_std)

if nargin < 2
    numiter = 1000000;
end


if nargin < 3
    eta_prop_std = [0.1610,0.3645,0.1412];
end


theta = [1,4,log(0.2)];
numupd_met = 16;


shift = 0;
range_scale = 0;
rate_scale = 0;

shift_std = sqrt(0.2);
c_range = 1.03;
c_rate = 1.004;


%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%%%%%%%%%%%%%%%%%%%%%%%%%%% queue_met.m %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

% Parameter sampling for the M/G/1 queue model

n = length(y);
x = cumsum(y);

rec_v_every = 1000;
print_every = 100000;

v_mat = zeros(numiter/rec_v_every, n);
par_mat = zeros(numiter, 3);

acc_met = 0;
acc_shift = 0;
acc_range_scale = 0;
acc_rate_scale = 0;

% Initialize latent variables (arrival times) and parameters

par_cur = [min(y), 4, log(0.2)];
v_cur = x - min(y);

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
tic;
for i = 1 : numiter
    
    %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
        
    % Update the arrival times using Gibbs sampling

    v_tmp_g = v_sample(x, y, par_cur, v_cur);

    v_cur = v_tmp_g;

    %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

    % Update the parameters using Metropolis sampling

    [par_tmp_m, acc] = par_sample(x, y, par_cur, v_cur, eta_prop_std, numupd_met);
    acc_met = acc_met + acc;

    par_cur = par_tmp_m;
   
    %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
    
    % Update the parameters and arrival times using a shift update
    
    if shift == 1
        
        [par_tmp_sh, v_tmp_sh, acc] = shift_sample(x, y, par_cur, v_cur, shift_std);
        acc_shift = acc_shift + acc;
        
        v_cur = v_tmp_sh;
        par_cur = par_tmp_sh;
        
    end
    
    %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%  
    
    % Update the parameters and arrival times using a scale update
    
    if range_scale == 1
    
        [par_tmp_range, v_tmp_range, acc] = range_sample(x, y, par_cur, v_cur, c_range);
        acc_range_scale = acc_range_scale + acc;
        
        v_cur = v_tmp_range;
        par_cur = par_tmp_range;
    
    end
    
    %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
    
    % Update the parameters and arrival times using a scale update
    
    if rate_scale == 1
    
        [par_tmp_rate, v_tmp_rate, acc] = rate_sample(x, y, par_cur, v_cur, c_rate);
        acc_rate_scale = acc_rate_scale + acc;
        
        v_cur = v_tmp_rate;
        par_cur = par_tmp_rate;
    
    end

    %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

    if rem(i, rec_v_every) == 0
    
        v_mat(i/rec_v_every, :) = v_cur;
    
    end
    
    par_mat(i, :) = par_cur;
    
    %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
    
    if print_every > 0 && rem(i, print_every) == 0
        
        fprintf('iteration %i \r', i);
        disp(par_mat(i, :))
        
    end
    
    %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
       
end
time = toc;

theta_post = par_mat;
theta0_post = [theta_post(:,1), theta_post(:,1)+theta_post(:,2), exp(theta_post(:,3))];
theta0_post = theta0_post(1:1000:end,:);


end