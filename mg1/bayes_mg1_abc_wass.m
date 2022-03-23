function [theta, dist] = bayes_mg1_abc_wass(y,tol,M,cov_rw,prior,logswitch)
% ABC inference for MG1 example using the Wass distance

T = length(y);
if (logswitch == 1)
    y = log(y);
end

theta = zeros(M,3);
dist = zeros(M,1);

theta_curr = prior.trans_f([1,5,0.2]);
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
    
    x = simulate_mg1(prop,T+1);
    if (logswitch == 1)
        x = log(x);
    end

    if (length(x)<10 || any(isinf(x)) || any(isnan(x)))
        theta(i,:) = theta_curr;
        dist(i) = dist_curr;
        continue;
    end
    
    dist_prop = Wass_stat_M(x,y,1);
    
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
