function [E,D,ssx] = decorr_toy(theta_curr,ns,n_cov)
% get a good estimate of the covariance by using a large number of samples

% take a lot of samples (n_cov samples)
[the_mean,the_cov] = mean_cov_toy(ns,theta_curr);
ssx = mvnrnd(the_mean,the_cov,n_cov);
ssx = ssx;

Sigma_hat = cov(ssx); % calculate the covariance

% eigendecomposition
[E,D] = eig(Sigma_hat);
end

