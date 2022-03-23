function [theta, dist] = bayes_toad_abc_quantiles(Y,simArgs,sumArgs,tol,M,cov_rw,prior,w)

nan_pos = isnan(Y);

ntoads = simArgs.ntoads;
ndays = simArgs.ndays;
model = simArgs.model;
d0 = simArgs.d0;
lag = sumArgs.lag;

y = summStat_quantiles3(Y,lag);

theta = zeros(M,3);
dist = zeros(M,1);

% MH - IL
theta_curr = prior.trans_f([1.7 35 0.6]);
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
    
    X = simulate_toads(prop,ntoads,ndays,model,0);
    X(nan_pos) = NaN;
    x = summStat_quantiles3(X,lag);
    
    if (~(x(1)<4000 && x(13)<4000 && x(25)<4000 && x(37)<4000))
        theta(i,:) = theta_curr;
        dist(i) = dist_curr;
        continue;
    end
    
    dist_prop = sum((w.*(x - y)).^2);
    
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
