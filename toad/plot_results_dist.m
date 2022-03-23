
%% real data

load('results_mcmc_real_cvm.mat')
theta_cvm = theta(1:1000:end,:);

load('results_mcmc_real_wass.mat')
theta_wass = theta(1:1000:end,:);

load('results_mcmc_real_wass_log.mat')
theta_wass_log = theta(1:1000:end,:);

load('results_mcmc_real_mmd.mat')
theta_mmd = theta(1:1000:end,:);

load('results_mcmc_real_mmd_log.mat')
theta_mmd_log = theta(1:1000:end,:);

figure;
subaxis(1,3,1,'SpacingVert',0.005,'MR',0.03,'ML',0.03,'MT',0.01,'PT',0.05,'MB',0.12,'PB',0.04);

subaxis(1);
[f,xi] = ksdensity(theta_cvm(:,1));
plot(xi,f,'b','LineWidth',2);
hold on;
[f,xi] = ksdensity(theta_wass(:,1));
plot(xi,f,'r--','LineWidth',2);
[f,xi] = ksdensity(theta_wass_log(:,1));
plot(xi,f,'m-.','LineWidth',2);
[f,xi] = ksdensity(theta_mmd(:,1));
plot(xi,f,'g.','LineWidth',2);
[f,xi] = ksdensity(theta_mmd_log(:,1));
plot(xi,f,'c:','LineWidth',2);
xlabel('\alpha','FontSize',16);

legend('CvM', 'Wass', 'Wass (log)', 'MMD', 'MMD (log)');



subaxis(2);
[f,xi] = ksdensity(theta_cvm(:,2));
plot(xi,f,'b','LineWidth',2);
hold on;
[f,xi] = ksdensity(theta_wass(:,2));
plot(xi,f,'r--','LineWidth',2);
[f,xi] = ksdensity(theta_wass_log(:,2));
plot(xi,f,'m-.','LineWidth',2);
[f,xi] = ksdensity(theta_mmd(:,2));
plot(xi,f,'g.','LineWidth',2);
[f,xi] = ksdensity(theta_mmd_log(:,2));
plot(xi,f,'c:','LineWidth',2);
xlabel('\gamma','FontSize',16);

legend('CvM', 'Wass', 'Wass (log)', 'MMD', 'MMD (log)');



subaxis(3);
[f,xi] = ksdensity(theta_cvm(:,3));
plot(xi,f,'b','LineWidth',2);
hold on;
[f,xi] = ksdensity(theta_wass(:,3));
plot(xi,f,'r--','LineWidth',2);
[f,xi] = ksdensity(theta_wass_log(:,3));
plot(xi,f,'m-.','LineWidth',2);
[f,xi] = ksdensity(theta_mmd(:,3));
plot(xi,f,'g.','LineWidth',2);
[f,xi] = ksdensity(theta_mmd_log(:,3));
plot(xi,f,'c:','LineWidth',2);
xlabel('p_0','FontSize',16);

legend('CvM', 'Wass', 'Wass (log)', 'MMD', 'MMD (log)');





%% simulated data

load('results_mcmc_simulated_cvm.mat')
theta_cvm = theta(1:1000:end,:);

load('results_mcmc_simulated_wass.mat')
theta_wass = theta(1:1000:end,:);

load('results_mcmc_simulated_wass_log.mat')
theta_wass_log = theta(1:1000:end,:);

figure;
subaxis(1,3,1,'SpacingVert',0.005,'MR',0.03,'ML',0.03,'MT',0.01,'PT',0.05,'MB',0.12,'PB',0.04);

subaxis(1);
[f,xi] = ksdensity(theta_cvm(:,1));
plot(xi,f,'b','LineWidth',2);
hold on;
[f,xi] = ksdensity(theta_wass(:,1));
plot(xi,f,'r--','LineWidth',2);
[f,xi] = ksdensity(theta_wass_log(:,1));
plot(xi,f,'m-.','LineWidth',2);
plot(1.7,0,'kx','MarkerSize',10);
xlabel('\alpha','FontSize',16);

legend('CvM', 'Wass', 'Wass (log)');



subaxis(2);
[f,xi] = ksdensity(theta_cvm(:,2));
plot(xi,f,'b','LineWidth',2);
hold on;
[f,xi] = ksdensity(theta_wass(:,2));
plot(xi,f,'r--','LineWidth',2);
[f,xi] = ksdensity(theta_wass_log(:,2));
plot(xi,f,'m-.','LineWidth',2);
plot(35,0,'kx','MarkerSize',10);
xlabel('\gamma','FontSize',16);

legend('CvM', 'Wass', 'Wass (log)');



subaxis(3);
[f,xi] = ksdensity(theta_cvm(:,3));
plot(xi,f,'b','LineWidth',2);
hold on;
[f,xi] = ksdensity(theta_wass(:,3));
plot(xi,f,'r--','LineWidth',2);
[f,xi] = ksdensity(theta_wass_log(:,3));
plot(xi,f,'m-.','LineWidth',2);
plot(0.6,0,'kx','MarkerSize',10);
xlabel('p_0','FontSize',16);

legend('CvM', 'Wass', 'Wass (log)');




