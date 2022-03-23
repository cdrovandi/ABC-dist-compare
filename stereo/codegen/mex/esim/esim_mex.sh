MATLAB="/Applications/MATLAB_R2017b.app"
Arch=maci64
ENTRYPOINT=mexFunction
MAPFILE=$ENTRYPOINT'.map'
PREFDIR="/Users/ziwen/Library/Application Support/MathWorks/MATLAB/R2017b"
OPTSFILE_NAME="./setEnv.sh"
. $OPTSFILE_NAME
COMPILER=$CC
. $OPTSFILE_NAME
echo "# Make settings for esim" > esim_mex.mki
echo "CC=$CC" >> esim_mex.mki
echo "CFLAGS=$CFLAGS" >> esim_mex.mki
echo "CLIBS=$CLIBS" >> esim_mex.mki
echo "COPTIMFLAGS=$COPTIMFLAGS" >> esim_mex.mki
echo "CDEBUGFLAGS=$CDEBUGFLAGS" >> esim_mex.mki
echo "CXX=$CXX" >> esim_mex.mki
echo "CXXFLAGS=$CXXFLAGS" >> esim_mex.mki
echo "CXXLIBS=$CXXLIBS" >> esim_mex.mki
echo "CXXOPTIMFLAGS=$CXXOPTIMFLAGS" >> esim_mex.mki
echo "CXXDEBUGFLAGS=$CXXDEBUGFLAGS" >> esim_mex.mki
echo "LDFLAGS=$LDFLAGS" >> esim_mex.mki
echo "LDOPTIMFLAGS=$LDOPTIMFLAGS" >> esim_mex.mki
echo "LDDEBUGFLAGS=$LDDEBUGFLAGS" >> esim_mex.mki
echo "Arch=$Arch" >> esim_mex.mki
echo "LD=$LD" >> esim_mex.mki
echo OMPFLAGS= >> esim_mex.mki
echo OMPLINKFLAGS= >> esim_mex.mki
echo "EMC_COMPILER=clang" >> esim_mex.mki
echo "EMC_CONFIG=optim" >> esim_mex.mki
"/Applications/MATLAB_R2017b.app/bin/maci64/gmake" -B -f esim_mex.mk
