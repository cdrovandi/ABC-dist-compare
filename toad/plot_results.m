
% plot of marginal posteriors for summary statistic based approaches (including CvM distance as a reference)

%% real data

load('results_mcmc_real_cvm.mat')
theta_cvm = theta(1:1000:end,:);

load('results_mcmc_real_quantiles.mat')
theta_quantiles = theta(1:1000:end,:);

load('results_mcmc_real_bsl.mat')
theta_bsl = theta(1:10:end,:);

figure;
subaxis(1,3,1,'SpacingVert',0.005,'MR',0.03,'ML',0.03,'MT',0.01,'PT',0.05,'MB',0.12,'PB',0.04);

subaxis(1);
[f,xi] = ksdensity(theta_bsl(:,1));
plot(xi,f,'g--','LineWidth',2);
hold on;
[f,xi] = ksdensity(theta_cvm(:,1));
plot(xi,f,'b','LineWidth',2);
[f,xi] = ksdensity(theta_quantiles(:,1));
plot(xi,f,'r-.','LineWidth',2);
xlabel('\alpha','FontSize',16);

legend('BSL', 'CvM', 'ABC');



subaxis(2);
[f,xi] = ksdensity(theta_bsl(:,2));
plot(xi,f,'g--','LineWidth',2);
hold on;
[f,xi] = ksdensity(theta_cvm(:,2));
plot(xi,f,'b','LineWidth',2);
[f,xi] = ksdensity(theta_quantiles(:,2));
plot(xi,f,'r-.','LineWidth',2);
xlabel('\gamma','FontSize',16);

legend('BSL', 'CvM', 'ABC');



subaxis(3);
[f,xi] = ksdensity(theta_bsl(:,3));
plot(xi,f,'g--','LineWidth',2);
hold on;
[f,xi] = ksdensity(theta_cvm(:,3));
plot(xi,f,'b','LineWidth',2);
[f,xi] = ksdensity(theta_quantiles(:,3));
plot(xi,f,'r-.','LineWidth',2);
xlabel('p_0','FontSize',16);

legend('BSL', 'CvM', 'ABC');




%% simulated data

load('results_mcmc_simulated_cvm.mat')
theta_cvm = theta(1:1000:end,:);

load('results_mcmc_simulated_quantiles.mat')
theta_quantiles = theta(1:1000:end,:);

load('results_mcmc_simulated_bsl.mat')
theta_bsl = theta(1:10:end,:);

figure;
subaxis(1,3,1,'SpacingVert',0.005,'MR',0.03,'ML',0.03,'MT',0.01,'PT',0.05,'MB',0.12,'PB',0.04);

subaxis(1);
[f,xi] = ksdensity(theta_bsl(:,1));
plot(xi,f,'g--','LineWidth',2);
hold on;
[f,xi] = ksdensity(theta_cvm(:,1));
plot(xi,f,'b','LineWidth',2);
[f,xi] = ksdensity(theta_quantiles(:,1));
plot(xi,f,'r-.','LineWidth',2);
plot(1.7,0,'kx','MarkerSize',10);
xlabel('\alpha','FontSize',16);

legend('BSL', 'CvM', 'ABC');



subaxis(2);
[f,xi] = ksdensity(theta_bsl(:,2));
plot(xi,f,'g--','LineWidth',2);
hold on;
[f,xi] = ksdensity(theta_cvm(:,2));
plot(xi,f,'b','LineWidth',2);
[f,xi] = ksdensity(theta_quantiles(:,2));
plot(xi,f,'r-.','LineWidth',2);
plot(35,0,'kx','MarkerSize',10);
xlabel('\gamma','FontSize',16);

legend('BSL', 'CvM', 'ABC');



subaxis(3);
[f,xi] = ksdensity(theta_bsl(:,3));
plot(xi,f,'g--','LineWidth',2);
hold on;
[f,xi] = ksdensity(theta_cvm(:,3));
plot(xi,f,'b','LineWidth',2);
[f,xi] = ksdensity(theta_quantiles(:,3));
plot(xi,f,'r-.','LineWidth',2);
plot(0.6,0,'kx','MarkerSize',10);
xlabel('p_0','FontSize',16);

legend('BSL', 'CvM', 'ABC');

