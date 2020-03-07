cmake_minimum_required(VERSION 3.15)

# For convenience you can put your application name here
set(APP_NAME YourAppName)
project(${APP_NAME} LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)

# Change this variable to `linux` to compile for linux
set(COMPILE_PLATFORM win)
# Uncomment the following line to compile for x86 architecture (32bit)
# set(USE_X86 TRUE)

if (USE_X86)
    SET(LINK_GL_LIBS ${CMAKE_SOURCE_DIR}/lib/${COMPILE_PLATFORM}/x86)
    file(COPY ${CMAKE_SOURCE_DIR}/bin/${COMPILE_PLATFORM}/x86/glew32.dll DESTINATION ${CMAKE_BINARY_DIR}/)
else()
    SET(LINK_GL_LIBS ${CMAKE_SOURCE_DIR}/lib/${COMPILE_PLATFORM}/x64)
    file(COPY ${CMAKE_SOURCE_DIR}/bin/${COMPILE_PLATFORM}/x64/glew32.dll DESTINATION ${CMAKE_BINARY_DIR}/)
endif ()

find_package(OpenGL)
add_executable(${APP_NAME} main.cpp)
target_link_libraries(${APP_NAME} ${OPENGL_gl_LIBRARY} ${LINK_GL_LIBS}/glfw3.lib ${LINK_GL_LIBS}/glew32.lib)