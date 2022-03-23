function [theta, loglike] = bayes_toggle_kde(y,m,M,cov_rw,prior)

theta = zeros(M,7);
loglike = zeros(M,1);

% MH - IL
theta_curr = prior.trans_f([320 0.25 0.15 25 4 15 4]);


x = zeros(m,length(y));
parfor k = 1:m
    x(k,:) = simulate_tsw([320 0.25 0.15 25 4 15 4]);
end

x = x(:);

[f,~] = ksdensity(x,y);
loglike_curr =  sum(log(f));

for i = 1:M
    i
    theta_prop = mvnrnd(theta_curr,cov_rw);
    
    
    logprior_curr = log(prior.pdf(theta_curr));
    logprior_prop = log(prior.pdf(theta_prop));
    
    prop = prior.trans_finv(theta_prop);
    
    x = zeros(m,length(y));
    parfor k = 1:m
        x(k,:) = simulate_tsw(prop);
    end
    
    x = x(:);

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
