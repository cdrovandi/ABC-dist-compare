% Update parameters with a Metropolis update

function [par_cur, acc] = par_sample(x, y, par_cur, v_cur, s_prop, numupd_met)

    acc = 0;
    
    lprior_cur = lprior_unif_orig(par_cur);
    [ll_cur, theta_bounds] = queue_ll_orig(x, y, v_cur, par_cur);
    lpost_cur = lprior_cur + ll_cur;
    
    for i = 1 : numupd_met
    
        par_prop = par_cur + s_prop .* randn(1, 3);
%         par_prop = mvnrnd(par_cur, s_prop);

        lprior_prop = lprior_unif_orig(par_prop);
        ll_prop = queue_ll_quick(y, v_cur, par_prop, theta_bounds);
        lpost_prop = lprior_prop + ll_prop;

        alpha = rand;

        if exp(lpost_prop - lpost_cur) > alpha

            par_cur = par_prop;
            lpost_cur = lpost_prop;
            
            acc = 1;

        end
    
    end
    
end