function [theta, loglike] = bayes_mg1_bsl_aux(y,m,M,cov_rw,prior,numComp,logswitch)
% BSL inference for MG1 example using summary statistics

T = length(y);

if (logswitch == 1)
    obj = gmdistribution.fit(log(y),numComp,'Replicates',1000,'Options',statset('MaxIter',100000,'TolFun',1e-10));
else
    obj = gmdistribution.fit(y,numComp,'Replicates',1000,'Options',statset('MaxIter',100000,'TolFun',1e-10));
end


theta_d = [obj.PComponents(1:(numComp-1)) obj.mu' reshape(obj.Sigma,numComp,1)'];
ssy = zeros(1,length(theta_d));

ssx = zeros(m,length(theta_d));
for k = 1:m
    x = simulate_mg1([1,5,0.2],T+1);
    if (logswitch == 1)
        ssx(k,:) = compute_grad(theta_d,log(x),obj,numComp);
    else
        ssx(k,:) = compute_grad(theta_d,x,obj,numComp);
    end
    
end


%Calculating the mean and covariance of the summary statistics
the_mean = mean(ssx);
the_cov = cov(ssx);
L = chol(the_cov);
logdetA = 2*sum(log(diag(L)));

% synthetic likelihood
loglike_curr = -0.5*logdetA - 0.5*(ssy-the_mean)*inv(the_cov)*(ssy-the_mean)';


theta = zeros(M,3);
loglike = zeros(M,1);

theta_curr = prior.trans_f([1,5,0.2]);

for i = 1:M
    
    theta_prop = mvnrnd(theta_curr,cov_rw);
    
    logprior_curr = log(prior.pdf(theta_curr));
    logprior_prop = log(prior.pdf(theta_prop));
    
    prop = prior.trans_finv(theta_prop);
    
    ssx = zeros(m,length(theta_d));
    for k = 1:m
        x = simulate_mg1(prop,T+1);
        if (logswitch == 1)
            ssx(k,:) = compute_grad(theta_d,log(x),obj,numComp);
        else
            ssx(k,:) = compute_grad(theta_d,x,obj,numComp);
        end
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
    loglike_prop = -0.5*logdetA - 0.5*(ssy-the_mean)*inv(the_cov)*(ssy-the_mean)';

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
