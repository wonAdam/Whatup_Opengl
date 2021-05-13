#pragma once

#include <vector>

class Camera;
class GameObject;
class Gui;
class Light;
class Shader;
class Framebuffer;
struct GLFWwindow;

// settings
const unsigned int SCR_WIDTH = 800;
const unsigned int SCR_HEIGHT = 600;

class Game
{
public: // Global Instances
	static Game* Instance;
	static Camera* GameCamera;
	static Gui* GameGui;
	static GLFWwindow* GameWindow;
	static Framebuffer* GameFramebuffer;

private: // GameObjects
	std::vector<GameObject*> _gameObjects;
	std::vector<GameObject*> _gameObjects_transparent;
	std::vector<Light*> _lights;

private:
	static float lastFrame;
	static float lastMouseX;
	static float lastMouseY;
	static bool firstMouseMove;

public:
	static float deltaTime;
	static int winWidth;
	static int winHeight;

private:
	Game();
	Game(const Game& rhs) = delete;
	virtual ~Game();

public:
	static void Initialize();
	static void Start();
	static void Update();
	static void PostProcessing();
	static void End();

	static void LoadLightUniform(const Shader& shader);
	static void CursorDisable();
	static void CursorEnable();

	static void AddGameObject(GameObject* go);
	static void AddLight(Light* li);

private:
	static bool Initialize_glfw();
	static bool Initialization_glew();
	static void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods);
	static void cursor_position_callback(GLFWwindow* window, double xpos, double ypos);
	static void window_size_callback(GLFWwindow* window, int width, int height);
};

