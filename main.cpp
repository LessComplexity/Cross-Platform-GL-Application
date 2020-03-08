#include "glshift/GLShift.h"
#include <vector>

#define numVAOs 1

GLuint createShaderProgram() {
    const char* vShaderSource =
            "#version 430 \n"
            "void main(void) \n"
            "{ gl_Position = vec4(0.0, 0.0, 0.0, 1.0); }";
    const char* fShaderSource =
            "#version 430 \n"
            "out vec4 color; \n"
            "void main(void) \n"
            "{ color = vec4(0.0, 1.0, 1.0, 1.0); }";

    GLuint vShader = glCreateShader(GL_VERTEX_SHADER);
    GLuint fShader = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(vShader, 1, &vShaderSource, NULL); glCompileShader(vShader);
    glShaderSource(fShader, 1, &fShaderSource, NULL); glCompileShader(fShader);

    GLuint vfProgram = glCreateProgram();
    glAttachShader(vfProgram, vShader); glAttachShader(vfProgram, fShader);
    glLinkProgram(vfProgram);
    return vfProgram;
}

/**
 * Example for a renderer implementation
 */
class MyRenderer : public GLShift::GLRenderer {
public:
    void render() override {
        glClearColor(1.0, 0.0, 0.0, 1.0);
        glClear(GL_COLOR_BUFFER_BIT);

        glUseProgram(this->renderingProgram);
        glDrawArrays(GL_POINTS, 0, 1);
    }

    void init() override {
        this->renderingProgram = createShaderProgram();
        glGenVertexArrays(numVAOs, this->vao);
        glBindVertexArray(vao[0]);
    }

private:
    GLuint renderingProgram;
    GLuint vao[numVAOs];
};

int main() {
    /**
     * Example for a GLManager implementation
     */
    GLShift::GLManager glManager = GLShift::GLManager(4, 3);
    glManager.openWindow(600, 300, "Yeahh!");
    glManager.setRenderer(new MyRenderer());
    glManager.run();
    return 0;
}
