% Update arrival times and parameters by shifting them

function [par_cur, v_cur, acc] = shift_sample(x, y, par_cur, v_cur, shift_scale)

    acc = 0;
    c = zeros(1, 2);
    
    shift_prop = shift_scale*randn;

    % Check if we have proposed to shift the first arrival time to
    % be less than 0 and if we have shifted the minimum service
    % time to be less than 0. Checking for these constraints here avoids
    % checking them in the likelihood, saving us some time. 
    
    v_prop = v_cur + shift_prop;
    c(1) = v_prop(1) > 0;
    
    theta_1_prop = par_cur(1) - shift_prop;
    c(2) = theta_1_prop > 0;
    	
    if all(c) == 1
        
        lprior_cur = lprior_unif_orig(par_cur);
        ll_cur = queue_ll_orig(x, y, v_cur, par_cur);
        lpost_cur = lprior_cur + ll_cur;
        
        par_prop = par_cur;
        par_prop(1) = theta_1_prop;
        
        lprior_prop = lprior_unif_orig(par_prop);
        ll_prop = queue_ll_orig(x, y, v_prop, par_prop);
        lpost_prop = lprior_prop + ll_prop;
        
        alpha = rand;
        
        if exp(lpost_prop - lpost_cur) > alpha

            par_cur = par_prop;
            v_cur = v_prop;
            
            acc = 1;

        end
        
    end

end