cmake_minimum_required(VERSION 3.16)


set(FLAGS -std=c++17 -O3 -Wall)
set(CMAKE_CXX_COMPILER g++)

add_compile_options(${FLAGS})

project(DRZEWA_CPP VERSION 0.11 LANGUAGES CXX)

file(GLOB_RECURSE SRC ${CMAKE_SOURCE_DIR}/source/*.cpp)

find_package(GTest REQUIRED)

add_subdirectory(${CMAKE_SOURCE_DIR}/lib)

add_executable(program main.cpp)
add_executable(runBSTTests tests/test_BST.cpp)
add_executable(runAVLTests tests/test_AVL.cpp)
target_include_directories(program PUBLIC BEFORE ${CMAKE_SOURCE_DIR}/Include)
target_include_directories(runBSTTests PUBLIC BEFORE ${CMAKE_SOURCE_DIR}/Include)
target_include_directories(runAVLTests PUBLIC BEFORE ${CMAKE_SOURCE_DIR}/Include)

target_link_libraries(program PUBLIC trees)
target_link_libraries(runBSTTests ${GTEST_LIBRARIES} pthread trees)
target_link_libraries(runAVLTests ${GTEST_LIBRARIES} pthread trees)