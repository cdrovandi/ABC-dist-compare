function [theta,loglike] = bayes_sl_vanilla_toad_aux(Y,simArgs,sumArgs,M,n,cov_rw,prior)

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

obj = {obj1, obj2, obj3, obj4};
theta_d = {theta_d1, theta_d2, theta_d3, theta_d4};


% observed summary 
ssy = summStat_aux(Y,lag,obj,theta_d);


theta_curr = [1.7 35 0.6];
ns = length(ssy);

theta = zeros(M,3);
ssx = zeros(n,ns);
loglike = zeros(M,1);
count = 0;

parfor k = 1:n
    X = simulate_toads(theta_curr,ntoads,ndays,model,0);
    X(nan_pos) = NaN;
    ssx(k,:) = summStat_aux(X,lag,obj,theta_d);
end


the_mean = mean(ssx);
the_cov = cov(ssx);

loglike_ind_curr = -0.5*log(2*pi)-0.5*log(det(the_cov))-0.5*(the_mean-ssy)/the_cov*(the_mean-ssy)';


theta_curr = prior.trans_f(theta_curr);
        
for i = 1:M
    i
    theta_prop = mvnrnd(theta_curr,cov_rw);
   
    log_prior_curr = log(prior.pdf(theta_curr));
    log_prior_prop = log(prior.pdf(theta_prop));
    
    prop = prior.trans_finv(theta_prop);
    
    parfor k = 1:n
        X = simulate_toads(prop,ntoads,ndays,model,0);
        X(nan_pos) = NaN;
        ssx(k,:) = summStat_aux(X,lag,obj,theta_d);
    end
    
    the_mean = mean(ssx);
    the_cov = cov(ssx);
    loglike_ind_prop = -0.5*log(2*pi)-0.5*log(det(the_cov))-0.5*(the_mean-ssy)/the_cov*(the_mean-ssy)';
    
    
    if (exp(loglike_ind_prop - loglike_ind_curr + log_prior_prop - log_prior_curr) > rand)
        fprintf('*** accepted ***\n');
        theta_curr = theta_prop;
        loglike_ind_curr = loglike_ind_prop;
        count = count + 1;
    end
    theta(i,:) = theta_curr;
    loglike(i) = loglike_ind_curr;
    
end

% back transform
for i=1:M
    theta(i,:) = prior.trans_finv(theta(i,:));
end

end
