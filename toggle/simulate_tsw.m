function y = simulate_tsw(theta)
    % function that simulates toggle model
	
	T = 300; C = 2000;
    %T = 600; C = 8000;

    mu = theta(1); sigma = theta(2); gam = theta(3);
    alpha.u = theta(4); alpha.v = theta(6);
    bet.u = theta(5); bet.v = theta(7);
    
    ut = 10*ones(C,1); vt = 10*ones(C,1);
    
    
    zeta = randn(C, 2*(T-1)+1);
    
    for j = 2:T
        p.u = vt.^bet.u; p.v = ut.^bet.v;
        ut = 0.97*ut + alpha.u./(1+ p.u) - 1.0 + 0.5*zeta(: ,2*(j-1));
        vt = 0.97*vt + alpha.v./(1+ p.v) - 1.0 + 0.5*zeta(:,2*(j-1) + 1);
        ut(ut < 1) = 1; vt(vt < 1) = 1;
    end
    
    y = ut + mu + sigma*mu*zeta(: ,1)./(ut.^gam);
    y(y<1) = 1;
    
end

