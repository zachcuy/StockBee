cmake_minimum_required(VERSION 3.0.0)
project(ScreenerAPI VERSION 0.1.0)

include(CTest)
enable_testing()

find_package(CURL CONFIG REQUIRED)

include_directories(${CMAKE_SOURCE_DIR}/include)
include_directories(${CMAKE_SOURCE_DIR}/curl)

file(GLOB SRCS src/*.cpp main.cpp)

add_executable(ScreenerAPI ${SRCS})

target_link_libraries(ScreenerAPI PRIVATE CURL::libcurl)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
