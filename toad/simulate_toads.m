function[X] = simulate_toads3(theta, ntoads, ndays, model,d0)
% simulate toads location for each toad and day
% INPUT:
% theta - model parameters, alpha, gamma and p0 (the probability of returning to a previous refuge)
% ntoads - the number of individual toads
% ndays - the number of days for simulation
% model - indicator for model version in the paper Marchand, et al (2017),
%         1 stands for random return
%         2 stands for nearest return
% OUTPUT:
% X - a ndays by ntoads matrix contains toads location for each toad and

if nargin < 5 & model == 3
    error('must specify a d0 in model 3')
end

if ~ismember(model,1:3)
    error('undefined model indicator number')
end

alpha = theta(1);
gamma = theta(2);
p0 = theta(3);
X = zeros(ndays, ntoads);

X_uniq = zeros(ndays, ntoads);
n_rs = int32(0);
pi_ret = 0;

if model == 3
    X_uniq = zeros(ndays,ntoads); % locations of all unique refuge sites
end
if model == 1 || model == 2
    for i = 2:ndays
        if (model == 1) % random return
            % toads that stay at new location
            ind = rand(1,ntoads) >= p0;
            deltax = rndlas(sum(ind),gamma,alpha)'; % distance of move (only generate distance for toads that stay at new location)
            X(i,ind) = X(i-1,ind) + deltax;
            
            % return to one of the previous refuge sites
            % multiple visits to a refuge site increases the weighting
            ind_refuge = randsample(i-1,ntoads-sum(ind),true)';
            idx = sub2ind(size(X),ind_refuge,find(~ind));
            X(i,find(~ind)) = X(idx);
            
        elseif (model == 2) % nearest return
            % generate displacements
            deltax = rndlas(ntoads,gamma,alpha)';
            X(i,:) = X(i-1,:) + deltax;
            
            % return to the closest refuge site with probability p0
            ind = rand(1,ntoads) >= p0;
            if (i == 2)
                X(i,find(~ind)) = zeros(1,length(find(~ind)));
            else
                [~,ind_refuge] = min(abs(X(i,find(~ind))-X(1:i-1,find(~ind))));
                idx = sub2ind(size(X),ind_refuge,find(~ind));
                X(i,find(~ind)) = X(idx);
            end
        end
    end
    
else % model 3
    for j = 1:ntoads
        if model == 3
            n_rs = int32(1); % intial number of unique refuge sites
        end
        for i = 2:ndays
            deltax = rndlas(1, gamma, alpha); % distance of the potential move
            
            xtemp = X(i-1,j) + deltax; % potential location if made the above move
            dtemp = abs(xtemp-X_uniq(1:n_rs,j)); % distances to all previous unique refuge sites
            pi_ret = p0*exp(-dtemp/d0); % return prob for the i-th unique site
            p_ret = prod(1-pi_ret); % total return prob
            
            
            if rand >= p_ret % take refuge here
                X(i,j) = X(i-1,j) + deltax;
                n_rs = n_rs+1;
                X_uniq(n_rs,j) = X(i,j);
                
            else % return to one of the previous refuge sites
                if model == 1
                    ind_refuge = randsample(i-1,1);
                    X(i,j) = X(ind_refuge,j);
                else
                    
                    ind_rs = find(unifrnd(0,sum(pi_ret)) < cumsum(pi_ret), 1); % C code mex version
                    X(i,j) = X_uniq(ind_rs(1),j);
                end
            end
        end
    end
    
    
end


