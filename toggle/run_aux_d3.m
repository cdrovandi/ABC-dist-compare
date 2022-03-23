function run_aux_d3

load('d3.mat')

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

cov_rw = [0.00202124109590204,-0.000173326086793599,-0.000501381309870622,0.00479784409114598,0.00520836937386246,-0.00258357200849668,-0.000624480633974869;-0.000173326086793599,0.00583255270715001,0.00881635647508105,0.00404227617004961,-0.00341227007992737,0.00177109292476160,-0.00588296344485853;-0.000501381309870622,0.00881635647508105,3.12895386445384,0.330199901661860,-0.0498945942801037,0.0994952153225268,-0.125618670722369;0.00479784409114598,0.00404227617004961,0.330199901661860,4.08449908597252,0.469090315384889,0.423016028802620,-1.19078936460602;0.00520836937386246,-0.00341227007992737,-0.0498945942801037,0.469090315384889,2.20151298512035,-0.0928820551069692,0.0627403435191128;-0.00258357200849668,0.00177109292476160,0.0994952153225268,0.423016028802620,-0.0928820551069692,2.39777656092971,0.0557883761208320;-0.000624480633974869,-0.00588296344485853,-0.125618670722369,-1.19078936460602,0.0627403435191128,0.0557883761208320,1.92929364281167];

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

save('results_mcmc_aux_d3.mat','theta','dist','eps');


end
