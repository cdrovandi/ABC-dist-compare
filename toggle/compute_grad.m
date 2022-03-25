function the_grad = compute_grad(theta,y,obj,numComp)
% compute summary statistics for g-and-k example (scores of auxuliary mixture model)
w = theta(1:(numComp-1));
w(numComp) = 1-sum(theta(1:(numComp-1)));
mu = theta(numComp:(2*numComp-1));
sigma = sqrt(theta((2*numComp):(3*numComp-1)));
the_grad = zeros(1,(3*numComp-1));
for i = 1:(numComp-1)
    the_grad(i) = sum(1./pdf(obj,y).*(normpdf(y,mu(i),sigma(i)) - normpdf(y,mu(numComp),sigma(numComp))));
end
for i = 1:numComp
    the_grad(i+numComp-1) = sum(1./pdf(obj,y).*(w(i)*normpdf(y,mu(i),sigma(i))*1/sigma(i)^2.*(y-mu(i))));
end
for i = 1:numComp
    the_grad(i+2*numComp-1) = sum(1./pdf(obj,y)*w(i).*normpdf(y,mu(i),sigma(i)).*(-0.5/sigma(i)^2 + 0.5/sigma(i)^4*(y-mu(i)).^2));
end

end