function [theta,loglike] = bayes_sl_vanilla_stereo(y,M,n,cov_rw,fn_summStat,prior)

ssy = fn_summStat(y);

theta_curr = [100 2 -0.1];
ns = length(ssy);

theta = zeros(M,3);
ssx = zeros(n,ns);
loglike = zeros(M,1);
count = 0;

parfor k = 1:n
    fn_ss = fn_summStat;
    x = esim_mex(theta_curr,5);
    ssx(k,:) = fn_ss(x);
end

if (any(any(isinf(ssx))) || any(any(ssx) == 0) == 1)
    loglike_ind_curr = -Inf;
else
    the_mean = mean(ssx)';
    the_cov = cov(ssx);
    
    loglike_ind_curr = -0.5*log(det(the_cov))-0.5*(the_mean-ssy)'/the_cov*(the_mean-ssy);
end

theta_curr = prior.trans_f([100 2 -0.1]);
        
for i = 1:M
    i
    theta_prop = mvnrnd(theta_curr,cov_rw);
   
    log_prior_curr = log(prior.pdf(theta_curr));
    log_prior_prop = log(prior.pdf(theta_prop));
    
    prop = prior.trans_finv(theta_prop);
    
    parfor k = 1:n
        fn_ss = fn_summStat;
        x = esim_mex(prop,5);
        ssx(k,:) = fn_ss(x);
    end
    
    if (any(any(isinf(ssx))) || any(any(ssx) == 0) == 1)
        fprintf('!!! dodgy sim !!!\n');
        theta(i,:) = theta_curr;
        loglike(i) = loglike_ind_curr;
        continue;
    end
    
    the_mean = mean(ssx)';
    the_cov = cov(ssx);
    loglike_ind_prop = -0.5*log(det(the_cov))-0.5*(the_mean-ssy)'/the_cov*(the_mean-ssy);
    
    
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
