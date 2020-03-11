//
// Created by lesscomplex on 08/03/2020.
//

#ifndef YOURAPPNAME_GLRENDERER_H
#define YOURAPPNAME_GLRENDERER_H

#include "definitions.h"
#include <unordered_map>

class GLShift::GLRenderer {
public:
    /**
     * Override to provide code for the rendering loop
     */
    virtual void render() = 0;
    /**
     * Override to provide code for the initialization loop
     */
    virtual void init() = 0;
    /**
     * Set the window that the render applies to
     * @param context
     */
    void setWindow(GLFWwindow * context);
    /**
     * Create and store an empty program in the renderer
     * @param name Name to reference to the program
     */
    void createProgram(const std::string& name);
    /**
     * Link the shaders given to the programs to make it complete
     * @param name Name of program to link
     */
    void linkProgram(const std::string& name);
    /**
     * Add a shader to a program
     * @param programName Program name to add to
     * @param shaderSource Source code of the shader
     * @param shader_type Shader type
     * @param isFile Set T for loading a file, or F for loading from code
     */
    void addShader(const std::string& programName, const char* shaderSource, GLint shader_type = GL_VERTEX_SHADER, bool isFile = true);
    /**
     * A safe function to call programs.
     * Newbies might use the command line `glUseProgram(this->glPrograms["name"])`.
     * The main problem is that if the program with the key "name" doesn't exists,
     * then it will be created, thus you will get en error. This functions checks
     * if the key exists before proceeding to use the program to avoid errors
     * @param name Name of the program to load
     */
    void useProgram(const std::string& name);
private:
    /**
     * Checks for errors in OpenGL environment
     * @param element If an element is specified then this function checks for errors in element.
     * @param isProgram Set to true to validate a program, and false for a shader
     * @return verification status
     */
    bool verify(GLint element = -1, bool isProgram = false);
protected:
    std::unordered_map<std::string, GLuint> glPrograms;
    GLFWwindow * window;
};

#endif //YOURAPPNAME_GLRENDERER_H
