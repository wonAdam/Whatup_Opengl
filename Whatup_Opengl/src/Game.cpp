#include "Game.h"

#include <glm/glm.hpp>

#include "Time.h"
#include "Camera.h"
#include "Cube.h"

Game* Game::Instance;
Camera* Game::GameCamera;
Time* Game::GameTime;

Game::Game()
{
	
}

Game::~Game()
{

}

void Game::Initialize()
{
	Instance = new Game();
	GameCamera = new Camera(glm::vec3(0.0f, 0.0f, 5.0f));
	GameTime = new Time();

	std::shared_ptr<Shader> shader(new Shader("src/vertexshader.vert", "src/fragmentshader.frag"));
	Cube* cube = new Cube(glm::vec3(0.0f), glm::vec3(0.0f), glm::vec3(1.0f), shader.get());
	
	Instance->_gameObjects.push_back(cube);
}

void Game::Update(float time)
{
	// Update DeltaTime
	GameTime->Update(time);

	// Update GameObjects
	for (GameObject* go : Instance->_gameObjects)
		go->Update(GameTime->deltaTime);

}
