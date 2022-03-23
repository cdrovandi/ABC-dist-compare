function [theta] = para_back_transform (theta_tilde)

theta = [10/(1+exp(-theta_tilde(1))), 10/(1+exp(-theta_tilde(2))), 0.5/(1+exp(-theta_tilde(3)))];

end