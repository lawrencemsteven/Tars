cmake_minimum_required(VERSION 3.15)
enable_testing()

include(cmake/warnings.cmake)

project(Tars)

find_package(Catch2 REQUIRED)
find_package(Vulkan REQUIRED)
find_package(glm REQUIRED)
find_package(glfw3 REQUIRED)

add_subdirectory("Tars")
add_subdirectory("TarsApp")