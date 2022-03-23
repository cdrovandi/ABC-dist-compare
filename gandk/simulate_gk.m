function q = simulate_gk(n,parms)
%%
% method to simulate from the g and k distribution
% a = parms(1); b = parms(2); c = parms(3); g = parms(4); k = parms(5);
% n is the number of observations
%%
    zu = randn(n,1);
    q = fun_gk(parms,zu);
end