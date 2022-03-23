function s = summStat_aux(x,obj,theta_d,numComp)

    
    s = [length(x) compute_grad(theta_d,x,obj,numComp)];


end