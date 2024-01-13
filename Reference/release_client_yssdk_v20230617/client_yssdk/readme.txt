
一  windows vs2017编译
1）安装好vs2017版本编译器
2）安装好msbuild工具
3）进入script目录双击 WIN_x86-32-debug.bat 脚本
4）编译生成x86-Debug的工程文件
5）进入x86-Debug目录双击打开yssdk_test.sln的工程文件
6）进行vs2017编译
7）最后编译出yssdk_client_test.exe测试文件可以正常跑看打印信息

二 ubuntu环境编译
1）文件目录下载到ubuntu文件目录下
2）进入script文件目录
3）修改权限 chmod 777 UBUNTU_x86.sh 
4）执行 ./UBUNTU_x86.sh 编译生成  bin/Ubuntu/x86/yssdk_client_test 文件
5）可执行../bin/Ubuntu/x86/yssdk_client_test 文件

二 fh-arm 环境编译
1）文件目录下载到ubuntu文件目录下
2）进入script文件目录
3）修改权限 chmod 777 ARM_FH_V200.sh
4）执行 ./ARM_FH_V200.sh 编译生成  bin/ARM_FH_V200/x86/yssdk_client_test 文件
5）可执行../bin/ARM_FH_V200/x86/yssdk_client_test 文件
