% Update arrival times and parameters by scaling them

function [par_cur, v_cur, acc] = range_sample(x, y, par_cur, v_cur, scale)

    n = length(y);
    acc = 0;
    c = zeros(1, 2);
    
    scale = scale^(2*(rand < 0.5) - 1);
    
    theta_1_cur = par_cur(1);
    theta_2_cur = par_cur(2) + par_cur(1);

    v_prop = (x-theta_1_cur) - scale*((x-theta_1_cur) - v_cur);

    % Check if any of the arrival times have been permuted. This is a
    % constraint that we can enforce when computing the likelihood;
    % however, checking for it here saves us some computation time. 
    
    c(1) = all(diff(v_prop) > 0);
    c(2) = v_prop(1) > 0;
    
    if all(c) == 1

        lprior_cur = lprior_unif_orig(par_cur);
        ll_cur = queue_ll_orig(x, y, v_cur, par_cur);
        lpost_cur = lprior_cur + ll_cur;

        par_prop = par_cur;
        par_prop(2) = (theta_2_cur - theta_1_cur)*scale;

        lprior_prop = lprior_unif_orig(par_prop);
        ll_prop = queue_ll_orig(x, y, v_prop, par_prop);
        lpost_prop = lprior_prop + ll_prop;

        alpha = rand;

        if exp(lpost_prop - lpost_cur + (n+1)*log(scale)) > alpha

            par_cur = par_prop;
            v_cur = v_prop;
            
            acc = 1;

        end

    end
    
end