#include "Input.h"

#include "GLFW/glfw3.h"

void Input::KeyboardInputHandler(GLFWwindow* window, int key, int scancode, int action, int mods)
{
	if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
	{
		glfwSetWindowShouldClose(window, GLFW_TRUE);
	}

}

void Input::MousePosInputHandler(GLFWwindow* window, double xpos, double ypos)
{
}
