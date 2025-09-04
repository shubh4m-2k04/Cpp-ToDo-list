
cmake_minimum_required(VERSION 3.10)
project(TodoApp CXX)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

file(GLOB SOURCE_FILES "src/*.cpp")

add_executable(todo_app ${SOURCE_FILES})
target_include_directories(todo_app PRIVATE include)
