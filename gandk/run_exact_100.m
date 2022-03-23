function run_exact_100(run)

% run exact MCMC for dataset of size 100 for dataset number "run" (between 1 and 100)

load('data100.mat')
y = y(:,run);

cov_rw = [0.0125195812935250,0.0166883296089280,-0.0189172539239108,-0.00626130577669591;0.0166883296089280,0.0478472705021770,4.80152464873732e-05,-0.0189211981753242;-0.0189172539239108,4.80152464873732e-05,0.0955088859491847,0.00721764833197183;-0.00626130577669591,-0.0189211981753242,0.00721764833197183,0.0126645114410704];

M=50000;

tic;
[theta, loglike] = bayes_gandk(y,M,cov_rw);
finaltime = toc;

save(['results_mcmc_100_exact_run' num2str(run) '.mat'],'theta','loglike','finaltime');


end