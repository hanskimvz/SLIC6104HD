#! /bin/bash
SET PLATMAJOR=Windows
SET PLATMINOR=x64
SET PLATREVISE=
SET CROSS_CHAIN=

SET build_dir=x64-Debug

rd /s /q ..\out
del ..\CompChain.cmake

echo MESSAGE("***********************************************") >> ../CompChain.cmake
echo MESSAGE("         Build With Windows Platform           ") >> ../CompChain.cmake
echo MESSAGE("***********************************************") >> ../CompChain.cmake

echo set(PLATMAJOR %PLATMAJOR%) >> ../CompChain.cmake
echo set(PLATMINOR %PLATMINOR%) >> ../CompChain.cmake

del ..\PlatformCfg.cmake

echo add_definitions(-DUSE_OPT_OS_WIN) >> ..\PlatformCfg.cmake
echo add_definitions(-D_CRT_SECURE_NO_WARNINGS) >> ..\PlatformCfg.cmake
rem echo set(LIBRARY_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/lib/${PLATFORM}/${PLATMINOR}) >> ..\PlatformCfg.cmake

del ..\%build_dir% /s /q /f
mkdir ..\%build_dir%
cd ../%build_dir%

cmake -G "Visual Studio 15 2017" -DCMAKE_BUILD_TYPE=Dubug -A x64 ..

rem msbuild YSSDK.sln /p:Configuration=Debug
rem pause
