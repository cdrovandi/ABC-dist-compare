function[x] = rndlas(n, gamma, alpha)
% simulate random draws from the zero-centred stable (aka Levy
% alpha-stable) distribution
% INPUT
% n - the number of draws
% gamma - scale
% alpha - stability parameter, range (0,2]
% OUTPUT
% x - n by 1 vector consists of random draws with the input parameters

if (alpha <= 0 | alpha > 2)
    error('alpha is not defined outside the interval (0,2]');
end

if (alpha == 1)
    x = tan(pi*(rand(n,1)-1/2)); % random draws from standard Cauchy distribution
end

if (alpha == 2)
    x = normrnd(0, sqrt(2)*gamma, [n 1]); % random draws from standard normal distribution
end

U = unifrnd(-pi/2, pi/2, [n 1]);
W = exprnd(1, n, 1);

x = gamma * sin(alpha*U) ./ cos(U).^(1/alpha) .* (cos((1-alpha)*U)./W).^((1-alpha)/alpha);

end