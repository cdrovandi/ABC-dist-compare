@echo off
set MATLAB=D:\Program Files\MATLAB\R2017b
set MATLAB_ARCH=win64
set MATLAB_BIN="D:\Program Files\MATLAB\R2017b\bin"
set ENTRYPOINT=mexFunction
set OUTDIR=.\
set LIB_NAME=summary_statistic_stereo_sltest_mex
set MEX_NAME=summary_statistic_stereo_sltest_mex
set MEX_EXT=.mexw64
call setEnv.bat
echo # Make settings for summary_statistic_stereo_sltest > summary_statistic_stereo_sltest_mex.mki
echo CC=%COMPILER%>> summary_statistic_stereo_sltest_mex.mki
echo CXX=%CXXCOMPILER%>> summary_statistic_stereo_sltest_mex.mki
echo CFLAGS=%COMPFLAGS%>> summary_statistic_stereo_sltest_mex.mki
echo CXXFLAGS=%CXXCOMPFLAGS%>> summary_statistic_stereo_sltest_mex.mki
echo OPTIMFLAGS=%OPTIMFLAGS%>> summary_statistic_stereo_sltest_mex.mki
echo DEBUGFLAGS=%DEBUGFLAGS%>> summary_statistic_stereo_sltest_mex.mki
echo LINKER=%LINKER%>> summary_statistic_stereo_sltest_mex.mki
echo LINKFLAGS=%LINKFLAGS%>> summary_statistic_stereo_sltest_mex.mki
echo LINKOPTIMFLAGS=%LINKOPTIMFLAGS%>> summary_statistic_stereo_sltest_mex.mki
echo LINKDEBUGFLAGS=%LINKDEBUGFLAGS%>> summary_statistic_stereo_sltest_mex.mki
echo MATLAB_ARCH=%MATLAB_ARCH%>> summary_statistic_stereo_sltest_mex.mki
echo OMPFLAGS= >> summary_statistic_stereo_sltest_mex.mki
echo OMPLINKFLAGS= >> summary_statistic_stereo_sltest_mex.mki
echo EMC_COMPILER=mingw64>> summary_statistic_stereo_sltest_mex.mki
echo EMC_CONFIG=optim>> summary_statistic_stereo_sltest_mex.mki
"D:\Program Files\MATLAB\R2017b\bin\win64\gmake" -B -f summary_statistic_stereo_sltest_mex.mk
