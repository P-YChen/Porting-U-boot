#########################################################################
# File Name: cut.sh
# Author: shift
# mail: open_shift@163.com
# Created Time: 2016年03月25日 星期五 21时49分01秒
#########################################################################
#!/bin/bash

TOPDIR=.
pushd ${TOPDIR}/board/ && rm -rfv `ls | grep -v "samsung"` && popd
pushd ${TOPDIR}/board/samsung && rm -rfv `ls | grep -v "smdk2410"` && popd
pushd ${TOPDIR}/cpu/ && rm -rfv `ls | grep -v "arm920t"` && popd
pushd ${TOPDIR}/include/ && rm -rfv `ls | grep "asm-" | egrep -v "arm|generic"`&& popd
pushd ${TOPDIR}/include/asm-arm/ && rm -rfv `ls | grep "arch-" | grep -v "s3c24x0"` && popd
pushd ${TOPDIR}/include/configs/ && rm -rfv `ls | grep -v "smdk2410.h"` && popd
pushd ${TOPDIR} && rm -rfv `ls | grep "lib_" | egrep -v "arm|generic"` && popd
