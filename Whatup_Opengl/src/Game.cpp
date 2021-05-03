#include "Game.h"

#include "Camera.h"
#include "Triangle.h"
#include "Gui.h"

Game* Game::Instance;
Camera* Game::GameCamera;
Gui* Game::GameGui;
float Game::lastFrame = 0.0f;
float Game::deltaTime = 0.0f;

Game::Game()
{
}

Game::~Game()
{
	for (GameObject* go : Instance->_gameObjects)
		delete go;

	GameGui->End();

	delete GameGui;
	delete GameCamera;
}

void Game::Initialize(float time, GLFWwindow* window)
{
	// --- Basic Initialization --- //
	Instance = new Game();
	GameGui = new Gui(window);

	GameCamera = new Camera(
		glm::vec3(0.0f, 0.0f, 0.0f),
		glm::vec3(0.0f, 0.0f, 0.0f)
	);
	GameGui->RegisterTransformPanel(GameCamera);

	lastFrame = time;
	deltaTime = 0.0f;

	// --- Game Initialization --- //
	Triangle* triangle = new Triangle("Triangle", glm::vec3(0.0f, 0.0f, -3.0f), glm::vec3(0.0f, 0.0f, 0.0f), glm::vec3(1.0f, 1.0f, 1.0f));
	GameGui->RegisterTransformPanel(triangle);
	Instance->_gameObjects.push_back(triangle);
}

void Game::Update(float time)
{
	deltaTime = time - lastFrame;
	lastFrame = time;

	GameCamera->Update(deltaTime);
	for (GameObject* go : Instance->_gameObjects)
		go->Update(deltaTime);

	GameGui->Update();
}


void Game::End()
{
	delete Instance;
}
