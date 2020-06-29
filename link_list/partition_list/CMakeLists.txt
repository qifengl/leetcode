cmake_minimum_required(VERSION 3.3)

set(CMAKE_CXX_STANDARD 11)

PROJECT(list-partition)

set(PROJECT_BINARY_DIR ${PROJECT_SOURCE_DIR}/build)
SET(CMAKE_BUILD_TYPE Debug)
set(APP_DIR ${PROJECT_SOURCE_DIR}/app)
set(BASE_DIR ${PROJECT_SOURCE_DIR}/base)

include_directories("${BASE_DIR}/include")
ADD_EXECUTABLE(${PROJECT_NAME} "${APP_DIR}/list_partition.cpp" "${BASE_DIR}/src/Solution.cpp")
