cmake_minimum_required(VERSION 3.12.0)

#set PROJECT_NAME and version
project(testLog)
set(VERSION_MAJOR 0)
set(VERSION_MINOR 0)
set(VERSION_PATCH 1)


file(GLOB SOURCE_FILE *.cpp)
file(GLOB HEAD_FILE *.h)

set(log4cplus_DIR ${PROJECT_SOURCE_DIR}/lib/log4cplus/lib/cmake/log4cplus)
find_package(log4cplus REQUIRED)
if(log4cplus_FOUND)
	message("found log4cplus ")
endif()

#include_directories(${PROJECT_SOURCE_DIR}/lib/log4cplus/include)
#set(log4cplus_LIBRARY ${PROJECT_SOURCE_DIR}/lib/log4cplus/lib/log4cplusU.lib)

set(project_headers
	${HEAD_FILE})

set(project_sources
	${SOURCE_FILE})

add_executable(${PROJECT_NAME} ${project_headers} ${project_sources})
	
#target_link_libraries(${PROJECT_NAME} ${log4cplus_LIBRARY})

target_link_libraries(${PROJECT_NAME} log4cplus::log4cplusU)

set(CMAKE_INSTALL_PREFIX ${PROJECT_BINARY_DIR}/installed)

install(TARGETS ${PROJECT_NAME} DESTINATION /)

install(FILES ${PROJECT_SOURCE_DIR}/Mylog.conf DESTINATION /)
install(FILES ${PROJECT_SOURCE_DIR}/lib/log4cplus/bin/log4cplusU.dll DESTINATION .)
