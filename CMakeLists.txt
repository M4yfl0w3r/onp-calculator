cmake_minimum_required(VERSION 3.13)

project(onp)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_FLAGS "-Wall")

add_library(onp STATIC
  src/onp.cpp
  src/stack.cpp
)

add_executable(onp_run src/main.cpp)
target_link_libraries(onp_run onp)
