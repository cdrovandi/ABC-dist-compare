function [theta_tilde] = para_transform (theta)

theta_tilde =[log(theta(1)/(10-theta(1))), log(theta(2)/(10-theta(2))), log(theta(3)/(0.5-theta(3)))];

end