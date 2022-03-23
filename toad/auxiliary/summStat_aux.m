function s = summStat_aux(X,lag,obj,theta_d,numComp)
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
    x = obsMat2deltax(X, l);
    x = abs(x);
    
    return_ind = x<10;
    x_noret = x(~return_ind);
    
    %deltax_noret = log(x_noret);
    deltax_noret = log(x_noret - 10);
    
    s = [s sum(return_ind) compute_grad(theta_d{k},deltax_noret',obj{k},numComp)];
end

end