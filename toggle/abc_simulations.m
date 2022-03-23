
% obtain the observed summary statistics
load('data_toggle.mat');
numComp=3;
obj = gmdistribution.fit(y,numComp,'Options',statset('MaxIter',100000,'TolFun',1e-10));

theta_d = [obj.PComponents(1:(numComp-1)) obj.mu' reshape(obj.Sigma,numComp,1)'];
weight_matrix = compute_obs_inf(theta_d,y,obj,numComp);
weight_matrix = inv(weight_matrix);

prior_lhs = [250 0.05 0.05 0 0 0 0];
prior_rhs = [400 0.5 0.35 50 7 50 7];

sims = 100;

theta = zeros(sims,length(prior_lhs));
S = zeros(sims,length(theta_d));
rho = zeros(sims,1);


parfor i = 1:sims
    theta(i,:) = unifrnd(prior_lhs, prior_rhs);
    ys = simulate_toggle(theta(i,:));
    % compute simulated summary statistics (based on the score of mixture model fitted to observed data)
    S(i,:) = compute_grad(theta_d,ys,obj,numComp);
    
    rho(i) = S(i,:)*weight_matrix*S(i,:)';
    
end

