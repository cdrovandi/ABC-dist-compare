function [theta, dist] = bayes_gandk_abc_cvm(y,n,tol,M,cov_rw,prior)
% ABC inference for g-and-k example using CvM distance

theta = zeros(M,4);
dist = zeros(M,1);

theta_curr = prior.trans_f([3 1 2 0.5]);
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
    
    x = simulate_gk(n,prop);
    dist_prop = cvm_stat_M(x,y,2);
    
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
