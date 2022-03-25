# ABC-dist-compare
Matlab code to support the article "A Comparison of Likelihood-Free Methods With and Without Summary Statistics" by Drovandi and Frazier that will appear in Statistics and Computing.

Each folder contains the code for a different example of the paper.

Note that the stereological extremes example uses a mex function to simulate the model to increase speed.  However, the code probably will not run on various operating systems outside of Windows OS it was compiled on.  However, the mex file can be recreated from the matlab simulation function esim.m using codegen in Matlab, see https://au.mathworks.com/help/coder/ref/codegen.html.

Some of the files to support the implementation of methods and visualisation of results have been obtained from freely available sources:

The file rbf_dot.m to help compute the MMD distance was obntained from  http://www.gatsby.ucl.ac.uk/~gretton/kernelBP/kernelBP.htm.

Aslak Grinsted (2022). Subaxis - Subplot (https://www.mathworks.com/matlabcentral/fileexchange/3696-subaxis-subplot), MATLAB Central File Exchange.
