



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




theta = [1.7000   35.0000    0.6000];



for i=1:100000
    i
    X = simulate_toads(theta,ntoads,ndays,model,0);
    X(nan_pos) = NaN;
    x = summStat(X,lag);

    dist1(i) = cvm_stat_M(x{1,2},y{1,2},2);
    dist2(i) = cvm_stat_M(x{2,2},y{2,2},2);
    dist3(i) = cvm_stat_M(x{3,2},y{3,2},2);
    dist4(i) = cvm_stat_M(x{4,2},y{4,2},2);
    dist5(i) = abs(x{1,1} - y{1,1});
    dist6(i) = abs(x{2,1} - y{2,1});
    dist7(i) = abs(x{3,1} - y{3,1});
    dist8(i) = abs(x{4,1} - y{4,1});
end

w(1) = 1/std(dist1);
w(2) = 1/std(dist2);
w(3) = 1/std(dist3);
w(4) = 1/std(dist4);
w(5) = 1/(std(dist5));
w(6) = 1/(std(dist6));
w(7) = 1/(std(dist7));
w(8) = 1/(std(dist8));

dist = w(1)*dist1 + w(2)*dist2 + w(3)*dist3 + w(4)*dist4 + w(5)*dist5 + w(6)*dist6 + w(7)*dist7 + w(8)*dist8;
eps = quantile(dist, 0.005);



