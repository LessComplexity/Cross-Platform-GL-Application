#include "GL/glew.h"
#include "GLFW/glfw3.h"
#include <iostream>

int main() {
    if(!glfwInit()) exit(EXIT_FAILURE);

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    GLFWwindow* window = glfwCreateWindow(600, 300, "Test", NULL, NULL);
    glfwMakeContextCurrent(window);
    if(glewInit() != GLEW_OK) exit(EXIT_FAILURE);
    glfwSwapInterval(1); // Allow VSync

    while(!glfwWindowShouldClose(window)) {
        // Draw data on screen
        glClearColor(1, 0, 0, 1); // Clear screen to red as default
        glClear(GL_COLOR_BUFFER_BIT);
        glfwSwapBuffers(window); // Swap back & front buffers
        glfwPollEvents(); // Listen to keyword clicks
    }
    glfwDestroyWindow(window);
    glfwTerminate();
    exit(EXIT_SUCCESS);
    return 0;
}
