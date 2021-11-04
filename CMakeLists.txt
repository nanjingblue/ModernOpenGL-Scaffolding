cmake_minimum_required(VERSION 3.20)
project(ModernOpenGL)

set(CMAKE_CXX_STANDARD 14)
set(DEPENDENCIES ${CMAKE_SOURCE_DIR}/dependencies)
set(SOURCE_DIR ${CMAKE_SOURCE_DIR}/src)
set(LIB_DIR ${DEPENDENCIES}/GLFW/lib-mingw-w64)

include_directories(${DEPENDENCIES}/GLFW/include)
include_directories(${DEPENDENCIES}/GLAD/include)
link_libraries(${DEPENDENCIES}/GLFW/lib-mingw-w64)
link_libraries(${DEPENDENCIES}/GLFW/lib-vc2019)

add_executable(ModernOpenGL WIN32 ${SOURCE_DIR}/main.cpp ${SOURCE_DIR}/glad.c)
target_link_libraries(ModernOpenGL ${LIB_DIR}/libglfw3.a)
