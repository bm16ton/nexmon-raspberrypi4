#!/bin/bash
LD_LIBRARY_PATH=$NEXMON_ROOT/arm32/libs $NEXMON_ROOT/arm32/libs/ld-2.31.so $NEXMON_ROOT/buildtools/gcc-arm-none-eabi-5_4-2016q2-linux-armv7l/bin/arm-none-eabi-objdump -j $1 -t $2 | sed -e '5q;d' | awk '{ print $1; }'
