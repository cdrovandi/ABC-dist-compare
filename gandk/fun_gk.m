function f = fun_gk(parms,zu)
%%
% the g-and-k quantile function
% a = parms(1); b = parms(2); c = parms(3); g = parms(4); k = parms(5);
% zu has the quantiles of the standard normal distribution (vector)
%%
    a = parms(1); b = parms(2); c = 0.8; g = parms(3); k = parms(4);
    f = a + b*(1 + c*(1-exp(-g*zu))./(1 + exp(-g*zu))).*(1 + zu.^2).^k.*zu;    
end