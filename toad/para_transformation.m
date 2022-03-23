function [theta_tilde] = para_transformation(theta)

% (1,2) by (0,100) by (0,0.9)

alpha = theta(:,1);
gamma = theta(:,2);
p0 = theta(:,3);

alpha_tilde = log((alpha-1) ./ (2-alpha));
gamma_tilde = log(gamma ./ (100-gamma));
p0_tilde = log(p0 ./ (0.9-p0));

theta_tilde = [alpha_tilde,gamma_tilde,p0_tilde];

end

