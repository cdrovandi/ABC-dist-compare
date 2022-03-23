
%% plot of real data

load('data/data_stereo_real.mat');
n = length(y);


figure;


[f,xi] = ksdensity(y);
plot(xi,f,'k','LineWidth',2);
xlabel('inclusion size','FontSize', 16);
ylabel('density','FontSize', 16)


%% plot of simulated data

load('data/data_stereo_synthetic.mat');
n = length(y);


figure;


[f,xi] = ksdensity(y);
plot(xi,f,'k','LineWidth',2);
xlabel('inclusion size','FontSize', 16);
ylabel('density','FontSize', 16)
