
% code to obtain the hyperparameters of the distance function involving the Wass distance

%load('data/data_stereo_synthetic.mat'); % uncomment for simulated data
load('data/data_stereo_real.mat'); % uncomment for real data

theta = [100,2,-0.1];

for i=1:100000
    i
    x = esim_mex(theta,5);

    dist1(i) = Wass_stat_M(x,y,1);
    dist2(i) = abs(length(x) - length(y));

end

w1 = 1/(1.4826*mad(dist1(~isinf(dist1))));
w2 = 1/std(dist2);

dist = w1*dist1 + w2*dist2;
eps = quantile(dist, 0.005);



