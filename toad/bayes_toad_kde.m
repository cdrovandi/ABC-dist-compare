function [theta,loglike] = bayes_toad_kde(Y,simArgs,sumArgs,M,n,cov_rw,prior)

 

ntoads = simArgs.ntoads;
ndays = simArgs.ndays;
model = simArgs.model;
d0 = simArgs.d0;
lag = sumArgs.lag;

y = summStat(Y,lag);

d1y = y{1,2}; d2y = y{2,2}; d3y = y{3,2}; d4y = y{4,2};
z1y = y{1,1}; z2y = y{2,1}; z3y = y{3,1}; z4y = y{4,1};    

theta_curr = [1.7 35 0.6];

theta = zeros(M,3);
loglike = zeros(M,1);
count = 0;

x = cell(4,2,n);
parfor k = 1:n
    X = simulate_toads(theta_curr,ntoads,ndays,model,0);
    x(:,:,k) = summStat(X,lag);
end

z1 = zeros(n,1); z2 = zeros(n,1); z3 = zeros(n,1); z4 = zeros(n,1);
d1 = []; d2 = []; d3 = []; d4 = [];

for k = 1:n
    z1(k) = cell2mat(x(1,1,k)); z2(k) = cell2mat(x(2,1,k)); z3(k) = cell2mat(x(3,1,k)); z4(k) = cell2mat(x(4,1,k));
    d1 = [d1; cell2mat((x(1,2,k)))]; d2 = [d2; cell2mat(x(2,2,k))]; d3 = [d3; cell2mat(x(3,2,k))]; d4 = [d4; cell2mat(x(4,2,k))];
end
    
d1 = d1(1:10:end); d2 = d2(1:10:end); d3 = d3(1:10:end); d4 = d4(1:10:end);
loglike_ind_curr = sum(log(ksdensity(log(d1), log(d1y)))) + sum(log(ksdensity(log(d2), log(d2y)))) + sum(log(ksdensity(log(d3), log(d3y)))) + sum(log(ksdensity(log(d4), log(d4y)))) + ...
    log(ksdensity(z1, z1y)) + log(ksdensity(z2, z2y)) + log(ksdensity(z3, z3y)) + log(ksdensity(z4, z4y));


theta_curr = prior.trans_f(theta_curr);
        
for i = 1:M
    i
    theta_prop = mvnrnd(theta_curr,cov_rw);
   
    log_prior_curr = log(prior.pdf(theta_curr));
    log_prior_prop = log(prior.pdf(theta_prop));
    
    prop = prior.trans_finv(theta_prop);
    
    parfor k = 1:n
        X = simulate_toads(prop,ntoads,ndays,model,0);
        ssx(k,:) = summStat_quantiles3(X,lag);
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
