//
// Created by lesscomplex on 08/03/2020.
//

#include "GLRenderer.h"
#include <iostream>

void GLShift::GLRenderer::setWindow(GLFWwindow * context) {
    this->window = context;
}

void GLShift::GLRenderer::createProgram(const std::string& name) {
    if(this->glPrograms.count(name) > 0) {
        std::cerr << "Program already exists." << std::endl;
        return;
    }

    this->glPrograms[name] = glCreateProgram();
}

void GLShift::GLRenderer::addShader(const std::string& programName, const char *shaderSource, GLint shader_type) {
    GLuint vShader = glCreateShader(shader_type);
    glShaderSource(vShader, 1, &shaderSource, nullptr);
    glCompileShader(vShader);
    glAttachShader(this->glPrograms[programName], vShader);
}

void GLShift::GLRenderer::linkProgram(const std::string& name) {
    if(this->glPrograms.count(name) == 0) {
        std::cerr << "Program doesn't exist!" << std::endl;
        return;
    }

    glLinkProgram(this->glPrograms[name]);
}

void GLShift::GLRenderer::useProgram(const std::string &name) {
    if(this->glPrograms.count(name) == 0) {
        std::cerr << "Program doesn't exist!" << std::endl;
        return;
    }

    glUseProgram(this->glPrograms[name]);
}
