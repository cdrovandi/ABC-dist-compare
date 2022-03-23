theta = [100 2 -0.1];
y = esim_mex(theta,5);
ssy = summary_statistic_stereo_sltest(y);

save('data/data_stereo_synthetic.mat')