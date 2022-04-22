include_directories(${PROJECT_SOURCE_DIR})
get_property(include_dir DIRECTORY ${PROJECT_SOURCE_DIR} PROPERTY INCLUDE_DIRECTORIES)
set(BIGNUM_INCLUDE ${include_dir} PARENT_SCOPE)

add_library(Bignum SHARED ./src/Bignum.cpp)
