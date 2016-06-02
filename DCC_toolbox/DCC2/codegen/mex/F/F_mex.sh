MATLAB="/Applications/MATLAB_R2016a.app"
Arch=maci64
ENTRYPOINT=mexFunction
MAPFILE=$ENTRYPOINT'.map'
PREFDIR="/Users/xuyuting/.matlab/R2016a"
OPTSFILE_NAME="./setEnv.sh"
. $OPTSFILE_NAME
COMPILER=$CC
. $OPTSFILE_NAME
echo "# Make settings for F" > F_mex.mki
echo "CC=$CC" >> F_mex.mki
echo "CFLAGS=$CFLAGS" >> F_mex.mki
echo "CLIBS=$CLIBS" >> F_mex.mki
echo "COPTIMFLAGS=$COPTIMFLAGS" >> F_mex.mki
echo "CDEBUGFLAGS=$CDEBUGFLAGS" >> F_mex.mki
echo "CXX=$CXX" >> F_mex.mki
echo "CXXFLAGS=$CXXFLAGS" >> F_mex.mki
echo "CXXLIBS=$CXXLIBS" >> F_mex.mki
echo "CXXOPTIMFLAGS=$CXXOPTIMFLAGS" >> F_mex.mki
echo "CXXDEBUGFLAGS=$CXXDEBUGFLAGS" >> F_mex.mki
echo "LD=$LD" >> F_mex.mki
echo "LDFLAGS=$LDFLAGS" >> F_mex.mki
echo "LDOPTIMFLAGS=$LDOPTIMFLAGS" >> F_mex.mki
echo "LDDEBUGFLAGS=$LDDEBUGFLAGS" >> F_mex.mki
echo "Arch=$Arch" >> F_mex.mki
echo OMPFLAGS= >> F_mex.mki
echo OMPLINKFLAGS= >> F_mex.mki
echo "EMC_COMPILER=Xcode with Clang" >> F_mex.mki
echo "EMC_CONFIG=optim" >> F_mex.mki
"/Applications/MATLAB_R2016a.app/bin/maci64/gmake" -B -f F_mex.mk
