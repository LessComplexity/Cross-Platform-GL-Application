//
// Created by lesscomplex on 08/03/2020.
//

#include "GLRenderer.h"
#include <iostream>
#include <sstream>
#include <fstream>

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

void GLShift::GLRenderer::addShader(const std::string& programName, const char *shaderSource, GLint shader_type, bool isFile) {
    GLuint vShader = glCreateShader(shader_type);
    std::string data = "";
    // Get source from file
    if(isFile) {
        std::ifstream file(shaderSource, std::ios::in);
        std::string line;
        while(!file.eof()) {
            std::getline(file, line);
            data.append(line + "\n");
        }
        shaderSource = data.c_str();
    }

    glShaderSource(vShader, 1, &shaderSource, nullptr);
    glCompileShader(vShader);
    bool verified = this->verify(vShader);
    if(!verified) std::cout << "Shader compilation error!" << std::endl;
    glAttachShader(this->glPrograms[programName], vShader);
}

void GLShift::GLRenderer::linkProgram(const std::string& name) {
    if(this->glPrograms.count(name) == 0) {
        std::cerr << "Program doesn't exist!" << std::endl;
        return;
    }

    glLinkProgram(this->glPrograms[name]);
    bool verified = this->verify(this->glPrograms[name], true);
}

void GLShift::GLRenderer::useProgram(const std::string &name) {
    if(this->glPrograms.count(name) == 0) {
        std::cerr << "Program doesn't exist!" << std::endl;
        return;
    }

    glUseProgram(this->glPrograms[name]);
}

bool GLShift::GLRenderer::verify(GLint element, bool isProgram) {
    bool verificationSuccessful = true;

    // Check for general OpenGL errors
    int glError = glGetError();
    if(glError != GL_NO_ERROR) std::cout << "OpenGL errors found: ";
    while(glError != GL_NO_ERROR) {
        verificationSuccessful = false;
        std::cout << glError << " ";
        glError = glGetError();
    }
    std::cout << std::endl;

    // Get shader status of compilation
    GLint status;
    if(isProgram) glGetShaderiv(element, GL_LINK_STATUS, &status);
    else glGetShaderiv(element, GL_COMPILE_STATUS, &status);

    if(status != 1) {
        verificationSuccessful = false;
        // Determine information length
        int infoLen, charWritten;
        if(isProgram) glGetProgramiv(element, GL_INFO_LOG_LENGTH, &infoLen);
        else glGetShaderiv(element, GL_INFO_LOG_LENGTH, &infoLen);
        // Print log if present
        if(infoLen <= 0) return false;
        char* logData = new char[infoLen];
        if(isProgram) {
            glGetProgramInfoLog(element, infoLen, &charWritten, logData);
            std::cout << "Program";
        }
        else {
            glGetShaderInfoLog(element, infoLen, &charWritten, logData);
            std::cout << "Shader";
        }
        std::cout << " Log: " << logData << "\n";
        delete[] logData;
    }

    return verificationSuccessful;
}