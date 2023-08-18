cmake_minimum_required(VERSION 3.12)
project(myvector)

set(CMAKE_CXX_STANDARD 11)

add_executable(main main.cpp)

add_subdirectory(src)

include_directories(include)

target_link_libraries(main PRIVATE vector)
