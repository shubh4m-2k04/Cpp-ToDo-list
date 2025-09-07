
cmake_minimum_required(VERSION 3.28.3)
project(TodoApp CXX)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

file(GLOB SOURCE_FILES "src/*.cpp")

include(FetchContent)

FetchContent_Declare(
    nlohmann_json
    GIT_REPOSITORY https://github.com/nlohmann/json.git
    GIT_TAG        v3.11.3 # Use a specific, stable version
)


FetchContent_MakeAvailable(nlohmann_json)

add_executable(todo_app ${SOURCE_FILES})
target_include_directories(todo_app PRIVATE include)
target_link_libraries(todo_app PRIVATE nlohmann_json::nlohmann_json)
