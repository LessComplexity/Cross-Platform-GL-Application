//
// Created by lesscomplex on 08/03/2020.
//

#ifndef YOURAPPNAME_GLMANAGER_H
#define YOURAPPNAME_GLMANAGER_H

#include "definitions.h"

class GLShift::GLManager {
public:
    /**
     * Initializes the GLFW environment
     */
    GLManager();
    /**
     * Initializes the GLFW environment & sets the specific version
     * of OpenGL to use
     * @param major
     * @param minor
     */
    GLManager(unsigned int major, unsigned int minor);
    /**
     * Terminated the GLFW environment
     */
    ~GLManager();

    /**
     * Sets the version of OpenGL to use
     * @param major
     * @param minor
     */
    void setVersion(unsigned int major, unsigned int minor);
    /**
     * Sets the renderer object to use for rendering on the window
     * @param renderer
     */
    void setRenderer(GLRenderer * renderer);
    /**
     * Opens a window with GLFW context
     * @param width
     * @param height
     * @param title
     * @param isFullScreen Set true to make full screen app
     */
    void openWindow(unsigned int width, unsigned int height, const char* title, bool isFullScreen = false);
    void run();
private:
    GLFWwindow *window;
    GLRenderer *renderer;
    unsigned int major, minor;
};


#endif //YOURAPPNAME_GLMANAGER_H
