cmake_minimum_required(VERSION 3.13)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_SHARED_LINKER_FLAGS}")
set(CMAKE_STATIC_LINKER_FLAGS "${CMAKE_STATIC_LINKER_FLAGS}")

add_executable(
    mlox
    main.cpp
    chunk.cpp
    debug.cpp
    value.cpp
)

target_include_directories(mlox PRIVATE .)
