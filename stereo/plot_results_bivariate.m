
% bivariate posterior plots

%% simulated data

load('results_mcmc_simulated_bsl.mat') % CHANGE THIS TO SEE RESULTS FOR A PARTICULAR METHOD
theta = theta(1:10:end,:); % change thinning for BSL

theta_true = [100 2 -0.1]; 

lower = [50 0 -1.4];
upper = [140 7 0.3];

figure;
subaxis('MT',0.06,'MB',0.1,'ML',0.06,'MR',0.02,'PL',0.01,'PR',0.01,'Pt',0.02,'PB',0.02);


subaxis(1,3,1);

[kx,ky] = ksdensity(theta(:,1:2));
Z = reshape(kx,[30,30]);
X = unique(ky(:,1));
Y = unique(ky(:,2));

contour(X,Y,Z,'LineWidth',1.5,'ShowText','Off','LineColor','k');
xlim([lower(1) upper(1)]);
ylim([lower(2) upper(2)]);
hold on;
plot(theta_true(1), theta_true(2), 'rx', 'MarkerSize', 10, 'LineWidth',2)


subaxis(1,3,2);

[kx,ky] = ksdensity(theta(:,[1 3]));
Z = reshape(kx,[30,30]);
X = unique(ky(:,1));
Y = unique(ky(:,2));

contour(X,Y,Z,'LineWidth',1.5,'ShowText','Off','LineColor','k');
xlim([lower(1) upper(1)]);
ylim([lower(3) upper(3)]);
hold on;
plot(theta_true(1), theta_true(3), 'rx', 'MarkerSize', 10, 'LineWidth',2)


subaxis(1,3,3);

[kx,ky] = ksdensity(theta(:,[2 3]));
Z = reshape(kx,[30,30]);
X = unique(ky(:,1));
Y = unique(ky(:,2));

contour(X,Y,Z,'LineWidth',1.5,'ShowText','Off','LineColor','k');
xlim([lower(2) upper(2)]);
ylim([lower(3) upper(3)]);
hold on;
plot(theta_true(2), theta_true(3), 'rx', 'MarkerSize', 10, 'LineWidth',2)



%% real data

load('results_mcmc_bsl_aux.mat') % CHANGE THIS TO SEE RESULTS FOR A PARTICULAR METHOD
theta = theta(1:10:end,:); % change thinning for BSL

theta_true = [1.7 35 0.6]; 

lower = [50 0.5 -1.4];
upper = [140 6 0.3];

figure;
subaxis('MT',0.06,'MB',0.1,'ML',0.06,'MR',0.02,'PL',0.01,'PR',0.01,'Pt',0.02,'PB',0.02);


subaxis(1,3,1);

[kx,ky] = ksdensity(theta(:,1:2));
Z = reshape(kx,[30,30]);
X = unique(ky(:,1));
Y = unique(ky(:,2));

contour(X,Y,Z,'LineWidth',1.5,'ShowText','Off','LineColor','k');
xlim([lower(1) upper(1)]);
ylim([lower(2) upper(2)]);


subaxis(1,3,2);

[kx,ky] = ksdensity(theta(:,[1 3]));
Z = reshape(kx,[30,30]);
X = unique(ky(:,1));
Y = unique(ky(:,2));

contour(X,Y,Z,'LineWidth',1.5,'ShowText','Off','LineColor','k');
xlim([lower(1) upper(1)]);
ylim([lower(3) upper(3)]);



subaxis(1,3,3);

[kx,ky] = ksdensity(theta(:,[2 3]));
Z = reshape(kx,[30,30]);
X = unique(ky(:,1));
Y = unique(ky(:,2));

contour(X,Y,Z,'LineWidth',1.5,'ShowText','Off','LineColor','k');
xlim([lower(2) upper(2)]);
ylim([lower(3) upper(3)]);



