#include "glshift/GLShift.h"

/**
 * Example for a renderer implementation
 */
class MyRenderer : public GLShift::GLRenderer {
public:
    void render() override {
        glClearColor(1, 0, 0, 1);
    }

    void init() override {}
};

int main() {
    /**
     * Example for a GLManager implementation
     */
    GLShift::GLManager glManager = GLShift::GLManager();
    glManager.openWindow(600, 300, "Yeahh!");
    glManager.setRenderer(new MyRenderer());
    glManager.run();
    return 0;
}
