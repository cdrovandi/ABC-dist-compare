function run_aux_d1

load('d1.mat')

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

cov_rw = [0.0617551271603222,0.0152551881114111,0.0527527229643510,-0.00744886384085383,0.00329661110747058,-0.207229839466746,-0.0120104805676102;0.0152551881114111,0.0125737008755484,0.0304228071185144,-0.00171746362805779,0.00119803679616403,-0.0549121671761430,0.0141791865049223;0.0527527229643510,0.0304228071185144,0.0928662616825797,-0.00613303737728323,0.00926491396868062,-0.249910600157066,0.0513617106006734;-0.00744886384085383,-0.00171746362805779,-0.00613303737728323,0.000914932544409958,-0.000129451640605789,0.0252215014876216,0.00433019666788533;0.00329661110747058,0.00119803679616403,0.00926491396868062,-0.000129451640605789,0.0205597364633416,-0.0641393944826657,0.145235678261743;-0.207229839466746,-0.0549121671761430,-0.249910600157066,0.0252215014876216,-0.0641393944826657,4.07132284930051,-0.133642788544326;-0.0120104805676102,0.0141791865049223,0.0513617106006734,0.00433019666788533,0.145235678261743,-0.133642788544326,1.96404106638918];

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

save('results_mcmc_aux_d1.mat','theta','dist','eps');


end
