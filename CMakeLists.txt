cmake_minimum_required(VERSION 3.15)

# For convenience you can put your application name here
set(APP_NAME YourAppName)
project(${APP_NAME} LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)

# Set to x86 for x86 architecture or x64 for x64 architecture
set(ARCHITECTURE_TO_USE x64)
# Add GLEW/GLFW/glm includes
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include)

# Make the executable
add_executable(${APP_NAME} main.cpp
        # Helper namespace and object to make your life easier
        glshift/GLManager.cpp
        glshift/GLManager.h
        glshift/GLShift.h
        glshift/definitions.h
        glshift/GLRenderer.h
        glshift/GLRenderer.cpp)

# Linking libraries for windows/linux
# TODO: add mac support
if(WIN32)
    # Neccessary variables
    SET(LINK_GL_LIBS ${CMAKE_SOURCE_DIR}/lib/win/${ARCHITECTURE_TO_USE})
    set(GLEW_SHARED_LIB ${LINK_GL_LIBS}/glew32.dll)
    set(GLEW_STATIC_LIB ${LINK_GL_LIBS}/glew32.lib)
    set(GLFW_STATIC_LIB  ${LINK_GL_LIBS}/glfw3.lib)
    # Copy the GLEW static lib
    file(COPY ${GLEW_SHARED_LIB} DESTINATION ${CMAKE_BINARY_DIR}/)
    find_package(OpenGL REQUIRED)
    # Link libs
    target_link_libraries(${APP_NAME} ${OPENGL_LIBRARIES} ${GLEW_STATIC_LIB} ${GLFW_STATIC_LIB})
else()
    SET(LINK_GL_LIBS ${CMAKE_SOURCE_DIR}/lib/linux)
    set(GLFW_STATIC_LIB  ${LINK_GL_LIBS}/libglfw3.a)
    set(GLEW_STATIC_LIB  ${LINK_GL_LIBS}/libGLEW.a)
    set(GLEW_SHARED_LIB  ${LINK_GL_LIBS}/libGLEW.so.2.1)

    # Link linux dependencies
    find_package(X11 REQUIRED)
    find_package(Threads REQUIRED)
    find_package(OpenGL REQUIRED)
    include_directories(${X11_INCLUDE_DIR})
    target_link_libraries(${APP_NAME}
            ${OPENGL_LIBRARIES}
            ${GLEW_SHARED_LIB}
            #${GLEW_STATIC_LIB}
            ${GLFW_STATIC_LIB}
            Threads::Threads
            ${X11_LIBRARIES}
            ${CMAKE_DL_LIBS})
endif()