function f = log_like_gk(x,c,data)
% returns exact (negative) log-likelihood for g-and-k model up to numerical precision
    a = x(1); b = x(2); g = x(3); k = x(4);
    parms = [a;b;c;g;k];
    n = length(data);
    f = 0;
    for i = 1:n
        fa = data(i)-density_gk(0+eps,parms);
        fb = data(i)-density_gk(1-eps,parms);
        if ((fa > 0 && fb > 0) || (fa < 0 && fb < 0))
            f = Inf;
            return;
        end
        u = fzero(@(x)(data(i)-density_gk(x,parms)),[0+eps;1-eps]);
        zu = norminv(u,0,1);
        f = f + log(normpdf(zu,0,1)) - log(b*c*(1 + zu^2)^k*((1/c + (1-exp(-g*zu))/(1+exp(-g*zu)))*(1 + (2*k+1)*zu^2)/(1 + zu^2) + 2*g*zu*exp(-g*zu)/((1 + exp(-g*zu))^2)));
    end
    f = -f; % minimise the negative loglikelihood function
    
end 