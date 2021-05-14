#include <iostream>

#include <imgui.h>
#include <imgui_impl_glfw.h>
#include <imgui_impl_opengl3.h>

#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include <stb_image.h>
#include <glm/glm.hpp>
#include <glm/gtc/type_ptr.hpp>

#include "GLMacro.h"
#include "Game.h"


int main(void)
{
    Game::Initialize();

    Game::Start();

    /* Loop until the user closes the window */
    while (!glfwWindowShouldClose(Game::GameWindow))
    {
        Game::Update();
        Game::LateUpdate();
        Game::Render();
        Game::OnGUI();

        /* Swap front and back buffers */
        glfwSwapBuffers(Game::GameWindow);
        /* Poll for and process events */
        glfwPollEvents();
    }

    // Cleanup
    Game::End();
    glfwTerminate();
    return 0;
}


