//
// Created by lesscomplex on 08/03/2020.
//

#ifndef YOURAPPNAME_GLRENDERER_H
#define YOURAPPNAME_GLRENDERER_H

#include "definitions.h"

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
    void setWindow(GLFWwindow * context);
private:
    GLFWwindow * window;
};

#endif //YOURAPPNAME_GLRENDERER_H
