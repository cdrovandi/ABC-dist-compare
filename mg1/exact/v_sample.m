% Sample arrival times

function v = v_sample(x, y, par_cur, v)

    n = length(y);

    % Update the first hidden state

    theta_1_cur = par_cur(1);
    theta_2_cur = par_cur(2) + par_cur(1);
    theta_3_cur = exp(par_cur(3));
        
    lb = max(0, x(1) - theta_2_cur);
    ub = min(v(2), x(1) - theta_1_cur);
    
    v(1) = lb + (ub-lb)*rand;
    
    % Update the intermediate hidden states
    
    for j = 2 : n-1
        
        if y(j) > theta_2_cur
            
            lb = x(j) - theta_2_cur;
            
        else
        
            lb = v(j-1);
          
        end
        
        ub = min(v(j+1), x(j) - theta_1_cur);
        
        v(j) = lb + (ub-lb)*rand;
                                      
    end
    
    % Update the last hidden state
    
    if y(n) > theta_2_cur
    
        lb = x(n) - theta_2_cur;
        
    else
        
        lb = v(n-1);
        
    end
    
    ub = x(n) - theta_1_cur;
    
    p = rand;
    
    v(n) = -add_logs(-theta_3_cur*lb + log(1-p), -theta_3_cur*ub + log(p)) / theta_3_cur;
    
end
