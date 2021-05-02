#include "Input.h"

#include "GLFW/glfw3.h"

#include "Game.h"
#include "Camera.h"

float Input::lastX = SCR_WIDTH / 2.0f;
float Input::lastY = SCR_HEIGHT / 2.0f;
bool Input::firstMouse = true;

void Input::KeyboardInputHandler(GLFWwindow* window, int key, int scancode, int action, int mods)
{
	if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
	{
		glfwSetWindowShouldClose(window, GLFW_TRUE);
	}

}

void Input::MousePosInputHandler(GLFWwindow* window, double xpos, double ypos)
{
	if (firstMouse)
	{
		lastX = xpos;
		lastY = ypos;
		firstMouse = false;
	}

	float xoffset = xpos - lastX;
	float yoffset = lastY - ypos; // reversed since y-coordinates go from bottom to top

	lastX = xpos;
	lastY = ypos;

	Game::GameCamera->ProcessMouseMovement(xoffset, yoffset);
}


Input::Input()
{
}

Input::~Input()
{
}
