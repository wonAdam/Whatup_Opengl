#include "Game.h"

#include <map>

#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include "Camera.h"
#include "gameobjects/Triangle.h"
#include "gameobjects/Quad.h"
#include "gameobjects/Window.h"
#include "gameobjects/Grass.h"
#include "gameobjects/DogeCube.h"
#include "gameobjects/SurvivorBackpack.h"
#include "Gui.h"
#include "Framebuffer.h"
#include "lights/Light.h"
#include "lights/DirectionalLight.h"
#include "lights/PointLight.h"
#include "lights/SpotLight.h"
#include "shaders/DefaultShader.h"
#include "shaders/LightShader.h"
#include "shaders/ScreenShader.h"
#include "GLMacro.h"

Game* Game::Instance;
Camera* Game::GameCamera;
Gui* Game::GameGui;
GLFWwindow* Game::GameWindow;
Framebuffer* Game::GameFramebuffer;
float Game::lastFrame = 0.0f;
float Game::deltaTime = 0.0f;
int Game::winWidth = 800;
int Game::winHeight = 600;
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

void Game::Initialize()
{
	Instance = new Game();

	Initialize_glfw();
	Initialization_glew();

	lastFrame = glfwGetTime();
	deltaTime = 0.0f;
}

void Game::Start()
{
	// --- Core Objects --- //
	GameGui = new Gui(Game::GameWindow);

	std::shared_ptr<ScreenShader> screenShader(new ScreenShader());
	GameFramebuffer = new Framebuffer(screenShader);

	GameCamera = new Camera(
		glm::vec3(0.0f, 0.0f, 3.0f),
		glm::vec3(0.0f, 0.0f, 0.0f)
	);
	GameGui->RegisterTransformPanel(GameCamera);

	// --- Game Objects --- //
	// Lights
	DirectionalLight* dirLight = new DirectionalLight("Directional Light", glm::vec3(-30.0f, 120.0f, 0.0f), glm::vec3(0.1f, 0.1f, 0.1f), glm::vec3(0.9f, 0.9f, 0.9f), glm::vec3(0.8f, 0.8f, 0.8f));
	Game::Instance->AddLight(dirLight);
	GameGui->RegisterTransformPanel(dirLight);

	PointLight* pLight = new PointLight("Point Light", glm::vec3(-1.0f, 0.0f, 0.0f), glm::vec3(0.1f, 0.1f, 0.1f), glm::vec3(0.9f, 0.9f, 0.9f), glm::vec3(0.8f, 0.8f, 0.8f));
	Game::Instance->AddLight(pLight);
	GameGui->RegisterTransformPanel(pLight);

	SpotLight* sLight = new SpotLight("Spot Light", glm::vec3(1.0f, 0.0f, 0.0f), glm::vec3(0.0f, 0.0f, 0.0f), glm::vec3(0.1f, 0.1f, 0.1f), glm::vec3(0.9f, 0.9f, 0.9f), glm::vec3(0.8f, 0.8f, 0.8f));
	Game::Instance->AddLight(sLight);
	GameGui->RegisterTransformPanel(sLight);

	Triangle* triangle = new Triangle("Triangle", glm::vec3(0.0f, 0.0f, -3.0f), glm::vec3(0.0f, 180.0f, 0.0f), glm::vec3(1.0f));
	GameGui->RegisterTransformPanel(triangle);
	Game::Instance->AddGameObject(triangle);

	Grass* grass = new Grass("Grass", glm::vec3(0.0f, 2.0f, -3.0f), glm::vec3(0.0f, 180.0f, 0.0f), glm::vec3(1.0f));
	GameGui->RegisterTransformPanel(grass);
	Game::Instance->AddGameObject(grass);

	DogeCube* cube = new DogeCube("DogeCube", glm::vec3(0.0f, 0.0f, -3.0f), glm::vec3(0.0f, 180.0f, 0.0f), glm::vec3(1.0f));
	GameGui->RegisterTransformPanel(cube);
	Game::Instance->AddGameObject(cube);

	for (int i = 0; i < 3; i++)
	{
		Window* transWindow = new Window("Window" + std::to_string(i), glm::vec3(0.0f, static_cast<float>(-i), -3.0f), glm::vec3(0.0f, 180.0f, 0.0f), glm::vec3(1.0f));
		GameGui->RegisterTransformPanel(transWindow);
		Game::Instance->AddGameObject(transWindow);
	}


	//std::shared_ptr<Model> backpack(new Model("models/backpack/backpack.obj"));
	//SurvivorBackpack* sb = new SurvivorBackpack(backpack, "Backpack", glm::vec3(1.0f, 2.0f, 3.0f), glm::vec3(0.0f), glm::vec3(1.0f));
	//GameGui->RegisterTransformPanel(sb);
	//Instance->_gameObjects.push_back(sb);
}

