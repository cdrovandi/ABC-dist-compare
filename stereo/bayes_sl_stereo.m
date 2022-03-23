function [theta,loglike] = bayes_sl_stereo(y,M,n,cov_rw,prior)

numComp = 3;
obj = gmdistribution.fit(y,numComp,'Replicates',100,'Options',statset('MaxIter',10000,'TolFun',1e-10));
theta_d = [obj.PComponents(1:(numComp-1)) obj.mu' reshape(obj.Sigma,numComp,1)'];
ssy = summStat_aux(y,obj,theta_d,numComp);

theta_curr = [100 2 -0.1];
ns = length(ssy);

theta = zeros(M,3);
ssx = zeros(n,ns);
loglike = zeros(M,1);
count = 0;

parfor k = 1:n
    x = esim_mex(theta_curr,5);
    ssx(k,:) = summStat_aux(x,obj,theta_d,numComp);
end

if (any(any(isinf(ssx))) || any(any(ssx) == 0) == 1 || any(any(isnan(ssx))))
    loglike_ind_curr = -Inf;
else
    the_mean = mean(ssx);
    the_cov = cov(ssx);
    
    [R, flag] = chol(the_cov);
    if (flag ~= 0)
        loglike_ind_curr = -Inf;
    else
        loglike_ind_curr = -0.5*(2*sum(log(diag(R))))-0.5*(the_mean-ssy)/the_cov*(the_mean-ssy)';
    end
    
end

theta_curr = prior.trans_f(theta_curr);
        
for i = 1:M
    i
    theta_prop = mvnrnd(theta_curr,cov_rw);
   
    log_prior_curr = log(prior.pdf(theta_curr));
    log_prior_prop = log(prior.pdf(theta_prop));
    
    prop = prior.trans_finv(theta_prop);
    
    parfor k = 1:n
        x = esim_mex(prop,5);
        ssx(k,:) = summStat_aux(x,obj,theta_d,numComp);
    end
    
    if (any(any(isinf(ssx))) || any(any(ssx) == 0) == 1 || any(any(isnan(ssx))))
        fprintf('!!! dodgy sim !!!\n');
        theta(i,:) = theta_curr;
        loglike(i) = loglike_ind_curr;
        continue;
    end
    
    the_mean = mean(ssx);
    the_cov = cov(ssx);
    
    [R, flag] = chol(the_cov);
    if (flag ~= 0)
        theta(i,:) = theta_curr;
        loglike(i) = loglike_ind_curr;
        continue;
    end
    
    loglike_ind_prop =  -0.5*(2*sum(log(diag(R))))-0.5*(the_mean-ssy)/the_cov*(the_mean-ssy)';
    %if (~isreal(loglike_ind_prop))
    %    fprintf('stop here\n');
    %end
    
    
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
