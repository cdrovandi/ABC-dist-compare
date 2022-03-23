function [theta,loglike] = bayes_sl_toads_warton(ssy,n,M,cov_rw,start,simArgs,sumArgs,gamma)
% Y - toads moves observation matrix, dimension is ndays by ntoads
% lag - time lag (days), vector
% ngm - number of Gaussian mixtures
% M is the total number of steps attempted (iterations)
% n is number of simulated data sets
% cov_rw is the covariance matrix used in the random walk (use multivariate
% random normal for proposals)

ntoads = simArgs.ntoads;
ndays = simArgs.ndays;
model = simArgs.model;
d0 = simArgs.d0;
lag = sumArgs.lag;


theta_curr = start; %Initial guesses for parameters
ns = length(ssy);
theta = zeros(M,3);
loglike = zeros(M,1);

% Simulating n sets of data and taking their summary statistics
ssx = zeros(n,ns);
parfor k = 1:n
    X = simulate_toads3(theta_curr,ntoads,ndays,model,0);
    ssx(k,:) = summStat_quantiles3(X,lag);
end

% Calculating the mean and covariance of the summary statistics
the_mean = mean(ssx)';
the_cov = warton(ssx, gamma);

loglike_ind_curr = -0.5*log(det(the_cov)) - 0.5*(ssy-the_mean)'/the_cov*(ssy-the_mean);

for i = 1:M
    
    fprintf('i = %i\n',i)
    
%     % Proposing a new pair of parameters
    theta_tilde_curr = para_transformation(theta_curr);
    theta_tilde_prop = mvnrnd(theta_tilde_curr,cov_rw);
    theta_prop = para_back_transformation(theta_tilde_prop);
    prob = jacobian_transformation(theta_tilde_prop) / jacobian_transformation(theta_tilde_curr);
%     theta_prop = theta_curr;
%     prob = 1;
            
    % Simulating n sets of data and taking their summary statistics
    ssx = zeros(n,ns);
    parfor k = 1:n
        X = simulate_toads3(theta_prop,ntoads,ndays,model,0)
        ssx(k,:) = summStat_quantiles3(X,lag);
    end
    
    % Calculating the mean and covariance of the summary statistics
    the_mean = mean(ssx)';
    the_cov = warton(ssx, gamma);
	
    loglike_ind_prop = -0.5*log(det(the_cov)) - 0.5*(ssy-the_mean)'/the_cov*(ssy-the_mean);

    % If the proposed parameters have a higher likelihood than previous, then
    % accept this new parameter at random.
    if (prob * exp(loglike_ind_prop - loglike_ind_curr) > rand)
        fprintf('*** accept ***\n');
        theta_curr = theta_prop;
        loglike_ind_curr = loglike_ind_prop;
    end
    
    theta(i,:) = theta_curr;
    loglike(i) = loglike_ind_curr;   
    
end


end

