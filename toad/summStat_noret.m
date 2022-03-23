function s = summStat_noret(X,lag)
% compute the summary statistics (score of Gaussian mixture estimates) for one toads' moves data matrix
% default lag is [1 2 4 8]
%
% INPUT:
% X - toads moves data matrix, dimension is ndays by ntoads
% obj - matrix containing all related parameters for Gaussian mixture model
% OUTPUT:
% ssx - 4 by 1 cell array of the summary statistics, each cell is of dimension 12 by 1

nlag = length(lag);

s = cell(nlag,1);

for k = 1:nlag
    l = lag(k);
    x = obsMat2deltax(X, l);
    x = abs(x);
    
    s{k,1} = x;

end

end