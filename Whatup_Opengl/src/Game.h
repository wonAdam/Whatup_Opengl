#pragma once

#include <vector>

class Camera;
class GameObject;
class Gui;
class Light;
class Shader;
struct GLFWwindow;

class Game
{
public: // Global Instances
	static Game* Instance;
	static Camera* GameCamera;
	static Gui* GameGui;
	static GLFWwindow* GameWindow;

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

private:
	Game();
	Game(const Game& rhs) = delete;
	virtual ~Game();

public:
	static void Initialize(float time, GLFWwindow* window);
	static void Update(float time);
	static void End();

	static void LoadLightUniform(const Shader& shader);
	static void CursorDisable();
	static void CursorEnable();

	static void AddGameObject(GameObject* go);
	static void AddLight(Light* li);

private:
	static void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods);
	static void cursor_position_callback(GLFWwindow* window, double xpos, double ypos);
};

