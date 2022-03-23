% Update arrival times and parameters by scaling them

function [par_cur, v_cur, acc] = rate_sample(x, y, par_cur, v_cur, c_rate)

    n = length(y);
    acc = 0;
    c = zeros(1, 2);
    
    theta_1_cur = par_cur(1);
    theta_2_cur = par_cur(1) + par_cur(2);
    
    c_rate = c_rate^(2*(rand < 0.5) - 1);
    v_prop = v_cur*c_rate;
    
    % Check if the proposed arrival times are all smaller than
    % x_i - theta_1_cur and for y_i > theta_2_cur, between 
    % x_(i) - theta_2 and x_(i) - theta_1_cur
    
    big_gaps = (y > theta_2_cur);
    c(1) = all(v_prop <= x - theta_1_cur);
    
    if sum(big_gaps) > 0
    
        c(2) = all(v_prop(big_gaps) >= x(big_gaps) - theta_2_cur);
        
    else
        
        c(2) = 1;
        
    end
    
    if all(c) == 1

        lprior_cur = lprior_unif_orig(par_cur);
        ll_cur = queue_ll_orig(x, y, v_cur, par_cur);
        lpost_cur = lprior_cur + ll_cur;

        par_prop = par_cur;
        par_prop(3) = par_prop(3) - log(c_rate);
    
        lprior_prop = lprior_unif_orig(par_prop);
        ll_prop = queue_ll_orig(x, y, v_prop, par_prop);
        lpost_prop = lprior_prop + ll_prop;

        alpha = rand;

        if exp(lpost_prop - lpost_cur + n*log(c_rate)) > alpha

            par_cur = par_prop;
            v_cur = v_prop;
            
            acc = 1;

        end

    end
    
end