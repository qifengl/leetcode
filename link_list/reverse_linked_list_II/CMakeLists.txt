cmake_minimum_required(VERSION 3.3)

set(CMAKE_CXX_STANDARD 11)

PROJECT(reverseLinkedListII)

set(PROJECT_BINARY_DIR ${PROJECT_SOURCE_DIR}/build)
SET(CMAKE_BUILD_TYPE Debug)
set(APP_DIR ${PROJECT_SOURCE_DIR}/app)
set(BASE_DIR ${PROJECT_SOURCE_DIR}/base)

include_directories("${BASE_DIR}/include")
ADD_EXECUTABLE(${PROJECT_NAME} "${APP_DIR}/reverse_linked_list_2.cpp" "${BASE_DIR}/src/Solution.cpp")
