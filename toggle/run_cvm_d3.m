function run_cvm_d3

load('d3.mat')

n = length(y);

% tune the ABC tolerance
for i=1:100000
    x = simulate_tsw(theta_test);
    dist(i) = cvm_stat_M(x,y,2);
end

eps = quantile(dist, 0.01);
%eps = 32.6149999999984;

cov_rw = [0.00112341414193265,-7.48766489668540e-05,-0.00356021432190275,0.00138150436118516,-0.00190127161841633,0.00406679250009954,-0.00168667531596468;-7.48766489668540e-05,0.00399342700041106,-0.00141486602779663,-0.00294369056102267,-0.00594714278635444,0.00923558057471246,-0.00825761053729108;-0.00356021432190275,-0.00141486602779663,3.26118954744892,-0.475709225635480,0.0171289605116640,-0.0923702555832446,0.0146298054609560;0.00138150436118516,-0.00294369056102267,-0.475709225635480,0.430958346566726,-0.0379995728063339,-0.133422129882172,-0.0233805647609777;-0.00190127161841633,-0.00594714278635444,0.0171289605116640,-0.0379995728063339,2.01300814835502,-0.118778680024674,0.459777914500926;0.00406679250009954,0.00923558057471246,-0.0923702555832446,-0.133422129882172,-0.118778680024674,2.51855706806632,0.350285929066927;-0.00168667531596468,-0.00825761053729108,0.0146298054609560,-0.0233805647609777,0.459777914500926,0.350285929066927,1.21332688884542];

start = theta_test;

% define prior
prior.num_params = 7;
prior.p1 = [250 0.05 0.05 0 0 0 0];
prior.p2 = [400 0.5 0.35 50 7 50 7];
prior.sampler = @() [unifrnd(prior.p1,prior.p2)]; 
prior.pdf = @(theta) prod(exp(theta)./(1 + exp(theta)).^2);
prior.trans_f = @(theta) [log((theta - prior.p1)./(prior.p2 - theta))];
prior.trans_finv = @(theta) [(prior.p2.*exp(theta) + prior.p1)./(1 + exp(theta))];

[theta,dist] = bayes_toggle_abc_cvm(y,n,eps,1e7,cov_rw,prior,start);

save('results_mcmc_cvm_d3.mat','theta','dist','eps');


end
