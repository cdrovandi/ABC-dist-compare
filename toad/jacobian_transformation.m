function [J] = jacobian_transformation (theta_tilde)

% (1,2) by (0,100) by (0,0.9)

e_theta_tilde = exp(theta_tilde);

a = [1, 0, 0];
b = [2, 100, 0.9];
logJ = log(b - a) - log(1 ./ e_theta_tilde + 2 + e_theta_tilde);
J = exp(sum(logJ));

end