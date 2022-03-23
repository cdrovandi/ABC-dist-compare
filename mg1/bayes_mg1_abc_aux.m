function [theta, dist] = bayes_mg1_abc_aux(y,tol,M,cov_rw,prior,numComp,logswitch)
% ABC inference for MG1 example using summary statistics

T = length(y);

if (logswitch == 1)
    obj = gmdistribution.fit(log(y),numComp,'Replicates',1000,'Options',statset('MaxIter',100000,'TolFun',1e-10));
else
    obj = gmdistribution.fit(y,numComp,'Replicates',1000,'Options',statset('MaxIter',100000,'TolFun',1e-10));
end

theta_d = [obj.PComponents(1:(numComp-1)) obj.mu' reshape(obj.Sigma,numComp,1)'];

if (logswitch == 1)
    weight_matrix = compute_obs_inf(theta_d,log(y),obj,numComp);
else
    weight_matrix = compute_obs_inf(theta_d,y,obj,numComp);
end
weight_matrix = inv(weight_matrix);

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
        grad = compute_grad(theta_d,log(x),obj,numComp);
    else
        grad = compute_grad(theta_d,x,obj,numComp);
    end
    
    dist_prop = grad*weight_matrix*grad';
    
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
