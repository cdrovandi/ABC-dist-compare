function ssx = summStat_stereo_112(x)

q = quantile(x,(1:50)./51);
difq = diff(q);
ind = find(difq == 0);
difq(ind) = 0.000001;
ssx = [length(x) median(x) log(difq)]';

end