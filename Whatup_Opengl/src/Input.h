#pragma once

struct GLFWwindow;

const unsigned int SCR_WIDTH = 800;
const unsigned int SCR_HEIGHT = 600;

class Input
{
private:
	static float lastX;
	static float lastY;
	static bool firstMouse;

public:
	static void KeyboardInputHandler(GLFWwindow* window, int key, int scancode, int action, int mods);
	//static void MouseInputHandler(GLFWwindow* window, int button, int action, int mods);
	static void MousePosInputHandler(GLFWwindow* window, double xpos, double ypos);

private: 
	Input();
	virtual ~Input();

};

