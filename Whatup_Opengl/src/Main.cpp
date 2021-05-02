#include <iostream>

#include <imgui.h>
#include <imgui_impl_glfw.h>
#include <imgui_impl_opengl3.h>

#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include <stb_image.h>
#include <glm/glm.hpp>
#include <assimp/Importer.hpp>
#include "Shader.h"
#include "Texture.h"
#include "Mesh.h"
#include "GLMacro.h"

bool Initialize_glfw(GLFWwindow*& window);
void GuiUpdate();
bool Initialization_glew();
void Initialization_ImGui(GLFWwindow* window);

// settings
const unsigned int SCR_WIDTH = 800;
const unsigned int SCR_HEIGHT = 600;

int main(void)
{
    GLFWwindow* window;
    Initialize_glfw(window);
    Initialization_glew();
    Initialization_ImGui(window);


    Shader shader("shaders/VertexShader.vert", "shaders/FragmentShader.frag");

    // set up vertex data (and buffer(s)) and configure vertex attributes
   // ------------------------------------------------------------------
    std::vector<Vertex> vertices = {
        // positions         // normals             // tex coord
        Vertex( 0.5f, -0.5f, 0.0f,  0.0f, 0.0f, 1.0f, 1.0f, 0.0f),  // bottom right
        Vertex(-0.5f, -0.5f, 0.0f,  0.0f, 0.0f, 1.0f, 0.0f, 0.0f),  // bottom left
        Vertex(0.0f,  0.5f, 0.0f,  0.0f, 0.0f, 1.0f, 0.5f, 1.0f)   // top 
    };
    std::vector<unsigned int> indices = { 0,1,2 };
    std::vector<Texture> textures = {
        Texture("img/container2.png", Texture::DIFFUSE),
        Texture("img/doge.png", Texture::DIFFUSE)
    };

    Mesh* mesh = new Mesh(vertices, indices, textures);
    /* Loop until the user closes the window */
    while (!glfwWindowShouldClose(window))
    {
        /* Render here */
        glClearColor(0.3f, 0.3f, 0.3f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        mesh->Draw(shader);
        GuiUpdate();

        /* Swap front and back buffers */
        glfwSwapBuffers(window);
        /* Poll for and process events */
        glfwPollEvents();
    }

    // Cleanup
    ImGui_ImplOpenGL3_Shutdown();
    ImGui_ImplGlfw_Shutdown();
    ImGui::DestroyContext();

    glfwTerminate();
    return 0;
}

void GuiUpdate()
{
    // Start the Dear ImGui frame
    ImGui_ImplOpenGL3_NewFrame();
    ImGui_ImplGlfw_NewFrame();
    ImGui::NewFrame();

    ImGui::Begin("Hello, ImGui!");                          // Create a window called "Hello, world!" and append into it.
    ImGui::Text("This is some useful text.");               // Display some text (you can use a format strings too)
    ImGui::Button("Button");
    ImGui::SameLine();
    ImGui::Text("Application average %.3f ms/frame (%.1f FPS)", 1000.0f / ImGui::GetIO().Framerate, ImGui::GetIO().Framerate);
    ImGui::End();

    ImGui::Render();
    ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
}

bool Initialize_glfw(GLFWwindow*& window)
{
    /* Initialize the library */
    if (!glfwInit())
        return false;

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    /* Create a windowed mode window and its OpenGL context */
    window = glfwCreateWindow(800, 600, "Whatup OpenGL ! ", NULL, NULL);
    if (!window)
    {
        glfwTerminate();
        return false;
    }
    /* Make the window's context current */
    glfwMakeContextCurrent(window);
    return true;
}

bool Initialization_glew()
{
    glewExperimental = GL_TRUE;
    GLenum err = glewInit();
    if (GLEW_OK != err)
        return false;

    glViewport(0, 0, 800, 600);
    //glEnable(GL_DEPTH_TEST);

    return true;
}

void Initialization_ImGui(GLFWwindow* window)
{
    IMGUI_CHECKVERSION();
    ImGui::CreateContext();
    ImGui::StyleColorsDark();
    ImGui_ImplGlfw_InitForOpenGL(window, true);
    const char* glsl_version = "#version 330";
    ImGui_ImplOpenGL3_Init(glsl_version);
}
