function W = compute_obs_inf(theta,y,obj,numComp)
        
        
w = theta(1:(numComp-1));
w(numComp) = 1-sum(theta(1:(numComp-1)));
mu = theta(numComp:(2*numComp-1));
sigma = sqrt(theta((2*numComp):(3*numComp-1)));
the_grad = zeros(1,(3*numComp-1));
W = zeros((3*numComp-1));

for t = 1:length(y)
    
    for i = 1:(numComp-1)
        the_grad(i) = sum(1./pdf(obj,y(t)).*(normpdf(y(t),mu(i),sigma(i)) - normpdf(y(t),mu(numComp),sigma(numComp))));
    end
    for i = 1:numComp
        the_grad(i+numComp-1) = sum(1./pdf(obj,y(t)).*(w(i)*normpdf(y(t),mu(i),sigma(i))*1/sigma(i)^2.*(y(t)-mu(i))));
    end
    for i = 1:numComp
        the_grad(i+2*numComp-1) = sum(1./pdf(obj,y(t))*w(i).*normpdf(y(t),mu(i),sigma(i)).*(-0.5/sigma(i)^2 + 0.5/sigma(i)^4*(y(t)-mu(i)).^2));
    end
    
    W = W + the_grad'*the_grad;
    
end



end