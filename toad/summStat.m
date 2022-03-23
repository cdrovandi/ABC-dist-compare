function s = summStat(X,lag)
% compute the summary statistics (score of Gaussian mixture estimates) for one toads' moves data matrix
% default lag is [1 2 4 8]
%
% INPUT:
% X - toads moves data matrix, dimension is ndays by ntoads
% obj - matrix containing all related parameters for Gaussian mixture model
% OUTPUT:
% ssx - 4 by 1 cell array of the summary statistics, each cell is of dimension 12 by 1

nlag = length(lag);

x = cell(nlag,1);
s = cell(4,2);

for k = 1:nlag
    l = lag(k);
    x = obsMat2deltax(X, l);
    x = abs(x);
    
    return_ind = x<10;
    x_noret = x(~return_ind);
    
    s{k,1} = sum(return_ind);
    s{k,2} = x_noret';

end

end