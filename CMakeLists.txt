cmake_minimum_required(VERSION 3.20)
project(lab5_calc_graph CXX)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

if (CMAKE_CXX_COMPILER_ID MATCHES "GNU|Clang")
  add_compile_options(-Wall -Wextra -O2)
  set(THREADS_PREFER_PTHREAD_FLAG ON)
  find_package(Threads REQUIRED)
endif()

add_executable(lab5_calc_graph
  main.cpp
  calc_graph.cpp
)

if (CMAKE_CXX_COMPILER_ID MATCHES "GNU|Clang")
  target_link_libraries(lab5_calc_graph PRIVATE Threads::Threads)
endif()