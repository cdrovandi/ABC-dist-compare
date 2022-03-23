function res = esim(theta,u)

lam=theta(1);
sig=theta(2);
xi =theta(3);

nn=poissrnd(lam*100);

z=unifrnd(-50,50,nn,1);

a=(u+sig*((1-rand(nn,1)).^(-xi)-1)/xi)/2;

b=rand(nn,1).*a;
cc=rand(nn,1).*a;

pars = [a b cc];
for i = 1:nn
    pars(i,:) = pars(i,randsample(1:3,3));
end

a=pars(:,1);
b=pars(:,2);
cc=pars(:,3);

dm = max([a b cc],[],2);


th=unifrnd(0,2*pi,nn,1);
ph=unifrnd(0,2*pi,nn,1);
p=-sin(ph)./z;
q=cos(ph).*sin(th)./z;
r=cos(ph).*cos(th)./z;


den=r.^2.*cc.^2; % cc
A1=a.^(-2)+p.^2./den;
B1=p.*q./den;
C1=b.^(-2)+q.^2./den;
D1=-p./den;
E1=-q./den;
F1=1./den-1;

tt=atan(2*B1./(A1-C1))/2;
%tt(isnan(tt)) = 0;

A2=A1.*(cos(tt)).^2+2*B1.*sin(tt).*cos(tt)+C1.*(sin(tt)).^2;
B2=A1.*(sin(tt)).^2-2*B1.*sin(tt).*cos(tt)+C1.*(cos(tt)).^2;
D2=D1.*cos(tt)+E1.*sin(tt);
E2=-D1.*sin(tt)+E1.*cos(tt);
F2=F1;

% A3=2*sqrt(D2.^2./A2.^2+E2.^2./(A2.*B2)-F2./A2);
% B3=2*sqrt(D2.^2./(A2.*B2)+E2.^2./B2.^2-F2./B2);
A3=2*sqrt(complex(D2.^2./A2.^2+E2.^2./(A2.*B2)-F2./A2));
B3=2*sqrt(complex(D2.^2./(A2.*B2)+E2.^2./B2.^2-F2./B2));
% A3=2*real(sqrt(D2.^2./A2.^2+E2.^2./(A2.*B2)-F2./A2));
% B3=2*real(sqrt(D2.^2./(A2.*B2)+E2.^2./B2.^2-F2./B2));
% temp1 = D2.^2./A2.^2+E2.^2./(A2.*B2)-F2./A2;
% temp2 = D2.^2./(A2.*B2)+E2.^2./B2.^2-F2./B2;
% A3=2*sqrt(temp1(temp1>=0.*temp2>=0));
% B3=2*sqrt(temp2(temp1>=0.*temp2>=0));


res = max([A3 B3],[],2);

dm=dm(res>u);
res = res(res>u);


% if (max(res)>20)
%     error('an extreme value of res detected')
% end

end
