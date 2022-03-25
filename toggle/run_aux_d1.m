function run_aux_d1

% run abc with summary statistics for dataset 1

load('d1.mat')

n = length(y);

numComp = 3;

obj = gmdistribution.fit(y,numComp,'Replicates',1000,'Options',statset('MaxIter',100000,'TolFun',1e-10));

theta_d = [obj.PComponents(1:(numComp-1)) obj.mu' reshape(obj.Sigma,numComp,1)'];

weight_matrix = compute_obs_inf(theta_d,y,obj,numComp);
weight_matrix = inv(weight_matrix);

% tune the ABC tolerance
for i=1:100000
    x = simulate_tsw([320 0.25 0.15 25 4 15 4]);
    grad = compute_grad(theta_d,x,obj,numComp);
    dist(i) = grad*weight_matrix*grad';
end

eps = quantile(dist, 0.01);

%eps = 6.56150332124355;

cov_rw = [0.00809311530801790,-0.00137580825647860,0.00113816622992703,-0.00146641398678768,-0.00261105254980647,-0.00337736189924560,0.000909153619371140;-0.00137580825647860,0.00384333880659611,0.00386603153820635,0.000259740904833589,0.00578395972869551,-0.00682122883020302,0.00467223600512793;0.00113816622992703,0.00386603153820635,0.00914354700282131,-0.000205588328731410,-0.000342229340610207,-0.00105397703528097,0.00762955500002915;-0.00146641398678768,0.000259740904833589,-0.000205588328731410,0.000302680635143380,0.00186763519935288,-0.000439296223192188,-1.25553409584612e-05;-0.00261105254980647,0.00578395972869551,-0.000342229340610207,0.00186763519935288,0.777003415256750,-0.787533361563698,0.293478646627102;-0.00337736189924560,-0.00682122883020302,-0.00105397703528097,-0.000439296223192188,-0.787533361563698,1.93345844707201,0.372864002347696;0.000909153619371140,0.00467223600512793,0.00762955500002915,-1.25553409584612e-05,0.293478646627102,0.372864002347696,1.39284275085736];
start = [320 0.25 0.15 25 4 15 4];

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

save('results_mcmc_aux.mat','theta','dist','eps');


end
