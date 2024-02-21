rem rem 编译SDK的32位版本
set PROJECT_NAME=yssdk_test
set CUR_PATH=%~dp0 
cd %CUR_PATH%
cd .\script\
call WIN_x86-32-debug.bat
msbuild %PROJECT_NAME%.sln /p:Configuration=Debug
cd %CUR_PATH%

cd %CUR_PATH%
cd .\script\
call WIN_x86-32-release.bat
msbuild %PROJECT_NAME%.sln /p:Configuration=Release
cd %CUR_PATH%

rem 编译SDK的64位版本
cd %CUR_PATH%
cd .\script\
call WIN_x86-64-debug.bat
msbuild %PROJECT_NAME%.sln /p:Configuration=Debug
cd %CUR_PATH%

cd %CUR_PATH%
cd .\script\
call WIN_x86-64-release.bat
msbuild %PROJECT_NAME%.sln /p:Configuration=Release
cd %CUR_PATH%

pause