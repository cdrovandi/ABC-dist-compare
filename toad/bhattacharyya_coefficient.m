function BC = bhattacharyya_coefficient(X, Y, k)
% FUNCTION BC = BHATTACHARYYA_COEFFICIENT(X, Y)
%
% INPUTS:
%   X - Samples from distribution P (Size: N x dim(P)).
%   Y - Samples from distribution Q (Size: M x dim(Q), dim(Q) == dim(P)).
%   K - Neighbour from which to calculated distances in approximation.
%
% OUTPUT:
%   BC   - The estimated Bhattacharyya coefficient between the two
%          distributions from which X & Y are sampled. The BC should be in
%          the range [0, 1] and the function will gate the output from the
%          bi-directional arithmetic mean to enforce this.
%
% Mitchell O'Sullivan (2020-03-18)

if(~ismatrix(X) || ~ismatrix(Y))
    error(['BhattacharyyaCoefficient:NonMatrixInputs\nEither X or Y ', ...
           'is not a 2D matrix.'], '');
end

[N, dX] = size(X);
[M, dY] = size(Y);
if (dX ~= dY)
    error(['BhattacharyyaCoefficient:IncompatibleSampleDimensions\nX ', ...
           'has dimensions %d-by-%d, while Y has dimensions %d-by-%d.'] ...
           , N, dX, M, dY);
end
% d = dX; % Not needed unless doing something to automatically choose k per
% Silverman's suggestion.
clear dX dY;

Bka = (hypergeom([1/2, k-1], k, 1)^2)/(pi*(k-1/2));
BC = 0;

rho_ks = squeeze(sort(vecnorm(X - permute(X, [3, 2, 1]), 2, 2), 1));
rho = rho_ks(sub2ind([N, N], sum(rho_ks == 0, 1) + k, 1:N)); clear rho_ks;

nu_ks = squeeze(sort(vecnorm(Y - permute(X, [3, 2, 1]), 2, 2), 1));
nu = nu_ks(sub2ind([M, N], sum(nu_ks == 0, 1) + k, 1:N)); clear nu_ks;

BC = BC + (1/N)*sum(sqrt(((N - 1)*rho)./(M*nu)));

rho_ks = squeeze(sort(vecnorm(Y - permute(Y, [3, 2, 1]), 2, 2), 1));
rho = rho_ks(sub2ind([M, M], sum(rho_ks == 0, 1) + k, 1:M)); clear rho_ks;

nu_ks = squeeze(sort(vecnorm(X - permute(Y, [3, 2, 1]), 2, 2), 1));
nu = nu_ks(sub2ind([N, M], sum(nu_ks == 0, 1) + k, 1:M)); clear nu_ks;

BC = BC + (1/M)*sum(sqrt(((M - 1)*rho)./(N*nu)));
BC = BC*Bka/2;

BC = max(0, min(1, BC));

end