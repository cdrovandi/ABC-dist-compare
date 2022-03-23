function ss = summary_statistic_stereo_sltest(y,useLog)
% compute the 4 summary statistics

if nargin < 2
    useLog = 0;
end

ss = zeros(4,1);
if (isempty(y))
    return; 
end

% compute the summary statistics
ss(1) = length(y);
ss(2) = min(y);
ss(3) = mean(y);
ss(4) = max(y);

if useLog
    ss([2 3 4]) = log(ss([2 3 4]));
end

end
    