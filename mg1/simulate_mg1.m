function x = simulate_mg1(theta,T)
% simulate from mg1 model

w = exprnd(1/theta(3),T,1);
s = unifrnd(theta(1), theta(2), T, 1);

x = zeros(T,1);
d = 0; v = 0;
for i = 1:T
   v = v + w(i);
   d = d + s(i) + max(0,v-d);
   x(i) = d;
end

x = diff(x);
end