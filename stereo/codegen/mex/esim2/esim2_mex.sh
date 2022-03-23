MATLAB="/Applications/MATLAB_R2017b.app"
Arch=maci64
ENTRYPOINT=mexFunction
MAPFILE=$ENTRYPOINT'.map'
PREFDIR="/Users/ziwen/Library/Application Support/MathWorks/MATLAB/R2017b"
OPTSFILE_NAME="./setEnv.sh"
. $OPTSFILE_NAME
COMPILER=$CC
. $OPTSFILE_NAME
echo "# Make settings for esim2" > esim2_mex.mki
echo "CC=$CC" >> esim2_mex.mki
echo "CFLAGS=$CFLAGS" >> esim2_mex.mki
echo "CLIBS=$CLIBS" >> esim2_mex.mki
echo "COPTIMFLAGS=$COPTIMFLAGS" >> esim2_mex.mki
echo "CDEBUGFLAGS=$CDEBUGFLAGS" >> esim2_mex.mki
echo "CXX=$CXX" >> esim2_mex.mki
echo "CXXFLAGS=$CXXFLAGS" >> esim2_mex.mki
echo "CXXLIBS=$CXXLIBS" >> esim2_mex.mki
echo "CXXOPTIMFLAGS=$CXXOPTIMFLAGS" >> esim2_mex.mki
echo "CXXDEBUGFLAGS=$CXXDEBUGFLAGS" >> esim2_mex.mki
echo "LDFLAGS=$LDFLAGS" >> esim2_mex.mki
echo "LDOPTIMFLAGS=$LDOPTIMFLAGS" >> esim2_mex.mki
echo "LDDEBUGFLAGS=$LDDEBUGFLAGS" >> esim2_mex.mki
echo "Arch=$Arch" >> esim2_mex.mki
echo "LD=$LD" >> esim2_mex.mki
echo OMPFLAGS= >> esim2_mex.mki
echo OMPLINKFLAGS= >> esim2_mex.mki
echo "EMC_COMPILER=clang" >> esim2_mex.mki
echo "EMC_CONFIG=optim" >> esim2_mex.mki
"/Applications/MATLAB_R2017b.app/bin/maci64/gmake" -B -f esim2_mex.mk
