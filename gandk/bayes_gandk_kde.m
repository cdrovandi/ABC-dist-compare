function [theta, loglike] = bayes_gandk_kde(y,n,M,cov_rw,prior)
% approximate inference for g-and-k example using KDE approach

theta = zeros(M,4);
loglike = zeros(M,1);

theta_curr = prior.trans_f([3 1 2 0.5]);

x = simulate_gk(n,[3 1 2 0.5]);
[f,~] = ksdensity(x,y);
loglike_curr =  sum(log(f));

for i = 1:M
    i
    theta_prop = mvnrnd(theta_curr,cov_rw);
    
    
    logprior_curr = log(prior.pdf(theta_curr));
    logprior_prop = log(prior.pdf(theta_prop));
    
    prop = prior.trans_finv(theta_prop);

    x = simulate_gk(n,prop);
    [f,~] = ksdensity(x,y);
    loglike_prop =  sum(log(f));
    
    mh = exp(loglike_prop - loglike_curr + logprior_prop - logprior_curr);
    
    if (mh > rand)
        theta_curr = theta_prop;
        loglike_curr = loglike_prop;
    end
    theta(i,:) = theta_curr;
    loglike(i) = loglike_curr;
    
end


% back transform
for i=1:M
    theta(i,:) = prior.trans_finv(theta(i,:));
end


end
