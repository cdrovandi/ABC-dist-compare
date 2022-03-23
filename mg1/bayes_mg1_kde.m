function [theta, loglike] = bayes_mg1_kde(y,m,M,cov_rw,prior,logswitch)
% Approximate inference for MG1 example using KDE method

T = length(y);

for k = 1:m
    x{k} = simulate_mg1([1,5,0.2],T+1);
end

xs = [];
for k = 1:m
    xs = [xs; x{k}];
end

if (logswitch == 1)
    [f,~] = ksdensity(log(xs),log(y));
else
    [f,~] = ksdensity(xs,y);
end

loglike_curr =  sum(log(f));


theta = zeros(M,3);
loglike = zeros(M,1);

theta_curr = prior.trans_f([1,5,0.2]);

for i = 1:M
    
    theta_prop = mvnrnd(theta_curr,cov_rw);
    
    logprior_curr = log(prior.pdf(theta_curr));
    logprior_prop = log(prior.pdf(theta_prop));
    
    prop = prior.trans_finv(theta_prop);
    
    for k = 1:m
        x{k} = simulate_mg1(prop,T+1);
    end
    
    xs = [];
    for k = 1:m
        xs = [xs; x{k}];
    end
    
    if (any(isnan(xs)))
        theta(i,:) = theta_curr;
        loglike(i) = loglike_curr;
        continue;
    end
    
    if (logswitch == 1)
        [f,~] = ksdensity(log(xs),log(y));
    else
        [f,~] = ksdensity(xs,y);
    end
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
