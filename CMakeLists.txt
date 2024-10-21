cmake_minimum_required(VERSION 3.30)
project(RevString)
add_executable(${PROJECT_NAME} RevStrArrStack.c)
add_library(scan SHARED src/scan.c)

target_link_libraries(${PROJECT_NAME} scan)