cmake_minimum_required(VERSION 3.2)

project(Bignum)

set(CMAKE_CXX_STANDARD 14)

add_subdirectory(${PROJECT_SOURCE_DIR}/libBignum)
include_directories(${BIGNUM_INCLUDE})

add_executable(BignumTest ${PROJECT_SOURCE_DIR}/test.cpp)
target_link_libraries(BignumTest Bignum)
