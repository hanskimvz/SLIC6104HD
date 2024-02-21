#CMAKE_MINIMUM_REQUIRED(VERSION 3.5)

#LINK_DIRECTORIES(${CMAKE_LIBRARY_OUTPUT_DIRECTORY})
message("link_directories ${CMAKE_LIBRARY_OUTPUT_DIRECTORY}")
message("-- ${PROJECT_SOURCE_DIR}")

include_directories(${PROJECT_SOURCE_DIR}/include)

aux_source_directory(${PROJECT_SOURCE_DIR}/test/ptz_test FILES_DIR) # 指定源码目录

SET(TEST_ERP  ptz_test)
add_executable(${TEST_ERP} ${FILES_DIR}) # 指定可执行文件名及源码

IF(WIN32)
	target_link_libraries(${TEST_ERP} ${LIB_YSSDK_CLIENT} ${LIB_MEDIASDK_EXT} ${LIB_YSSDK_ERPCLIENT})
ELSE()
	target_link_libraries(${TEST_ERP} ${LIB_YSSDK_CLIENT} ${LIB_MEDIASDK_EXT} ${LIB_YSSDK_ERPCLIENT} -lrt -ldl -lm -lpthread)
	# 链接外部库 # 链接外部库
ENDIF()

