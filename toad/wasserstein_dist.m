function f = wasserstein_dist(x,y)

n = length(y);

f = mean(abs(quantile(x, (0:(n-1))/(n-1)) - quantile(y, (0:(n-1))/(n-1))));

end