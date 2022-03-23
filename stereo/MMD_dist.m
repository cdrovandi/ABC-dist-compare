function f = MMD_dist(x,y)
% computes MMD distance

m = length(x);
n = length(y);

sig = median(pdist(y));

f = sum(sum(rbf_dot(x,x,sig)))/m^2 - 2*sum(sum(rbf_dot(x,y,sig)))/(n*m) + sum(sum(rbf_dot(y,y,sig)))/n^2;

end