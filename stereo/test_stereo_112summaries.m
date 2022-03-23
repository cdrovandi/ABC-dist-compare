theta_curr = [100 2 -0.1];
n=10000;

parfor k = 1:n
   x = esim_mex(theta_curr,5);
   q = quantile(x,(1:112)./113);
   a = log(diff(q));
   ssx(k,:) = [length(x) a];
end

plotmatrix(ssx(:,1:10))