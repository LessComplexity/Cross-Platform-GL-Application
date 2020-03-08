//
// Created by lesscomplex on 08/03/2020.
//

#ifndef YOURAPPNAME_GLRENDERER_H
#define YOURAPPNAME_GLRENDERER_H

#include "definitions.h"

class GLShift::GLRenderer {
public:
    explicit GLRenderer(GLManager* context);
    virtual void render() = 0;
    virtual void init() = 0;
private:
    GLManager * context;
};

#endif //YOURAPPNAME_GLRENDERER_H