void Game::Update()
{
	GameFramebuffer->Bind(true);

	// Time
	float time = glfwGetTime();
	deltaTime = time - lastFrame;
	lastFrame = time;

	// Updates
	GameCamera->Update(deltaTime);

	for (GameObject* go : Instance->_gameObjects)
		go->Update(deltaTime);

	for (Light* li : Instance->_lights)
		li->Update(deltaTime);

	// Render Transparent Object by Order
	std::map<float, GameObject*> sorted;
	for (GameObject* t_go : Instance->_gameObjects_transparent)
	{
		float distance = glm::length(GameCamera->_transform._position - t_go->_transform._position);
		sorted[distance] = t_go;
	}
	for (auto it = sorted.rbegin(); it != sorted.rend(); ++it)
	{
		it->second->Update(deltaTime);
	}

	GameGui->Update();

	GameFramebuffer->Bind(false);
	GameFramebuffer->Draw();
}

void Game::PostProcessing()
{
	
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
			light->LoadUniformValue(lightCnt[static_cast<unsigned int>(Light::Type::DIRECTIONAL)]++, shader);
		else if (dynamic_cast<PointLight*>(light) != nullptr)
			light->LoadUniformValue(lightCnt[static_cast<unsigned int>(Light::Type::POINT)]++, shader);
		else if (dynamic_cast<SpotLight*>(light) != nullptr)
			light->LoadUniformValue(lightCnt[static_cast<unsigned int>(Light::Type::SPOT)]++, shader);
	}
	shader.setInt("n_of_dir_lights", lightCnt[static_cast<unsigned int>(Light::Type::DIRECTIONAL)]);
	shader.setInt("n_of_point_lights", lightCnt[static_cast<unsigned int>(Light::Type::POINT)]);
	shader.setInt("n_of_spot_lights", lightCnt[static_cast<unsigned int>(Light::Type::SPOT)]);
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

void Game::AddGameObject(GameObject* go)
{
	// transparent object check
	if (dynamic_cast<ITransparent*>(go) == nullptr)
		Game::Instance->_gameObjects.push_back(go);
	else
		Game::Instance->_gameObjects_transparent.push_back(go);
}

void Game::AddLight(Light* li)
{
	Game::Instance->_lights.push_back(li);
}

bool Game::Initialize_glfw()
{
	/* Initialize the library */
	if (!glfwInit())
		return false;

	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	/* Create a windowed mode window and its OpenGL context */
	GameWindow = glfwCreateWindow(SCR_WIDTH, SCR_HEIGHT, "Whatup OpenGL ! ", NULL, NULL);
	if (!GameWindow)
	{
		glfwTerminate();
		return false;
	}
	/* Make the window's context current */
	glfwMakeContextCurrent(GameWindow);

	glfwSetKeyCallback(Game::GameWindow, Game::key_callback);
	glfwSetCursorPosCallback(Game::GameWindow, Game::cursor_position_callback);
	glfwSetWindowSizeCallback(Game::GameWindow, Game::window_size_callback);

	return true;
}

bool Game::Initialization_glew()
{
	glewExperimental = GL_TRUE;
	GLenum err = glewInit();
	if (GLEW_OK != err)
		return false;

	GLCall(glViewport(0, 0, 800, 600));
	GLCall(glEnable(GL_DEPTH_TEST));
	GLCall(glEnable(GL_STENCIL_TEST));
	GLCall(glEnable(GL_BLEND));
	GLCall(glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA));
	GLCall(glStencilOp(GL_KEEP, GL_KEEP, GL_REPLACE));
	GLCall(glEnable(GL_CULL_FACE));
	GLCall(glCullFace(GL_BACK));
	GLCall(glFrontFace(GL_CCW));

	return true;
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

		if (GameCamera->FPSMode == false)
			CursorEnable();
		else
			CursorDisable();
	}
	if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
		glfwSetWindowShouldClose(window, true);
}

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

void Game::window_size_callback(GLFWwindow* window, int width, int height)
{
	winWidth = width;
	winHeight = height;
	GLCall(glViewport(0, 0, width, height));
}
