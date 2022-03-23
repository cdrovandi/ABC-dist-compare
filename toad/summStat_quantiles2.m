function s = summStat_quantiles2(X,lag)
% compute the summary statistics (score of Gaussian mixture estimates) for one toads' moves data matrix
% default lag is [1 2 4 8]
% default number of Gaussian mixtures is 4 (for all lags)
%
% INPUT:
% X - toads moves data matrix, dimension is ndays by ntoads
% obj - matrix containing all related parameters for Gaussian mixture model
% OUTPUT:
% ssx - 4 by 1 cell array of the summary statistics, each cell is of dimension 12 by 1

nlag = length(lag);

x = cell(nlag,1);
s = [];  
for k = 1:nlag
    l = lag(k);
    x{k} = obsMat2deltax(X, l);
    s = [s log(diff(quantile(x{k}, 0:0.1:1))) median(x{k})];
end

end