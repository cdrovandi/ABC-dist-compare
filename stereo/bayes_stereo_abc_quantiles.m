function [theta, dist] = bayes_stereo_abc_quantiles(y,n,tol,M,cov_rw,prior,w)

y = y';
ssy = summStat_stereo_112(y)';

theta = zeros(M,3);
dist = zeros(M,1);

% MH - IL
theta_curr = prior.trans_f([100 2 -0.1]);
dist_curr = tol;

for i = 1:M
    
    theta_prop = mvnrnd(theta_curr,cov_rw);
    
    prior_curr = prior.pdf(theta_curr);
    prior_prop = prior.pdf(theta_prop);
    
    
    if (rand > prior_prop/prior_curr) % early rejection
        theta(i,:) = theta_curr;
        dist(i) = dist_curr;
        continue;
    end
    
    prop = prior.trans_finv(theta_prop);
    
    x = esim_mex(prop,5);
    x = x';
    if (length(x)<10 || any(isinf(x)) || any(isnan(x)))
        theta(i,:) = theta_curr;
        dist(i) = dist_curr;
        continue;
    end
    
    ssx = summStat_stereo_112(x)';
    dist_prop = sum(w.*(ssx - ssy).^2);
    
    if (dist_prop <= tol)
        theta_curr = theta_prop;
        dist_curr = dist_prop;
    end
    theta(i,:) = theta_curr;
    dist(i) = dist_curr;
    
end

% back transform
for i=1:M
    theta(i,:) = prior.trans_finv(theta(i,:));
end


end
