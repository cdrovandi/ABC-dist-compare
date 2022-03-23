%% simulated data

load('results_mcmc_simulated_cvm.mat')
theta_cvm = theta(1:1000:end,:);

load('results_mcmc_simulated_wass.mat')
theta_wass = theta(1:1000:end,:);

load('results_mcmc_simulated_mmd.mat')
theta_mmd = theta(1:1000:end,:);

load('results_mcmc_simulated_kde.mat')
theta_kde = theta(1:10:end,:);

figure;
subaxis(1,3,1,'SpacingVert',0.005,'MR',0.05,'ML',0.06,'MT',0.01,'PT',0.05,'MB',0.12,'PB',0.04);

subaxis(1);
[f,xi] = ksdensity(theta_cvm(:,1));
plot(xi,f,'b--','LineWidth',2);
hold on;
[f,xi] = ksdensity(theta_wass(:,1));
plot(xi,f,'r','LineWidth',2);
[f,xi] = ksdensity(theta_mmd(:,1));
plot(xi,f,'g-.','LineWidth',2);
[f,xi] = ksdensity(theta_kde(:,1));
plot(xi,f,'m.','LineWidth',2);
xlabel('\lambda','FontSize',16);
plot(100,0,'kx','MarkerSize',10)
legend('CvM', 'Wass', 'MMD', 'KDE');



subaxis(2);
[f,xi] = ksdensity(theta_cvm(:,2));
plot(xi,f,'b--','LineWidth',2);
hold on;
[f,xi] = ksdensity(theta_wass(:,2));
plot(xi,f,'r','LineWidth',2);
[f,xi] = ksdensity(theta_mmd(:,2));
plot(xi,f,'g-.','LineWidth',2);
[f,xi] = ksdensity(theta_kde(:,2));
plot(xi,f,'m.','LineWidth',2);
xlabel('\sigma','FontSize',16);
plot(2,0,'kx','MarkerSize',10)
legend('CvM', 'Wass', 'MMD', 'KDE');




subaxis(3);
[f,xi] = ksdensity(theta_cvm(:,3));
plot(xi,f,'b--','LineWidth',2);
hold on;
[f,xi] = ksdensity(theta_wass(:,3));
plot(xi,f,'r','LineWidth',2);
[f,xi] = ksdensity(theta_mmd(:,3));
plot(xi,f,'g-.','LineWidth',2);
[f,xi] = ksdensity(theta_kde(:,3));
plot(xi,f,'m.','LineWidth',2);
plot(-0.1,0,'kx','MarkerSize',10)
xlabel('\xi','FontSize',16);

legend('CvM', 'Wass', 'MMD', 'KDE');






%% real data

load('results_mcmc_cvm.mat')
theta_cvm = theta(1:1000:end,:);

load('results_mcmc_wass.mat')
theta_wass = theta(1:1000:end,:);

load('results_mcmc_mmd.mat')
theta_mmd = theta(1:1000:end,:);

load('results_mcmc_kde.mat')
theta_kde = theta(1:10:end,:);


figure;
subaxis(1,3,1,'SpacingVert',0.005,'MR',0.05,'ML',0.06,'MT',0.01,'PT',0.05,'MB',0.12,'PB',0.04);

subaxis(1);
[f,xi] = ksdensity(theta_cvm(:,1));
plot(xi,f,'b--','LineWidth',2);
hold on;
[f,xi] = ksdensity(theta_wass(:,1));
plot(xi,f,'r','LineWidth',2);
[f,xi] = ksdensity(theta_mmd(:,1));
plot(xi,f,'g-.','LineWidth',2);
[f,xi] = ksdensity(theta_kde(:,1));
plot(xi,f,'m.','LineWidth',2);
xlabel('\lambda','FontSize',16);
%plot(100,0,'kx','MarkerSize',10)
legend('CvM', 'Wass', 'MMD', 'KDE');



subaxis(2);
[f,xi] = ksdensity(theta_cvm(:,2));
plot(xi,f,'b--','LineWidth',2);
hold on;
[f,xi] = ksdensity(theta_wass(:,2));
plot(xi,f,'r','LineWidth',2);
[f,xi] = ksdensity(theta_mmd(:,2));
plot(xi,f,'g-.','LineWidth',2);
[f,xi] = ksdensity(theta_kde(:,2));
plot(xi,f,'m.','LineWidth',2);
xlabel('\sigma','FontSize',16);
%plot(2,0,'kx','MarkerSize',10)
legend('CvM', 'Wass', 'MMD', 'KDE');




subaxis(3);
[f,xi] = ksdensity(theta_cvm(:,3));
plot(xi,f,'b--','LineWidth',2);
hold on;
[f,xi] = ksdensity(theta_wass(:,3));
plot(xi,f,'r','LineWidth',2);
[f,xi] = ksdensity(theta_mmd(:,3));
plot(xi,f,'g-.','LineWidth',2);
[f,xi] = ksdensity(theta_kde(:,3));
plot(xi,f,'m.','LineWidth',2);
%plot(-0.1,0,'kx','MarkerSize',10)
xlabel('\xi','FontSize',16);

legend('CvM', 'Wass', 'MMD', 'KDE');



