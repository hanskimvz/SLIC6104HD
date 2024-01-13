#! /bin/bash
PLATMAJOR=ARM
PLATMINOR=arm-hisiv500
PLATREVISE=v500
CROSS_CHAIN=arm-hisiv500-linux-

rm ../build/* -rf
rm ../CompChain.cmake
rm ../PlatformCfg.cmake

# 检查编译链是否有安装, 检索版权信息中的Copyright字眼
COPYRIGHT_FLG=$(${CROSS_CHAIN}gcc --version | grep "Copyright")

if [ -z "${COPYRIGHT_FLG}" ]
then
    echo "-- Fail!!! ${CROSS_CHAIN}gcc --version | grep \"Copyright\" = ${COPYRIGHT_FLG}"
    echo "   You Need Install arm-hisiv500-linux Cross-compiliation chain"
    echo "   !!!!!!!!!!!Exit!!!!!!!!!"
else


    echo 'MESSAGE("***********************************************")' >> ../CompChain.cmake
    echo 'MESSAGE("       Build With ARM_HISI_v500 Platform       ")' >> ../CompChain.cmake
    echo 'MESSAGE("***********************************************")' >> ../CompChain.cmake

    echo "set(CMAKE_C_COMPILER   ${CROSS_CHAIN}gcc)" >> ../CompChain.cmake
    echo "set(CMAKE_CXX_COMPILER ${CROSS_CHAIN}g++)" >> ../CompChain.cmake
    echo "set(CMAKE_C_STANDARD 99)" >> ../CompChain.cmake
    echo "set(PLATMAJOR ${PLATMAJOR})" >> ../CompChain.cmake
    echo "set(PLATMINOR ${PLATMINOR})" >> ../CompChain.cmake
    echo "set(PLATREVISE ${PLATREVISE})" >> ../CompChain.cmake
    echo "set(CROSS_CHAIN ${CROSS_CHAIN})" >> ../CompChain.cmake

    echo "#empter" >>  ../PlatformCfg.cmake     
fi

cd ../build
cmake ..  && make
