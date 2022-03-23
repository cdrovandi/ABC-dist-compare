function [theta,loglike] = bayes_stereo_kde(y,M,n,cov_rw,prior)

theta_curr = [100 2 -0.1];

theta = zeros(M,3);

loglike = zeros(M,1);
count = 0;

parfor k = 1:n
    x{k} = esim_mex(theta_curr,5);
end

xs = [];
for k = 1:n
    xs = [xs; x{k}];
end

if (any(isinf(xs)))
    loglike_ind_curr = -Inf;
else
    loglike_ind_curr = sum(log(ksdensity(log(xs),log(y))));
end

theta_curr = prior.trans_f([100 2 -0.1]);
        
for i = 1:M
    i
    theta_prop = mvnrnd(theta_curr,cov_rw);
   
    log_prior_curr = log(prior.pdf(theta_curr));
    log_prior_prop = log(prior.pdf(theta_prop));
    
    prop = prior.trans_finv(theta_prop);
    
    parfor k = 1:n
        x{k} = esim_mex(prop,5);
    end
    
    xs = [];
    for k = 1:n
        xs = [xs; x{k}];
    end
    
    if (any(isinf(xs)))
        fprintf('!!! dodgy sim !!!\n');
        theta(i,:) = theta_curr;
        loglike(i) = loglike_ind_curr;
        continue;
    end
    
    loglike_ind_prop = sum(log(ksdensity(log(xs),log(y))));
    
    if (exp(loglike_ind_prop - loglike_ind_curr + log_prior_prop - log_prior_curr) > rand)
        fprintf('*** accepted ***\n');
        theta_curr = theta_prop;
        loglike_ind_curr = loglike_ind_prop;
        count = count + 1;
    end
    theta(i,:) = theta_curr;
    loglike(i) = loglike_ind_curr;
    
end

% back transform
for i=1:M
    theta(i,:) = prior.trans_finv(theta(i,:));
end

end
