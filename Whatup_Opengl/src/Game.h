#pragma once

#include <vector>

class Camera;
class GameObject;
class Gui;
struct GLFWwindow;

class Game
{
public: // Global Instances
	static Game* Instance;
	static Camera* GameCamera;
	static Gui* GameGui;

public: // GameObjects
	std::vector<GameObject*> _gameObjects;

private:
	static float lastFrame;
	static float deltaTime;

private:
	Game();
	Game(const Game& rhs) = delete;
	virtual ~Game();

public:
	static void Initialize(float time, GLFWwindow* window);
	static void Update(float time);
	static void End();
};

