cmake_minimum_required(VERSION 3.22.1)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_SKIP_RPATH ON)
set(CMAKE_SKIP_RPATH ON CACHE BOOL "Skip RPATH" FORCE)
set(PROJECT_NAME "twisted-reality")

project(${PROJECT_NAME})
add_executable(
    ${PROJECT_NAME}
    Source/Main.cpp
    Source/Game.cpp
)

find_package(SDL2 2.28.2 EXACT REQUIRED)
find_package(SDL2_image REQUIRED)

include_directories(${SDL2_INCLUDE_DIRS})
target_link_libraries(${PROJECT_NAME} ${SDL2_LIBRARIES} SDL2_image::SDL2_image)