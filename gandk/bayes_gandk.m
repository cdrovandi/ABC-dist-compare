function [theta, loglike] = bayes_gandk(y,M,cov_rw)
% exact Bayesian inference for g-and-k example

theta = zeros(M,4);
loglike = zeros(M,1);

theta_curr = [3 1 2 0.5];

loglike_curr =  -log_like_gk(theta_curr,0.8,y);

for i = 1:M
    i
    theta_prop = mvnrnd(theta_curr,cov_rw);
    if (any(theta_prop<0) || any(theta_prop>10))
        theta(i,:) = theta_curr;
        loglike(i) = loglike_curr;
        continue;
    end
    
    loglike_prop =  -log_like_gk(theta_prop,0.8,y);
    
    mh = exp(loglike_prop - loglike_curr);
    
    if (mh > rand)
        theta_curr = theta_prop;
        loglike_curr = loglike_prop;
    end
    theta(i,:) = theta_curr;
    loglike(i) = loglike_curr;
    
end

end
