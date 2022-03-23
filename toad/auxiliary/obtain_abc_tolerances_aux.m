



load('data_toads_model1.mat') % uncomment for simulated data
%load('radio_converted.mat'); % uncomment for real data
nan_pos = isnan(Y);

lag = [1, 2, 4, 8];

simArgs = struct('ntoads',ntoads,'ndays',ndays,'model',1,'d0',NaN);
sumArgs = struct('lag',lag);


ntoads = simArgs.ntoads;
ndays = simArgs.ndays;
model = simArgs.model;
d0 = simArgs.d0;
lag = sumArgs.lag;


y = summStat(Y,lag);


numComp = 3;
%obj1 = gmdistribution.fit(log(y{1,2} - 10),numComp,'Replicates',100,'Options',statset('MaxIter',10000,'TolFun',1e-10));
%obj2 = gmdistribution.fit(log(y{2,2} - 10),numComp,'Replicates',100,'Options',statset('MaxIter',10000,'TolFun',1e-10));
%obj3 = gmdistribution.fit(log(y{3,2} - 10),numComp,'Replicates',100,'Options',statset('MaxIter',10000,'TolFun',1e-10));
%obj4 = gmdistribution.fit(log(y{4,2} - 10),numComp,'Replicates',100,'Options',statset('MaxIter',10000,'TolFun',1e-10));

obj1 = gmdistribution.fit(log(y{1,2}),numComp,'Replicates',100,'Options',statset('MaxIter',10000,'TolFun',1e-10));
obj2 = gmdistribution.fit(log(y{2,2}),numComp,'Replicates',100,'Options',statset('MaxIter',10000,'TolFun',1e-10));
obj3 = gmdistribution.fit(log(y{3,2}),numComp,'Replicates',100,'Options',statset('MaxIter',10000,'TolFun',1e-10));
obj4 = gmdistribution.fit(log(y{4,2}),numComp,'Replicates',100,'Options',statset('MaxIter',10000,'TolFun',1e-10));


theta_d1 = [obj1.PComponents(1:(numComp-1)) obj1.mu' reshape(obj1.Sigma,numComp,1)'];
theta_d2 = [obj2.PComponents(1:(numComp-1)) obj2.mu' reshape(obj2.Sigma,numComp,1)'];
theta_d3 = [obj3.PComponents(1:(numComp-1)) obj3.mu' reshape(obj3.Sigma,numComp,1)'];
theta_d4 = [obj4.PComponents(1:(numComp-1)) obj4.mu' reshape(obj4.Sigma,numComp,1)'];

obj = {obj1, obj2, obj3, obj4};
theta_d = {theta_d1, theta_d2, theta_d3, theta_d4};


theta = [1.7000   35.0000    0.6000];


%weight_matrix1 = compute_obs_inf(theta_d1,log(y{1,2} - 10),obj1,numComp);
weight_matrix1 = compute_obs_inf(theta_d1,log(y{1,2}),obj1,numComp);
weight_matrix1 = inv(weight_matrix1);

%weight_matrix2 = compute_obs_inf(theta_d2,log(y{2,2} - 10),obj2,numComp);
weight_matrix2 = compute_obs_inf(theta_d2,log(y{2,2}),obj2,numComp);
weight_matrix2 = inv(weight_matrix2);

%weight_matrix3 = compute_obs_inf(theta_d3,log(y{3,2} - 10),obj3,numComp);
weight_matrix3 = compute_obs_inf(theta_d3,log(y{3,2}),obj3,numComp);
weight_matrix3 = inv(weight_matrix3);

%weight_matrix4 = compute_obs_inf(theta_d4,log(y{4,2} - 10),obj4,numComp);
weight_matrix4 = compute_obs_inf(theta_d4,log(y{4,2}),obj4,numComp);
weight_matrix4 = inv(weight_matrix4);

for i=1:100000
    i
    X = simulate_toads(theta,ntoads,ndays,model,0);
    X(nan_pos) = NaN;
    x = summStat(X,lag);
    %grad1 = compute_grad(theta_d1,log(x{1,2} - 10),obj1,numComp);
    %grad2 = compute_grad(theta_d2,log(x{2,2} - 10),obj2,numComp);
    %grad3 = compute_grad(theta_d3,log(x{3,2} - 10),obj3,numComp);
    %grad4 = compute_grad(theta_d4,log(x{4,2} - 10),obj4,numComp);
    grad1 = compute_grad(theta_d1,log(x{1,2}),obj1,numComp);
    grad2 = compute_grad(theta_d2,log(x{2,2}),obj2,numComp);
    grad3 = compute_grad(theta_d3,log(x{3,2}),obj3,numComp);
    grad4 = compute_grad(theta_d4,log(x{4,2}),obj4,numComp);
    dist1(i) = grad1*weight_matrix1*grad1';
    dist2(i) = grad2*weight_matrix2*grad2';
    dist3(i) = grad3*weight_matrix3*grad3';
    dist4(i) = grad4*weight_matrix4*grad4';
    dist5(i) = abs(x{1,1} - y{1,1});
    dist6(i) = abs(x{2,1} - y{2,1});
    dist7(i) = abs(x{3,1} - y{3,1});
    dist8(i) = abs(x{4,1} - y{4,1});
end

w(1) = 1/std(log(dist1));
w(2) = 1/std(log(dist2));
w(3) = 1/std(log(dist3));
w(4) = 1/std(log(dist4));
w(5) = 1/(std(dist5));
w(6) = 1/(std(dist6));
w(7) = 1/(std(dist7));
w(8) = 1/(std(dist8));

dist = w(1)*log(dist1) + w(2)*log(dist2) + w(3)*log(dist3) + w(4)*log(dist4) + w(5)*dist5 + w(6)*dist6 + w(7)*dist7 + w(8)*dist8;
eps = quantile(dist, 0.01);



