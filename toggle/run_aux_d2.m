function run_aux_d2

% run abc with summary statistics for dataset 2

load('d2.mat')

n = length(y);

numComp = 3;

obj = gmdistribution.fit(y,numComp,'Replicates',1000,'Options',statset('MaxIter',100000,'TolFun',1e-10));

theta_d = [obj.PComponents(1:(numComp-1)) obj.mu' reshape(obj.Sigma,numComp,1)'];

weight_matrix = compute_obs_inf(theta_d,y,obj,numComp);
weight_matrix = inv(weight_matrix);

% tune the ABC tolerance
for i=1:100000
    x = simulate_tsw(theta_test);
    grad = compute_grad(theta_d,x,obj,numComp);
    dist(i) = grad*weight_matrix*grad';
end

eps = quantile(dist, 0.02);

%eps = 6.56150332124355;

cov_rw = [0.000752374110893122,-0.000512117124291799,3.18094059399563e-05,-0.000144532083323280,0.00395558059291661,-0.00714528072836624,-0.000578488856015551;-0.000512117124291799,0.00166215131289127,0.00162019959875897,2.46170327040823e-05,-0.0114519078340538,0.0152610102733769,0.00253000011098857;3.18094059399563e-05,0.00162019959875897,0.0124374517441833,-0.000177437273965877,-0.0155619447401381,-0.0522169042899610,-0.00695114427536210;-0.000144532083323280,2.46170327040823e-05,-0.000177437273965877,6.59369194009629e-05,0.00304130928435715,-0.00241561253200656,-0.000482859911561066;0.00395558059291661,-0.0114519078340538,-0.0155619447401381,0.00304130928435715,0.972016572242257,-0.598944780228390,-0.0774961400267316;-0.00714528072836624,0.0152610102733769,-0.0522169042899610,-0.00241561253200656,-0.598944780228390,2.30875903495040,0.333427844472972;-0.000578488856015551,0.00253000011098857,-0.00695114427536210,-0.000482859911561066,-0.0774961400267316,0.333427844472972,0.0562195441272462];

start = theta_test;

% define prior
prior.num_params = 7;
prior.p1 = [250 0.05 0.05 0 0 0 0];
prior.p2 = [400 0.5 0.35 50 7 50 7];
prior.sampler = @() [unifrnd(prior.p1,prior.p2)]; 
prior.pdf = @(theta) prod(exp(theta)./(1 + exp(theta)).^2);
prior.trans_f = @(theta) [log((theta - prior.p1)./(prior.p2 - theta))];
prior.trans_finv = @(theta) [(prior.p2.*exp(theta) + prior.p1)./(1 + exp(theta))];

tic;
[theta,dist] = bayes_toggle_abc_aux(y,n,eps,1e7,cov_rw,prior,numComp,start,obj);
finaltime=toc;

save('results_mcmc_aux_d2.mat','theta','dist','eps');


end
