cmake_minimum_required(VERSION 3.10.0)
project(cmake_hello_window VERSION 0.1.0)

add_executable(${CMAKE_PROJECT_NAME} main.cpp)

include_directories(headers)

set(GLFW_BUILD_DOCS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_TESTS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)

add_subdirectory(libs/glfw-3.3.8)

target_link_libraries(${CMAKE_PROJECT_NAME} PRIVATE glfw)

add_subdirectory(libs/glad)

target_link_libraries(${CMAKE_PROJECT_NAME} PRIVATE glad)

add_subdirectory(libs/glm)

target_link_libraries(${CMAKE_PROJECT_NAME} PRIVATE glm::glm)