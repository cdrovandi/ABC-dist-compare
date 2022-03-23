function[x] = obsMat2deltax(X,lag)
% convert the observation matrix to delta x (zero-removed)for given lag
%
% INPUT:
% X - toads moves observation matrix, dimension is ndays by ntoads
% lag - time lag (days)
% OUTPUT;
% x - distances with respect to the time lag

[ndays,~] = size(X);

deltax = zeros(1,0);

for i = 1:(ndays-lag)
    j = i+lag;
    deltax = [deltax, X(j,:)-X(i,:)];
end
deltax = deltax(~isnan(deltax)); % ignore missing values

x = deltax;

if any(x == inf)
    error('Inf detected')
end

end