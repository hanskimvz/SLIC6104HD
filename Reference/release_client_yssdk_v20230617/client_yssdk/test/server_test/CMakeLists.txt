#CMAKE_MINIMUM_REQUIRED(VERSION 3.5)

#LINK_DIRECTORIES(${CMAKE_LIBRARY_OUTPUT_DIRECTORY})
message("link_directories ${CMAKE_LIBRARY_OUTPUT_DIRECTORY}")
message("-- ${PROJECT_SOURCE_DIR}")

include_directories(${PROJECT_SOURCE_DIR}/include)

aux_source_directory(${PROJECT_SOURCE_DIR}/test/server_test FILES_DIR) # 指定源码目录

SET(TEST_YSSDK_SERVER ${LIB_YSSDK_SERVER}_test)
add_executable(${TEST_YSSDK_SERVER} ${FILES_DIR}) # 指定可执行文件名及源码

IF(WIN32)
	target_link_libraries(${TEST_YSSDK_SERVER} ${LIB_YSSDK_SERVER} ${LIB_MEDIASDK_EXT})
ELSE()
	target_link_libraries(${TEST_YSSDK_SERVER} ${LIB_YSSDK_SERVER} ${LIB_MEDIASDK_EXT} -lrt -ldl -lm -lpthread)
	# 链接外部库 # 链接外部库
ENDIF()

