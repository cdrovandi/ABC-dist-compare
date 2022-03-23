function q = density_gk(u,parms)
% simulates g-and-k model based on parameters and uniform random numbers
    a = parms(1); b = parms(2); c = parms(3); g = parms(4); k = parms(5);
    zu = norminv(u,0,1);
    q = a + b*(1 + c*(1-exp(-g*zu))./(1 + exp(-g*zu))).*(1 + zu.^2).^k.*zu;
end