function [out] =Wass_stat_M(vec1,vec2,power)
% computes Wasserstein distance
n1 = length(vec1);
n2 = length(vec2);
n = n1+n2;

joint_sample = [vec1;vec2];
ee = [(1/n1)*ones(1,n1),zeros(1,n2)];
ff = [zeros(1,n1),(1/n2)*ones(1,n2)];
%   joint_sample = [vec1;vec2];
%   ee = c(rep(1/n1,n1),rep(0,   n2))
%   ff = c(rep(0,   n1),rep(1/n2,n2))

[temp,ind] = sort(joint_sample);
d = joint_sample(ind);
e = ee(ind);
f = ff(ind);

out = 0;
Ecur = 0;
Fcur = 0;
for i =1:(n-1)
    Ecur = Ecur + e(i);
    Fcur = Fcur + f(i);
    height = abs(Fcur-Ecur);
    width = d(i+1)-d(i);
    out = out + (height*power)*width;
end

end