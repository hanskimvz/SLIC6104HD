rem rem ����SDK��32λ�汾
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

rem ����SDK��64λ�汾
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