function run_exact(run)

load('data100.mat')
y = y(:,run);

theta = bayes_exact_posterior(y, 1000000);

save(['results_mcmc_100_exact_run' num2str(run) '.mat'],'theta');


end
