function [theta, dist] = bayes_toad_abc_wass(Y,simArgs,sumArgs,tol,M,cov_rw,prior,w)
% ABC using Wass distance for toad example.  
nan_pos = isnan(Y);

ntoads = simArgs.ntoads;
ndays = simArgs.ndays;
model = simArgs.model;
d0 = simArgs.d0;
lag = sumArgs.lag;

y = summStat(Y,lag);

theta = zeros(M,3);
dist = zeros(M,1);

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
    x = summStat(X,lag);
    
    if (~(length(x{1,2})>10 && length(x{2,2})>10 && length(x{3,2})>10 && length(x{4,2})>10))
        theta(i,:) = theta_curr;
        dist(i) = dist_curr;
        continue;
    end
    
    dist_prop = sum(w.*[Wass_stat_M(x{1,2},y{1,2},1) Wass_stat_M(x{2,2},y{2,2},1) Wass_stat_M(x{3,2},y{3,2},1) Wass_stat_M(x{4,2},y{4,2},1) abs(x{1,1} - y{1,1}) abs(x{2,1} - y{2,1}) abs(x{3,1} - y{3,1}) abs(x{4,1} - y{4,1})]);
    
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
