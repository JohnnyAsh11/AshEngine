//GLEW has to be included before all other OpenGL libraries
#include <GL/glew.h>

// OpenGL 
#include <GLFW/glfw3.h>

#include <exception>
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

#include "Renderer.h"
#include "VertexBuffer.h"
#include "IndexBuffer.h"
#include "VertexArray.h"
#include "Shader.h"
#include "Renderer.h"
#include "VertexBufferLayout.h"

int main(void)
{
    GLFWwindow* window;

    // Initializing the GLFW library.
    if (!glfwInit())
    {
        return -1;
    }

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    // Creating a windowed-mode window and an OpenGL context with it.
    window = glfwCreateWindow(640, 480, "Hello World", NULL, NULL);
    if (!window)
    {
        glfwTerminate();
        return -1;
    }

    // Actually creating the window context.
    glfwMakeContextCurrent(window);
    glfwSwapInterval(1);

    // GlEW must be initialized after a Window Context is created.
    if (glewInit() != GLEW_OK)
    {
        throw std::exception("GLEW not initialized properly.");
    }
    // Printing the current version of OpenGL being worked with.
    std::cout << glGetString(GL_VERSION) << std::endl;

    float positions[] = {
        -0.5f, -0.5f, // 0
         0.5f, -0.5f, // 1
         0.5f,  0.5f, // 2
        -0.5f,  0.5f  // 3
    };

    // Will tell the renderer what indices of the positions array
    //  to draw and what order to do so.
    unsigned int indices[] = {
        0, 1, 2,
        2, 3, 0
    };

    // Vertex array object

    VertexArray* va = new VertexArray();

    // Vertex Buffer
    VertexBuffer* vb = new VertexBuffer(positions, (4 * sizeof(float)) * 2);

    VertexBufferLayout layout;
    layout.Push<float>(2);

    va->AddBuffer(*vb, layout);

    // Index Buffer
    IndexBuffer* ib = new IndexBuffer(indices, 6);


    Shader* shader = new Shader("res/shaders/basic.shader");
    shader->Bind();

    shader->SetUniform4f("u_Color", 0.0f, 0.0f, 1.0f, 1.0f);

    shader->Unbind();
    va->Unbind();
    vb->Unbind();
    ib->Unbind();

    Renderer renderer = Renderer();

    float r = 0.0f;
    float increment = 0.05f;

    // Keeps the program alive until the user closes the window.
    while (!glfwWindowShouldClose(window))
    {
        renderer.Clear();
        // Render after the glClear call.

        shader->Bind();
        shader->SetUniform4f("u_Color", r, 0.3f, 0.8f, 1.0f);

        renderer.Draw(*va, *ib, *shader);

        if (r < 0.0f)
        {
            increment = 0.05f;
        }
        else if (r > 1.0f)
        {
            increment = -0.05f;
        }

        r += increment;

        // Swapping the buffers
        glfwSwapBuffers(window);

        // Polling for process events.
        glfwPollEvents();
    }

    delete ib;
    delete vb;
    delete va;
    delete shader;

    // Closes the window.
    glfwTerminate();
    return 0;
}