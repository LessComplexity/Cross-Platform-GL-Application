#include "glshift/GLShift.h"

class MyRenderer : public GLShift::GLRenderer {
    using GLShift::GLRenderer::GLRenderer; // Import constructor
public:
    void render() override {
        glClearColor(1, 0, 0, 1);
    }

    void init() override {}
};

int main() {
    GLShift::GLManager glManager = GLShift::GLManager();
    glManager.openWindow(600, 300, "Yeahh!");
    glManager.setRenderer(new MyRenderer(&glManager));
    glManager.run();
    return 0;
}
