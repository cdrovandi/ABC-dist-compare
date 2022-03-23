
% code to obtain the hyperparameters of the distance function involving the 4 summary stats

%load('data/data_stereo_synthetic.mat'); % uncomment for simulated data
load('data/data_stereo_real.mat'); % uncomment for real data


ssy = summary_statistic_stereo_sltest(y,1)';
theta = [100,2,-0.1];

for i=1:100000
    i
    x = esim_mex(theta,5);
    ssx(i,:) = summary_statistic_stereo_sltest(x,1)';

end


w(1) = 1/var(ssx(:,1));
w(2) = 1/var(ssx(:,2));
w(3) = 1/var(ssx(~isinf(ssx(:,3)),3));
w(4) = 1/var(ssx(~isinf(ssx(:,4)),4));

dist = sum(repmat(w,100000,1).*((ssx - repmat(ssy,100000,1)).^2),2);

eps = quantile(dist, 0.005);



