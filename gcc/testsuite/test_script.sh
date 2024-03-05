export PREFIX="/home/syrmia/Desktop/Aleksandar/GNU_toolchain/install"
export SOURCE_DIR="/home/syrmia/Desktop/Aleksandar/GNU_toolchain/source"
export BUILD_DIR="/home/syrmia/Desktop/Aleksandar/GNU_toolchain/build"
export SYSROOT="/home/syrmia/Desktop/Aleksandar/GNU_toolchain/install/sys_root"
export PATH=$PREFIX/bin:$PATH
export TARGET=mips64-r6-linux-gnu


$PREFIX/bin/mips64-r6-linux-gnu-gcc fp_foo.c -O2 >out.txt -S -o fp_foo.s -march=mips64r6 -mabi=64

