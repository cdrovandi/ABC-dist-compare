

load('data/data_stereo_synthetic.mat'); % uncomment for simulated data
%load('data/data_stereo_real.mat'); % uncomment for real data


ssy = summStat_stereo_112(y)';
theta = [100,2,-0.1];

for i=1:100000
    i
    x = esim_mex(theta,5);
    ssx(i,:) = summStat_stereo_112(x)';

end

w = 1./var(ssx);

dist = sum(repmat(w,100000,1).*((ssx - repmat(ssy,100000,1)).^2),2);

eps = quantile(dist, 0.005);



