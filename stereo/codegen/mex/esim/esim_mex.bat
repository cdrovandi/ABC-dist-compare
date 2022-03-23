@echo off
set MATLAB=C:\PROGRA~1\MATLAB\R2017a
set MATLAB_ARCH=win64
set MATLAB_BIN="C:\Program Files\MATLAB\R2017a\bin"
set ENTRYPOINT=mexFunction
set OUTDIR=.\
set LIB_NAME=esim_mex
set MEX_NAME=esim_mex
set MEX_EXT=.mexw64
call setEnv.bat
echo # Make settings for esim > esim_mex.mki
echo COMPILER=%COMPILER%>> esim_mex.mki
echo COMPFLAGS=%COMPFLAGS%>> esim_mex.mki
echo OPTIMFLAGS=%OPTIMFLAGS%>> esim_mex.mki
echo DEBUGFLAGS=%DEBUGFLAGS%>> esim_mex.mki
echo LINKER=%LINKER%>> esim_mex.mki
echo LINKFLAGS=%LINKFLAGS%>> esim_mex.mki
echo LINKOPTIMFLAGS=%LINKOPTIMFLAGS%>> esim_mex.mki
echo LINKDEBUGFLAGS=%LINKDEBUGFLAGS%>> esim_mex.mki
echo MATLAB_ARCH=%MATLAB_ARCH%>> esim_mex.mki
echo BORLAND=%BORLAND%>> esim_mex.mki
echo OMPFLAGS= >> esim_mex.mki
echo OMPLINKFLAGS= >> esim_mex.mki
echo EMC_COMPILER=msvc140>> esim_mex.mki
echo EMC_CONFIG=optim>> esim_mex.mki
"C:\Program Files\MATLAB\R2017a\bin\win64\gmake" -B -f esim_mex.mk
