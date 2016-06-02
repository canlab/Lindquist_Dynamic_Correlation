MATLAB="/Applications/MATLAB_R2016a.app"
Arch=maci64
ENTRYPOINT=mexFunction
MAPFILE=$ENTRYPOINT'.map'
PREFDIR="/Users/xuyuting/.matlab/R2016a"
OPTSFILE_NAME="./setEnv.sh"
. $OPTSFILE_NAME
COMPILER=$CC
. $OPTSFILE_NAME
echo "# Make settings for G" > G_mex.mki
echo "CC=$CC" >> G_mex.mki
echo "CFLAGS=$CFLAGS" >> G_mex.mki
echo "CLIBS=$CLIBS" >> G_mex.mki
echo "COPTIMFLAGS=$COPTIMFLAGS" >> G_mex.mki
echo "CDEBUGFLAGS=$CDEBUGFLAGS" >> G_mex.mki
echo "CXX=$CXX" >> G_mex.mki
echo "CXXFLAGS=$CXXFLAGS" >> G_mex.mki
echo "CXXLIBS=$CXXLIBS" >> G_mex.mki
echo "CXXOPTIMFLAGS=$CXXOPTIMFLAGS" >> G_mex.mki
echo "CXXDEBUGFLAGS=$CXXDEBUGFLAGS" >> G_mex.mki
echo "LD=$LD" >> G_mex.mki
echo "LDFLAGS=$LDFLAGS" >> G_mex.mki
echo "LDOPTIMFLAGS=$LDOPTIMFLAGS" >> G_mex.mki
echo "LDDEBUGFLAGS=$LDDEBUGFLAGS" >> G_mex.mki
echo "Arch=$Arch" >> G_mex.mki
echo OMPFLAGS= >> G_mex.mki
echo OMPLINKFLAGS= >> G_mex.mki
echo "EMC_COMPILER=Xcode with Clang" >> G_mex.mki
echo "EMC_CONFIG=optim" >> G_mex.mki
"/Applications/MATLAB_R2016a.app/bin/maci64/gmake" -B -f G_mex.mk
