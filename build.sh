#!/bin/bash

LOCAL_DIR=`pwd`
export PATH="$PATH:/home/dante/Android/GPE-Remixed/prebuilts/gcc/linux-x86/aarch64/aarch64-linux-android-4.9/bin/"
export CROSS_COMPILE="aarch64-linux-android-"
mkdir -p out
echo "Paths and Toolchain loaded!"
make ARCH=arm64 O=out hisi_hi6210sft_defconfig
make ARCH=arm64 O=out -j8
