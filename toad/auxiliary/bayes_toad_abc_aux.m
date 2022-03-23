function [theta, dist] = bayes_toad_abc_aux(Y,simArgs,sumArgs,tol,M,cov_rw,prior,w)

nan_pos = isnan(Y);

ntoads = simArgs.ntoads;
ndays = simArgs.ndays;
model = simArgs.model;
d0 = simArgs.d0;
lag = sumArgs.lag;

y = summStat(Y,lag);


numComp = 3;
obj1 = gmdistribution.fit(log(y{1,2}),numComp,'Replicates',100,'Options',statset('MaxIter',100000,'TolFun',1e-10));
obj2 = gmdistribution.fit(log(y{2,2}),numComp,'Replicates',100,'Options',statset('MaxIter',100000,'TolFun',1e-10));
obj3 = gmdistribution.fit(log(y{3,2}),numComp,'Replicates',100,'Options',statset('MaxIter',100000,'TolFun',1e-10));
obj4 = gmdistribution.fit(log(y{4,2}),numComp,'Replicates',100,'Options',statset('MaxIter',100000,'TolFun',1e-10));


theta_d1 = [obj1.PComponents(1:(numComp-1)) obj1.mu' reshape(obj1.Sigma,numComp,1)'];
theta_d2 = [obj2.PComponents(1:(numComp-1)) obj2.mu' reshape(obj2.Sigma,numComp,1)'];
theta_d3 = [obj3.PComponents(1:(numComp-1)) obj3.mu' reshape(obj3.Sigma,numComp,1)'];
theta_d4 = [obj4.PComponents(1:(numComp-1)) obj4.mu' reshape(obj4.Sigma,numComp,1)'];

weight_matrix1 = compute_obs_inf(theta_d1,log(y{1,2}),obj1,numComp);
weight_matrix1 = inv(weight_matrix1);

weight_matrix2 = compute_obs_inf(theta_d2,log(y{2,2}),obj2,numComp);
weight_matrix2 = inv(weight_matrix2);

weight_matrix3 = compute_obs_inf(theta_d3,log(y{3,2}),obj3,numComp);
weight_matrix3 = inv(weight_matrix3);

weight_matrix4 = compute_obs_inf(theta_d4,log(y{4,2}),obj4,numComp);
weight_matrix4 = inv(weight_matrix4);


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
    x = summStat(X,lag);
    
    if (~(length(x{1,2})>10 && length(x{2,2})>10 && length(x{3,2})>10 && length(x{4,2})>10))
        theta(i,:) = theta_curr;
        dist(i) = dist_curr;
        continue;
    end
    
    
    grad1 = compute_grad(theta_d1,log(x{1,2}),obj1,numComp);
    grad2 = compute_grad(theta_d2,log(x{2,2}),obj2,numComp);
    grad3 = compute_grad(theta_d3,log(x{3,2}),obj3,numComp);
    grad4 = compute_grad(theta_d4,log(x{4,2}),obj4,numComp);
    
    
    dist_prop = sum(w.*[log(grad1*weight_matrix1*grad1') log(grad2*weight_matrix2*grad2') log(grad3*weight_matrix3*grad3') log(grad4*weight_matrix4*grad4') abs(x{1,1} - y{1,1}) abs(x{2,1} - y{2,1}) abs(x{3,1} - y{3,1}) abs(x{4,1} - y{4,1})]);
    
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
