



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

ssy = summStat_quantiles3(Y,lag);


theta = [1.7000   35.0000    0.6000];



for i=1:100000
    i
    X = simulate_toads(theta,ntoads,ndays,model,0);
    X(nan_pos) = NaN;
    ssx(i,:) = summStat_quantiles3(X,lag);
end


w = 1./std(ssx);

dist = sum((repmat(w,100000,1).*(ssx - repmat(ssy,100000,1))).^2,2);

eps = quantile(dist, 0.005);



