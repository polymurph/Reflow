cmake_minimum_required(VERSION 3.13.4)

# path definitions
set(BSL_DIR ${CMAKE_SOURCE_DIR}/bsl/)



project(reflow)

add_executable(${PROJECT_NAME} main.cpp)

add_subdirectory(${PROJECT_SOURCE_DIR}bsl)

# adding boatdsupport layer
add_subdirectory(bsl)