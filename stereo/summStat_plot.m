load('data/data_stereo_real.mat', 'y');
ssy = summary_statistic_stereo_sltest(y);
theta = [100 2 -0.1];
n = 10000;

parfor k = 1:n
   k
   x = esim_mex(theta,5);
   ssx(k,:) = summary_statistic_stereo_sltest(x);
end
ssx(find(isinf(ssx(:,3))),:) = [];

xlab = {'no. of inclusions','minmum','mean','maximum'};
figure('Position', [200 150 800 500]);
subaxis('MT',0.03,'MB',0.08,'ML',0.08,'MR',0.05,'PL',0.01,'PR',0.01,'Pt',0.02,'PB',0.03);
for i = 1:4
    subaxis(2,2,i);
    [fx x] = ksdensity(ssx(:,i));
    plot(x,fx,'LineWidth',1.5,'Color','black');
    hold on
    xl = xlim;
    x = linspace(xl(1), xl(2));
    plot(x, normpdf(x, mean(ssx(:,i)), std(ssx(:,i))), 'r--');
    plot(ssy(i),0,'Color',[34 139 34]/255,'Marker','*');
    hold off
    ylabel('density');
    if exist('xlab')
        xlabel(xlab{i});
    else
        xlabel(strcat('ssx_{',num2str(i),'}'));
    end
end



%%%%%%%%%%%%%%%%%%%%%%%%%

tic;
parfor k = 1:n
    k
    x = esim(theta,5);
end
toc;
% 6.53 sec

tic;
parfor k = 1:n
    k
    x = esim_mex(theta,5);
end
toc;
% 1.51 sec