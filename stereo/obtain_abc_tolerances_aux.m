

%load('data/data_stereo_synthetic.mat'); % uncomment for simulated data
load('data/data_stereo_real.mat'); % uncomment for real data

numComp = 3;
obj = gmdistribution.fit(y,numComp,'Replicates',100,'Options',statset('MaxIter',10000,'TolFun',1e-10));
theta_d = [obj.PComponents(1:(numComp-1)) obj.mu' reshape(obj.Sigma,numComp,1)'];
ssy = summStat_aux(y,obj,theta_d,numComp);

weight_matrix = compute_obs_inf(theta_d,y,obj,numComp);
weight_matrix = inv(weight_matrix);


theta = [100,2,-0.1];

for i=1:100000
    i
    x = esim_mex(theta,5);
    grad = compute_grad(theta_d,x,obj,numComp);
    dist1(i) = grad*weight_matrix*grad';
    
    dist2(i) = abs(length(x) - length(y));
   
end

w1 = 1/iqr(dist1);
w2 = 1/std(dist2);

dist = w1*dist1 + w2*dist2;
eps = quantile(dist, 0.005);



