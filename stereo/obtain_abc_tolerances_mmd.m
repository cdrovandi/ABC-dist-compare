

%load('data/data_stereo_synthetic.mat'); % uncomment for simulated data
load('data/data_stereo_real.mat'); % uncomment for real data

theta = [100,2,-0.1];

for i=1:100000
    i
    x = esim_mex(theta,5);

    dist1(i) = MMD_dist(x,y);
    dist2(i) = abs(length(x) - length(y));

end

w1 = 1/std(dist1(~isnan(dist1)));
w2 = 1/std(dist2);

dist = w1*dist1 + w2*dist2;
eps = quantile(dist, 0.005);



