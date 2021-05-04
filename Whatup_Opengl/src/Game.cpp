#include "Game.h"

#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include "Camera.h"
#include "Triangle.h"
#include "Cube.h"
#include "Gui.h"
#include "Light.h"
#include "DirectionalLight.h"
#include "PointLight.h"
#include "SpotLight.h"

Game* Game::Instance;
Camera* Game::GameCamera;
Gui* Game::GameGui;
GLFWwindow* Game::GameWindow;
float Game::lastFrame = 0.0f;
float Game::deltaTime = 0.0f;
float Game::lastMouseX;
float Game::lastMouseY;
bool Game::firstMouseMove = true;

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

	GameWindow = window;

	GameCamera = new Camera(
		glm::vec3(0.0f, 0.0f, 3.0f),
		glm::vec3(0.0f, 0.0f, 0.0f)
	);
	GameGui->RegisterTransformPanel(GameCamera);

	glfwSetKeyCallback(window, Game::key_callback);
	glfwSetCursorPosCallback(window, Game::cursor_position_callback);

	//DirectionalLight* dirLight = new DirectionalLight("Directional Light", glm::vec3(0.0f, 180.0f, 0.0f), glm::vec3(0.1f, 0.1f, 0.1f), glm::vec3(1.0f, 1.0f, 1.0f), glm::vec3(1.0f, 1.0f, 1.0f));
	//Instance->_lights.push_back(dirLight);
	//GameGui->RegisterTransformPanel(dirLight);
	PointLight* pLight = new PointLight("Point Light", glm::vec3(0.0f, 0.0f, 0.0f), glm::vec3(0.1f, 0.1f, 0.1f), glm::vec3(1.0f, 1.0f, 1.0f), glm::vec3(1.0f, 1.0f, 1.0f));
	Instance->_lights.push_back(pLight);
	GameGui->RegisterTransformPanel(pLight);
	//SpotLight* sLight = new SpotLight("Spot Light", glm::vec3(0.0f, 0.0f, 0.0f), glm::vec3(0.0f, 0.0f, 0.0f), glm::vec3(0.1f, 0.1f, 0.1f), glm::vec3(0.75f, 0.75f, 0.75f), glm::vec3(1.0f, 1.0f, 1.0f));
	//Instance->_lights.push_back(sLight);
	//GameGui->RegisterTransformPanel(sLight);

	lastFrame = time;
	deltaTime = 0.0f;

	// --- Game Initialization --- //
	/*Triangle* triangle = new Triangle("Triangle", glm::vec3(0.0f, 0.0f, -3.0f), glm::vec3(0.0f, 180.0f, 0.0f), glm::vec3(1.0f));
	GameGui->RegisterTransformPanel(triangle);
	Instance->_gameObjects.push_back(triangle);*/
	Cube* cube = new Cube("Cube", glm::vec3(0.0f, 0.0f, -3.0f), glm::vec3(0.0f, 180.0f, 0.0f), glm::vec3(1.0f));
	GameGui->RegisterTransformPanel(cube);
	Instance->_gameObjects.push_back(cube);
}

void Game::Update(float time)
{
	deltaTime = time - lastFrame;
	lastFrame = time;

	GameCamera->Update(deltaTime);

	if (GameCamera->FPSMode == false)
		CursorEnable();
	else
		CursorDisable();

	for (GameObject* go : Instance->_gameObjects)
		go->Update(deltaTime);

	GameGui->Update();
}


void Game::End()
{
	delete Instance;
}

void Game::LoadLightUniform(const Shader& shader)
{
	unsigned int lightCnt[LIGHT_TPYE_COUNT] = { 0,0,0 };
	for (Light* light : Instance->_lights)
	{
		if (dynamic_cast<DirectionalLight*>(light) != nullptr)
			light->LoadUniformValue(lightCnt[Light::TYPE::DIRECTIONAL]++, shader);
		else if (dynamic_cast<PointLight*>(light) != nullptr)
			light->LoadUniformValue(lightCnt[Light::TYPE::POINT]++, shader);
		else if (dynamic_cast<SpotLight*>(light) != nullptr)
			light->LoadUniformValue(lightCnt[Light::TYPE::SPOT]++, shader);
	}
	shader.setInt("n_of_dir_lights", lightCnt[Light::TYPE::DIRECTIONAL]);
	shader.setInt("n_of_point_lights", lightCnt[Light::TYPE::POINT]);
	shader.setInt("n_of_spot_lights", lightCnt[Light::TYPE::SPOT]);
	shader.setVec3("viewPos", Game::GameCamera->_transform._position);
}

void Game::CursorDisable()
{
	glfwSetInputMode(GameWindow, GLFW_CURSOR, GLFW_CURSOR_DISABLED);
}

void Game::CursorEnable()
{
	glfwSetInputMode(GameWindow, GLFW_CURSOR, GLFW_CURSOR_NORMAL);
}

void Game::key_callback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
	if (glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS)
		GameCamera->Move(0.0, 0.0, 1.0f);
	if (glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS)
		GameCamera->Move(0.0, 0.0, -1.0f);
	if (glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS)
		GameCamera->Move(-1.0f, 0.0f, 0.0f);
	if (glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS)
		GameCamera->Move(1.0f, 0.0f, 0.0f);
	if (glfwGetKey(window, GLFW_KEY_E) == GLFW_PRESS)
		GameCamera->Move(0.0, 1.0, 0.0f);
	if (glfwGetKey(window, GLFW_KEY_Q) == GLFW_PRESS)
		GameCamera->Move(0.0, -1.0, 0.0f);
	if (glfwGetKey(window, GLFW_KEY_G) == GLFW_PRESS)
	{
		GameCamera->FPSMode = !GameCamera->FPSMode;
		firstMouseMove = true;
	}
	if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
		glfwSetWindowShouldClose(window, true);
}

#include <iostream>
void Game::cursor_position_callback(GLFWwindow* window, double xpos, double ypos)
{
	if (GameCamera->FPSMode == false) return;

	if (firstMouseMove)
	{
		lastMouseX = xpos;
		lastMouseY = ypos;
		firstMouseMove = false;
	}

	float xoffset = lastMouseX - xpos;
	float yoffset = lastMouseY - ypos;
	lastMouseX = xpos;
	lastMouseY = ypos;

	GameCamera->Rotate(xoffset, yoffset);
}
