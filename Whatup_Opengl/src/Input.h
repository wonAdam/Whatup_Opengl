#pragma once

struct GLFWwindow;

class Input
{
public:
	static void KeyboardInputHandler(GLFWwindow* window, int key, int scancode, int action, int mods);
	//static void MouseInputHandler(GLFWwindow* window, int button, int action, int mods);
	static void MousePosInputHandler(GLFWwindow* window, double xpos, double ypos);
};

