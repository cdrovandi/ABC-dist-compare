

% plot true g-and-k density

xgrid = -1:0.01:15;
f = zeros(1,length(xgrid));

for i = 1:length(xgrid)
    i
    f(i) = exp(-log_like_gk([3 1 2 0.5],0.8,xgrid(i)));
    
end

plot(xgrid,f,'k','LineWidth',2);
xlabel('realisation','FontSize',12);
ylabel('density','FontSize',12);




