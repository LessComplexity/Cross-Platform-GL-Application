//
// Created by lesscomplex on 08/03/2020.
//

#ifndef YOURAPPNAME_GLMANAGER_H
#define YOURAPPNAME_GLMANAGER_H

#include "definitions.h"

class GLShift::GLManager {
public:
    GLManager();
    ~GLManager();
    GLManager(signed int major, signed int minor);

    void setVersion(signed int major, signed int minor);
    void setRenderer(GLRenderer * renderer);
    void openWindow(signed int width, signed int height, const char* title, bool isFullScreen = false);
    void run();
private:
    GLFWwindow *window;
    GLRenderer *renderer;
    signed int major, minor;
};


#endif //YOURAPPNAME_GLMANAGER_H
