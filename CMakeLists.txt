
cmake_minimum_required(VERSION 3.10)
cmake_policy(SET CMP0076 NEW)

project(NAARD)

add_library(NAARD SHARED)
add_subdirectory(src)
target_include_directories(NAARD PUBLIC include/)
target_include_directories(NAARD PUBLIC /usr/include/c++/9/)

add_executable(NAARD_TESTS)
add_subdirectory(tests)
target_link_libraries(NAARD_TESTS NAARD)