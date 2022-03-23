
%% real data

load('results_mcmc_wass.mat')
theta_wass = theta(1:1000:end,:);

load('results_mcmc_4stats.mat')
theta_4stats = theta(1:1000:end,:);

load('results_mcmc_aux.mat')
theta_aux = theta(1:1000:end,:);

load('results_mcmc_bsl_aux.mat')
theta_bsl = theta;


figure;
subaxis(1,3,1,'SpacingVert',0.005,'MR',0.05,'ML',0.06,'MT',0.01,'PT',0.05,'MB',0.12,'PB',0.04);

subaxis(1);
[f,xi] = ksdensity(theta_bsl(:,1));
plot(xi,f,'m--','LineWidth',2);
hold on;
[f,xi] = ksdensity(theta_wass(:,1));
plot(xi,f,'r','LineWidth',2);
[f,xi] = ksdensity(theta_4stats(:,1));
plot(xi,f,'b-.','LineWidth',2);
[f,xi] = ksdensity(theta_aux(:,1));
plot(xi,f,'g.','LineWidth',2);
xlabel('\lambda','FontSize',16);

legend('BSL', 'Wass', 'ABC 4stats', 'ABC Summ');



subaxis(2);
[f,xi] = ksdensity(theta_bsl(:,2));
plot(xi,f,'m--','LineWidth',2);
hold on;
[f,xi] = ksdensity(theta_wass(:,2));
plot(xi,f,'r','LineWidth',2);
[f,xi] = ksdensity(theta_4stats(:,2));
plot(xi,f,'b-.','LineWidth',2);
[f,xi] = ksdensity(theta_aux(:,2));
plot(xi,f,'g.','LineWidth',2);
xlabel('\sigma','FontSize',16);

legend('BSL', 'Wass', 'ABC 4stats', 'ABC Summ');




subaxis(3);
[f,xi] = ksdensity(theta_bsl(:,3));
plot(xi,f,'m--','LineWidth',2);
hold on;
[f,xi] = ksdensity(theta_wass(:,3));
plot(xi,f,'r','LineWidth',2);
[f,xi] = ksdensity(theta_4stats(:,3));
plot(xi,f,'b-.','LineWidth',2);
[f,xi] = ksdensity(theta_aux(:,3));
plot(xi,f,'g.','LineWidth',2);
xlabel('\xi','FontSize',16);

legend('BSL', 'Wass', 'ABC 4stats', 'ABC Summ');





%% simulated data

load('results_mcmc_simulated_wass.mat')
theta_wass = theta(1:1000:end,:);

load('results_mcmc_simulated_4stats.mat')
theta_4stats = theta(1:1000:end,:);

load('results_mcmc_simulated_aux.mat')
theta_aux = theta(1:1000:end,:);

load('results_mcmc_simulated_bsl_aux.mat')
theta_bsl = theta(1:10:end,:);

figure;
subaxis(1,3,1,'SpacingVert',0.005,'MR',0.05,'ML',0.06,'MT',0.01,'PT',0.05,'MB',0.12,'PB',0.04);

subaxis(1);
[f,xi] = ksdensity(theta_bsl(:,1));
plot(xi,f,'m--','LineWidth',2);
hold on;
[f,xi] = ksdensity(theta_wass(:,1));
plot(xi,f,'r','LineWidth',2);
[f,xi] = ksdensity(theta_4stats(:,1));
plot(xi,f,'b-.','LineWidth',2);
[f,xi] = ksdensity(theta_aux(:,1));
plot(xi,f,'g.','LineWidth',2);
plot(100,0,'kx','MarkerSize',10)
xlabel('\lambda','FontSize',16);


legend('BSL', 'Wass', 'ABC 4stats', 'ABC Summ');



subaxis(2);
[f,xi] = ksdensity(theta_bsl(:,2));
plot(xi,f,'m--','LineWidth',2);
hold on;
[f,xi] = ksdensity(theta_wass(:,2));
plot(xi,f,'r','LineWidth',2);
[f,xi] = ksdensity(theta_4stats(:,2));
plot(xi,f,'b-.','LineWidth',2);
[f,xi] = ksdensity(theta_aux(:,2));
plot(xi,f,'g.','LineWidth',2);
plot(2,0,'kx','MarkerSize',10)
xlabel('\sigma','FontSize',16);

legend('BSL', 'Wass', 'ABC 4stats', 'ABC Summ');




subaxis(3);
[f,xi] = ksdensity(theta_bsl(:,3));
plot(xi,f,'m--','LineWidth',2);
hold on;
[f,xi] = ksdensity(theta_wass(:,3));
plot(xi,f,'r','LineWidth',2);
[f,xi] = ksdensity(theta_4stats(:,3));
plot(xi,f,'b-.','LineWidth',2);
[f,xi] = ksdensity(theta_aux(:,3));
plot(xi,f,'g.','LineWidth',2);
plot(-0.1,0,'kx','MarkerSize',10)
xlabel('\xi','FontSize',16);

legend('BSL', 'Wass', 'ABC 4stats', 'ABC Summ');



