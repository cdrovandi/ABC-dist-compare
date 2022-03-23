function [theta, loglike] = bayes_toggle_bsl_aux_start(y,n,m,M,cov_rw,prior,numComp,start)


%numComp = 3;
obj = gmdistribution.fit(y,numComp,'Replicates',100,'Options',statset('MaxIter',100000,'TolFun',1e-10));

theta_d = [obj.PComponents(1:(numComp-1)) obj.mu' reshape(obj.Sigma,numComp,1)'];
ssy = zeros(1,length(theta_d));

ssx = zeros(m,length(theta_d));
parfor k = 1:m
    x = simulate_tsw(start);
    ssx(k,:) = compute_grad(theta_d,x,obj,numComp);
end


%Calculating the mean and covariance of the summary statistics
the_mean = mean(ssx);
the_cov = cov(ssx);
L = chol(the_cov);
logdetA = 2*sum(log(diag(L)));

% synthetic likelihood
loglike_curr = -0.5*logdetA - 0.5*(ssy-the_mean)/the_cov*(ssy-the_mean)';


theta = zeros(M,7);
loglike = zeros(M,1);

% MH - IL
theta_curr = prior.trans_f(start);

for i = 1:M
    i
    theta_prop = mvnrnd(theta_curr,cov_rw);
    
    logprior_curr = log(prior.pdf(theta_curr));
    logprior_prop = log(prior.pdf(theta_prop));
    
    prop = prior.trans_finv(theta_prop);
    
    ssx = zeros(m,length(theta_d));
    parfor k = 1:m
        x = simulate_tsw(prop);
        ssx(k,:) = compute_grad(theta_d,x,obj,numComp);
    end
    if (any(any(isnan(ssx))))
        theta(i,:) = theta_curr;
        loglike(i) = loglike_curr;
        continue;
    end
        
    
    %Calculating the mean and covariance of the summary statistics
    the_mean = mean(ssx);
    the_cov = cov(ssx);
    [L,p] = chol(the_cov);
    if (p>0)
        theta(i,:) = theta_curr;
        loglike(i) = loglike_curr;
        continue;
    end
        
    logdetA = 2*sum(log(diag(L)));
    
    % synthetic likelihood
    loglike_prop = -0.5*logdetA - 0.5*(ssy-the_mean)/the_cov*(ssy-the_mean)';
    if (loglike_prop > 100)
        fprintf('stop here\n');
    end

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
