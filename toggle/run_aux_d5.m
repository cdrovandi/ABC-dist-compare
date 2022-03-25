function run_aux_d5

% run abc with summary statistics for dataset 5

load('d5.mat')

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

eps = quantile(dist, 0.01);

%eps = 6.56150332124355;

cov_rw = [0.139282376933933,-0.0821777306075101,0.0279310769396929,-0.0298815139391975,-0.0117572216158099,0.0331462151641929,-0.0564023339921639;-0.0821777306075101,0.0775702957876043,0.00893223642208729,0.0176701245021850,0.000520997368484761,0.0310441377643196,0.0513555688100432;0.0279310769396929,0.00893223642208729,0.0417359894075891,-0.00645114729139956,-0.0134936984746465,0.0536214592192564,-0.0274378746709695;-0.0298815139391975,0.0176701245021850,-0.00645114729139956,0.00660882583532407,0.00214021458959628,-0.00684038112088210,0.0110900871342387;-0.0117572216158099,0.000520997368484761,-0.0134936984746465,0.00214021458959628,0.0836286228264903,-0.180961659098900,0.185751147446312;0.0331462151641929,0.0310441377643196,0.0536214592192564,-0.00684038112088210,-0.180961659098900,1.71721177694899,0.249789388876413;-0.0564023339921639,0.0513555688100432,-0.0274378746709695,0.0110900871342387,0.185751147446312,0.249789388876413,1.25253144556687];

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
[theta,dist] = bayes_toggle_abc_aux(y,n,eps,1e7,cov_rw,prior,numComp,start);
finaltime=toc;

save('results_mcmc_aux_d5.mat','theta','dist','eps');


end
