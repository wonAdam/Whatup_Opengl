#pragma once

#include <vector>
#include <deque>


class Camera;
class GameObject;
class Gui;
class Light;
class Shader;
class Framebuffer;
class Skybox;
struct GLFWwindow;

// settings
const unsigned int SCR_WIDTH = 800;
const unsigned int SCR_HEIGHT = 600;

struct GameObjectSort
{
	bool operator()(GameObject* a, GameObject* b)
	{

	}
};

class Game
{
public: // Global Instances
	static Game* Instance;
	static Camera* GameCamera;
	static Gui* GameGui;
	static Framebuffer* GameFramebuffer;
	static Skybox* GameSkybox;

	static GLFWwindow* GameWindow;

private: // GameObjects
	// transparent gameobjects are placed at back of the deque.
	// normal gameobjects area placed at front of the deque.
	std::deque<GameObject*> _gameObjects;

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
	static void LateUpdate();
	static void Render();
	static void OnGUI();
	static void End();

	static void LoadLightUniform(const Shader& shader);
	static void CursorDisable();
	static void CursorEnable();

	static void AddGameObject(GameObject* go);

private:
	static bool Initialize_glfw();
	static bool Initialization_glew();
	static void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods);
	static void cursor_position_callback(GLFWwindow* window, double xpos, double ypos);
	static void window_size_callback(GLFWwindow* window, int width, int height);
};

