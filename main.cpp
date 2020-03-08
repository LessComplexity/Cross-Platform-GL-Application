#include "glshift/GLShift.h"

#define numVAOs 1

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
        glDrawArrays(GL_POINTS, 0, 1);
    }

    void init() override {
        // Example for fixed shader
        const char* vShaderSource =
                "#version 430 \n"
                "void main(void) \n"
                "{ gl_Position = vec4(0.0, 0.0, 0.0, 1.0); }";
        const char* fShaderSource =
                "#version 430 \n"
                "out vec4 color; \n"
                "void main(void) \n"
                "{ color = vec4(0.0, 1.0, 1.0, 1.0); }";

        // Example for creating and linking a shader pipeline
        this->createProgram("main");
        this->addShader("main", vShaderSource, GL_VERTEX_SHADER);
        this->addShader("main", fShaderSource, GL_FRAGMENT_SHADER);
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
    glManager.openWindow(600, 300, "Yeahh!");
    glManager.setRenderer(new MyRenderer());
    glManager.run();
    return 0;
}
