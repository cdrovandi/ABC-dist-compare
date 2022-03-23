% Log-likelihood for the M/G/1 queue model

function ll = queue_ll_quick(y, v, par_vec, theta_bounds)

    n = length(y);
    c = zeros(1, 3);
    
    theta_1 = par_vec(1);
    theta_2 = par_vec(2) + par_vec(1);
    theta_3 = exp(par_vec(3));
    
    c(1) = theta_2 - theta_1 > 0;
    c(2) = theta_1 <= theta_bounds(1);
    c(3) = theta_2 >= theta_bounds(2);

    if all(c) == 1
        
        ll = n*log(theta_3) - theta_3*v(n) - n*log(theta_2-theta_1);
    
    else
        
        ll = -Inf;
        
    end
    
end