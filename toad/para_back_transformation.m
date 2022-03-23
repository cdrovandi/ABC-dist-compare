function [theta] = para_back_transformation(theta_tilde)

% (1,2) by (0,100) by (0,0.9)

e_theta_tilde = exp(theta_tilde);

a = [1, 0, 0];
b = [2, 100, 0.9];
theta = a ./ (1 + e_theta_tilde) + b ./ (1 + 1 ./ e_theta_tilde);

end

