% Log-likelihood for M/G/1 queue model

function [ll, theta_bounds] = queue_ll_orig(x, y, v, par_vec)

    n = length(y);
    c = zeros(1, 5);
    
    theta_1 = par_vec(1);
    theta_2 = par_vec(2) + par_vec(1);
    theta_3 = exp(par_vec(3));
    
    c(1) = theta_2 - theta_1 > 0;
    c(2) = theta_1 <= y(1) - v(1);
    c(3) = theta_2 >= y(1) - v(1);
    c(4) = theta_1 <= min(y(2:n) - max(0, v(2:n) - x(1:n-1)));
    c(5) = theta_2 >= max(y(2:n) - max(0, v(2:n) - x(1:n-1)));

    if all(c) == 1
        
        ll = n*log(theta_3) - theta_3*v(n) - n*log(theta_2-theta_1);
    
    else
        
        ll = -Inf;
        
    end
    
    theta_bounds(1) = min(y(1) - v(1), min(y(2:n) - max(0, v(2:n) - x(1:n-1))));
    theta_bounds(2) = max(y(1) - v(1), max(y(2:n) - max(0, v(2:n) - x(1:n-1))));
    
end