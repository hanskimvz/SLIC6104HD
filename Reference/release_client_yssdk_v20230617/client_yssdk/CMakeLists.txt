CMAKE_MINIMUM_REQUIRED(VERSION 3.5)

MESSAGE("+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++")
MESSAGE("|                        Build protoc yssdk                         |")
MESSAGE("+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++")

INCLUDE(CompChain.cmake) 

SET(PRO_NAME "yssdk_test")

# 配置整体项目的全局参数
PROJECT(${PRO_NAME} VERSION 1.0.0.1 LANGUAGES CXX C)

# 配置windows下 MSVC的CMake参数
IF(MSVC)
    message("== Into MSVC")
    add_definitions(-D_CRT_SECURE_NO_WARNINGS -DWIN32_LEAN_AND_MEAN)
    add_compile_options(-DOS_WINDOWS)
    add_compile_options(/wd4819)
    add_compile_options(/wd4018)
    add_compile_options(/wd4267)
    #set(CMAKE_SHARED_LINKER_FLAGS_RELEASE "/INCREMENTAL:NO")
    # 添加win系列的
    include_directories(${PROJECT_SOURCE_DIR}/include/win32)
ENDIF()

IF ("${PLATMAJOR}" STREQUAL "Windows")
    SET(PLATFORM "${PLATMAJOR}")
    SET(PLATFORM_NAME "${PLATMAJOR}")

if ((CMAKE_BUILD_TYPE STREQUAL "Debug"))
    string(APPEND BUILD_DIR "/Debug")
else ()
   string(APPEND BUILD_DIR "/Release")
endif ()

ELSE()
    SET(PLATFORM "${PLATMAJOR}")
    SET(PLATFORM_NAME "${PLATMAJOR}")
    add_compile_options(-Os -fPIC)
    add_definitions(-DOS_LINUX -D_GNU_SOURCE)
ENDIF()

# 设置库输出目录(包含动态库和静态库)
set(LIBRARY_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/lib/${PLATFORM}/${PLATMINOR})

# 指定可执行文件的存放目录
set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin/${PLATFORM}/${PLATMINOR})

# 附加库路径
link_directories(${PROJECT_SOURCE_DIR}/lib/${PLATFORM}/${PLATMINOR})

# 添加libclient_yssdk 库头文件与源文件
SET(LIB_YSSDK_CLIENT_DIR ${PROJECT_SOURCE_DIR}/lib)
INCLUDE_DIRECTORIES(${PROJECT_SOURCE_DIR}/include)

FIND_LIBRARY(LIB_YSSDK_CLIENT_LIBRARY NAMES yssdk_client 
	HINTS ${PROJECT_SOURCE_DIR}/lib/${PLATFORM}/${PLATMINOR}/${BUILD_DIR})
	
SET(LIB_YSSDK_CLIENT ${LIB_YSSDK_CLIENT_LIBRARY})


## 编译子项目test
add_subdirectory(${PROJECT_SOURCE_DIR}/test/client_test)

