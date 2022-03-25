function run_wass_d2

% run abc with Wass distance for dataset 2

load('d2.mat')

n = length(y);

% tune the ABC tolerance
for i=1:100000
    x = simulate_tsw(theta_test);
    dist(i) = Wass_stat_M(x,y,1);
end

eps = quantile(dist, 0.01);
%eps = 2.16793518151315;

start = theta_test;

cov_rw = [0.000280785809717704,-1.45438417120755e-05,0.000332682016435856,-7.39245826114693e-05,-0.00362057109957826,0.000198999075965943,-0.000718122360107319;-1.45438417120755e-05,0.00253173208858634,0.00302199526727613,-4.84163996859181e-07,-0.00921382615503106,0.0102755572796518,-0.00217636439039081;0.000332682016435856,0.00302199526727613,0.287206351716664,0.00457202158767660,0.0907893578146322,-0.335074507602009,-0.0679123580463918;-7.39245826114693e-05,-4.84163996859181e-07,0.00457202158767660,0.00117423962038541,0.0165960711344197,5.60391196580252e-05,0.00146928314666982;-0.00362057109957826,-0.00921382615503106,0.0907893578146322,0.0165960711344197,1.77102502954784,-0.586840022655526,0.121523837809114;0.000198999075965943,0.0102755572796518,-0.335074507602009,5.60391196580252e-05,-0.586840022655526,2.04155275707155,0.194552761035650;-0.000718122360107319,-0.00217636439039081,-0.0679123580463918,0.00146928314666982,0.121523837809114,0.194552761035650,0.0695499831985823];

% define prior
prior.num_params = 7;
prior.p1 = [250 0.05 0.05 0 0 0 0];
prior.p2 = [400 0.5 0.35 50 7 50 7];
prior.sampler = @() [unifrnd(prior.p1,prior.p2)]; 
prior.pdf = @(theta) prod(exp(theta)./(1 + exp(theta)).^2);
prior.trans_f = @(theta) [log((theta - prior.p1)./(prior.p2 - theta))];
prior.trans_finv = @(theta) [(prior.p2.*exp(theta) + prior.p1)./(1 + exp(theta))];

[theta,dist] = bayes_toggle_abc_wass(y,n,eps,1e7,cov_rw,prior,start);

save('results_mcmc_wass_d2.mat','theta','dist','eps');


end
