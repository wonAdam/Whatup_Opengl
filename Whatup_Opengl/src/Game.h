#pragma once

#include <vector>

class Camera;
class Time;
class GameObject;

class Game
{
public:
	static Game* Instance;
	static Time* GameTime;
	static Camera* GameCamera;

public:
	std::vector<GameObject*> _gameObjects;

public:
	virtual ~Game();
	static void Initialize();
	static void Update(float time);

private:
	Game();
};

