#! /bin/bash

PLATMAJOR=Ubuntu
PLATMINOR=x86
PLATREVISE=
CROSS_CHAIN=

# 检查编译链是否有安装, 检索版权信息中的Copyright字眼
COPYRIGHT_FLG=$(gcc --version | grep "Copyright")

if [ -z "${COPYRIGHT_FLG}" ]
then
    echo "-- Fail!!!"
    echo "   You Need Install gcc compiliation chain"
    echo "   !!!!!!!!!!!Exit!!!!!!!!!"
else
    if test -d ../build
    then
        rm ../build/* -rf
    else
        mkdir ../build
    fi

    if test -e ../CompChain.cmake
    then
        rm ../CompChain.cmake
    fi

    if test -e ../PlatformCfg.cmake
    then
        rm ../PlatformCfg.cmake
    fi

    echo 'MESSAGE("***********************************************")' >> ../CompChain.cmake
    echo 'MESSAGE("       Build With Ubuntu  x86  Platform        ")' >> ../CompChain.cmake
    echo 'MESSAGE("***********************************************")' >> ../CompChain.cmake

    echo "set(CMAKE_C_STANDARD 99)" >> ../CompChain.cmake
    echo "set(PLATMAJOR ${PLATMAJOR})" >> ../CompChain.cmake
    echo "if(CMAKE_SIZEOF_VOID_P EQUAL 8)" >> ../CompChain.cmake
    echo "  set(PLATMINOR x64)" >> ../CompChain.cmake
    echo "else()" >> ../CompChain.cmake
    echo "  set(PLATMINOR x86)" >> ../CompChain.cmake
    echo "endif()" >> ../CompChain.cmake  

    echo "#empter" >>  ../PlatformCfg.cmake
fi

cd ../build && cmake .. && make
