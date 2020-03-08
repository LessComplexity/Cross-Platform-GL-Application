//
// Created by lesscomplex on 08/03/2020.
//

#include "GLManager.h"
#include "GLRenderer.h"
#include <iostream>

GLShift::GLManager::GLManager() {
    if(!glfwInit()) {
        std::cerr << "Couldn't initialize glfw context" << std::endl;
        delete this;
    }
}

GLShift::GLManager::GLManager(int major, int minor) {
    if(!glfwInit()) {
        std::cerr << "Couldn't initialize glfw context" << std::endl;
        delete this;
    }
    this->setVersion(major, minor);
}

void GLShift::GLManager::setVersion(int major, int minor) {
    this->major = major; this->minor = minor;
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, major);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, minor);
}

void GLShift::GLManager::openWindow(int width, int height, const char* title,bool isFullScreen) {
    this->window = glfwCreateWindow(width, height, title, isFullScreen ? glfwGetPrimaryMonitor() : NULL, NULL);
    glfwMakeContextCurrent(this->window);
    if(GLenum err = glewInit(); err != GLEW_OK) {
        std::cerr << glewGetErrorString(err) << std::endl;
        delete this->window;
        return;
    }
    glfwSwapInterval(1); // Allow VSync
}

void GLShift::GLManager::setRenderer(GLShift::GLRenderer *renderer) {
    this->renderer = renderer;
    // Call initialization function
    this->renderer->init();
}

void GLShift::GLManager::run() {
    if(this->renderer == nullptr) {
        std::cerr << "No renderer is defined!" << std::endl;
        return;
    }
    if(this->window == nullptr) {
        std::cerr << "No window is defined!" << std::endl;
        return;
    }

    while(!glfwWindowShouldClose(this->window)) {
        this->renderer->render();

        glClear(GL_COLOR_BUFFER_BIT);
        glfwSwapBuffers(this->window);
        glfwPollEvents();
    }
}

GLShift::GLManager::~GLManager() {
    if(this->window != nullptr) glfwDestroyWindow(this->window);
    glfwTerminate();
}
