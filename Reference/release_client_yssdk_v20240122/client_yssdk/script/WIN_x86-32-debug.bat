#! /bin/bash
SET PLATMAJOR=Windows
SET PLATMINOR=x86
SET PLATREVISE=
SET CROSS_CHAIN=

SET build_dir=x86-Debug

rd /s /q ..\out
mkdir ..\%build_dir%
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

cmake -G "Visual Studio 15 2017" -DCMAKE_BUILD_TYPE=Debug -A Win32 ..

rem msbuild YSSDK.sln /p:Configuration=Debug
rem pause
