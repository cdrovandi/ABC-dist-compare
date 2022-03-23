%% plot raw data

load('d3.mat')

figure;
subaxis(1,2,1,'SpacingVert',0.005,'MR',0.05,'ML',0.06,'MT',0,'PT',0.05,'MB',0.09,'PB',0.04,'PL',0.02);

subaxis(1);
[f,xi] = ksdensity(y);
plot(xi,f,'k','LineWidth',2);
xlabel('y','FontSize',16);
ylabel('density','FontSize',16);


subaxis(2);
[f,x] = ecdf(y);
plot(x,f,'k','LineWidth',2);
xlabel('y','FontSize',16);
ylabel('ecdf','FontSize',16);


%% plot results


load('d3.mat')

true = theta_test;
labels = {'\mu', '\sigma', '\gamma', '\alpha_u', '\beta_u', '\alpha_v', '\beta_v'};

load('results_mcmc_cvm_d3.mat')
theta_cvm = theta(1:1000:end,:);

load('results_mcmc_wass_d3.mat')
theta_wass = theta(1:1000:end,:);

load('results_mcmc_aux_d3.mat')
theta_aux = theta(1:1000:end,:);

load('results_mcmc_bsl_d3.mat')
theta_bsl = theta(1:10:end,:);

xlower = [370 0.07 0 30 -1 -10 -1];
xupper = [380 0.09 0.4 42 9 60 8];

figure;
subaxis(3,3,1,'SpacingVert',0.005,'MR',0.05,'ML',0.06,'MT',0,'PT',0.05,'MB',0.05,'PB',0.04);

for i = 1:7
    subaxis(i);
    [f,xi] = ksdensity(theta_cvm(:,i));
    plot(xi,f,'b','LineWidth',2);
    hold on;
    [f,xi] = ksdensity(theta_wass(:,i));
    plot(xi,f,'r--','LineWidth',2);
    [f,xi] = ksdensity(theta_aux(:,i));
    plot(xi,f,'g-.','LineWidth',2);
    [f,xi] = ksdensity(theta_bsl(:,i));
    plot(xi,f,'m.','LineWidth',2);
    plot(true(i),0,'kx','MarkerSize',10)
    xlabel(labels{i},'FontSize',16);
    xlim([xlower(i) xupper(i)]);
    
    legend('CvM', 'Wass', 'ABC', 'BSL');
    
end















