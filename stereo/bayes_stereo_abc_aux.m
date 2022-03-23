function [theta, dist] = bayes_stereo_abc_aux(y,n,tol,M,cov_rw,prior,w1,w2)
% ABC using auxiliary summary statistics

numComp = 3;
obj = gmdistribution.fit(y,numComp,'Replicates',100,'Options',statset('MaxIter',10000,'TolFun',1e-10));
theta_d = [obj.PComponents(1:(numComp-1)) obj.mu' reshape(obj.Sigma,numComp,1)'];

weight_matrix = compute_obs_inf(theta_d,y,obj,numComp);
weight_matrix = inv(weight_matrix);

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

    if (length(x)<10 || any(isinf(x)) || any(isnan(x)))
        theta(i,:) = theta_curr;
        dist(i) = dist_curr;
        continue;
    end
    
    grad = compute_grad(theta_d,x,obj,numComp);
    dist_prop = w1*grad*weight_matrix*grad' + w2*abs(length(x) - length(y));
    
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
