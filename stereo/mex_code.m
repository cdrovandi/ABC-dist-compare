theta = [100 2 -0.1];
codegen esim -args {theta,5};


%%%%%%

x = esim(theta,5);
x = coder.typeof(x,[Inf 1]);
codegen summary_statistic_stereo_sltest -args {x,1}



%%%%%%%%%%%%%%%%%%%%%%%%%

tic;
parfor k = 1:n
    k
    x = esim(theta,5);
end
toc;
% 6.53 sec

tic;
parfor k = 1:n
    k
    x = esim_mex(theta,5);
end
toc;
% 1.51 sec


tic;
parfor k = 1:n*100
    k
    summary_statistic_stereo_sltest(x,1);
end
toc;
% 1.37 sec

tic;
parfor k = 1:n*100
    k
   summary_statistic_stereo_sltest_mex(x,1);
end
toc;
% 1.25 sec
