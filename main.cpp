#include "glshift/GLShift.h"

#define numVAOs 3

/**
 * Example for a renderer implementation
 */
class MyRenderer : public GLShift::GLRenderer {
public:
    void render() override {
        glClearColor(1.0, 0.0, 0.0, 1.0);
        glClear(GL_COLOR_BUFFER_BIT);

        // Rather use this function instead of glUseProgram
        // Since it checks for availability of the program
        this->useProgram("main");
        glDrawArrays(GL_TRIANGLES, 0, 3);
    }

    void init() override {
        // Example for creating and linking a shader pipeline
        this->createProgram("main");
        this->addShader("main", "../shaders/simple_vertex.glsl", GL_VERTEX_SHADER);
        this->addShader("main", "../shaders/simple_fragment.glsl", GL_FRAGMENT_SHADER);
        this->linkProgram("main");

        // Just a point
        glGenVertexArrays(numVAOs, this->vao);
        glBindVertexArray(vao[0]);
    }

private:
    GLuint vao[numVAOs];
};

int main() {
    /*
     * Example for a GLManager implementation
     */
    GLShift::GLManager glManager = GLShift::GLManager(4, 3);
    glManager.openWindow(600, 400, "Yeahh!");
    glManager.setRenderer(new MyRenderer());
    glManager.run();
    return 0;
}
