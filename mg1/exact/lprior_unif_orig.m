% Prior for the queueing model parameters

function lpr = lprior_unif_orig(par_vec)

    if all(par_vec(1:2) >= 0) && all(par_vec(1:2) <= 10) && par_vec(3) <= log(1/3)

        lpr = par_vec(3);
        
    else
        
        lpr = -Inf;
        
    end   

end