MATLAB="/Applications/MATLAB_R2017b.app"
Arch=maci64
ENTRYPOINT=mexFunction
MAPFILE=$ENTRYPOINT'.map'
PREFDIR="/Users/ziwen/Library/Application Support/MathWorks/MATLAB/R2017b"
OPTSFILE_NAME="./setEnv.sh"
. $OPTSFILE_NAME
COMPILER=$CC
. $OPTSFILE_NAME
echo "# Make settings for summary_statistic_stereo_sltest" > summary_statistic_stereo_sltest_mex.mki
echo "CC=$CC" >> summary_statistic_stereo_sltest_mex.mki
echo "CFLAGS=$CFLAGS" >> summary_statistic_stereo_sltest_mex.mki
echo "CLIBS=$CLIBS" >> summary_statistic_stereo_sltest_mex.mki
echo "COPTIMFLAGS=$COPTIMFLAGS" >> summary_statistic_stereo_sltest_mex.mki
echo "CDEBUGFLAGS=$CDEBUGFLAGS" >> summary_statistic_stereo_sltest_mex.mki
echo "CXX=$CXX" >> summary_statistic_stereo_sltest_mex.mki
echo "CXXFLAGS=$CXXFLAGS" >> summary_statistic_stereo_sltest_mex.mki
echo "CXXLIBS=$CXXLIBS" >> summary_statistic_stereo_sltest_mex.mki
echo "CXXOPTIMFLAGS=$CXXOPTIMFLAGS" >> summary_statistic_stereo_sltest_mex.mki
echo "CXXDEBUGFLAGS=$CXXDEBUGFLAGS" >> summary_statistic_stereo_sltest_mex.mki
echo "LDFLAGS=$LDFLAGS" >> summary_statistic_stereo_sltest_mex.mki
echo "LDOPTIMFLAGS=$LDOPTIMFLAGS" >> summary_statistic_stereo_sltest_mex.mki
echo "LDDEBUGFLAGS=$LDDEBUGFLAGS" >> summary_statistic_stereo_sltest_mex.mki
echo "Arch=$Arch" >> summary_statistic_stereo_sltest_mex.mki
echo "LD=$LD" >> summary_statistic_stereo_sltest_mex.mki
echo OMPFLAGS= >> summary_statistic_stereo_sltest_mex.mki
echo OMPLINKFLAGS= >> summary_statistic_stereo_sltest_mex.mki
echo "EMC_COMPILER=clang" >> summary_statistic_stereo_sltest_mex.mki
echo "EMC_CONFIG=optim" >> summary_statistic_stereo_sltest_mex.mki
"/Applications/MATLAB_R2017b.app/bin/maci64/gmake" -B -f summary_statistic_stereo_sltest_mex.mk
