function f = cvm_dist(x,y)

m = length(x);
n = length(y);

[fx,xx] = ecdf(x);
[fy,xy] = ecdf(y);
z = [x y];
xx = xx(2:end);
fx = fx(2:end);
xy = xy(2:end);
fy = fy(2:end);
Fx = interp1(xx, fx, z, 'previous');
Fy = interp1(xy, fy, z, 'previous');

Fx(z<xx(1)) = 0;
Fx(z>xx(end)) = 1;

Fy(z<xy(1)) = 0;
Fy(z>xy(end)) = 1;

f = m*n/(m+n)^2*sum((Fx - Fy).^2);

end