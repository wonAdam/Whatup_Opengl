#include "Gui.h"

#include <glm/gtc/type_ptr.hpp>
#include "GameObject.h"
#include "Transform.h"
#include "Game.h"
#include "Camera.h"
#include "lights/Light.h"
#include "SpotLight.h"
#include "DirectionalLight.h"
#include "PointLight.h"
#include "DogeCube.h"

Gui::Gui(GLFWwindow* window)
{
    IMGUI_CHECKVERSION();
    ImGui::CreateContext();
    ImGui::StyleColorsDark();
    ImGui_ImplGlfw_InitForOpenGL(window, true);
    const char* glsl_version = "#version 330";
    ImGui_ImplOpenGL3_Init(glsl_version);
}

Gui::~Gui()
{
}

void Gui::Update()
{
    // Start the Dear ImGui frame
    ImGui_ImplOpenGL3_NewFrame();
    ImGui_ImplGlfw_NewFrame();
    ImGui::NewFrame();

    // --- Camera Mode --- //
    ImGui::Begin("Mouse Mode");
    if (Game::Instance->GameCamera->FPSMode == false)
    {
        if (ImGui::Button("Back To FPS Mode"))
            Game::Instance->GameCamera->FPSMode = true;
    }
    else
    {
        ImGui::Text("Press G to Cancel the FPS Mode");
    }

        
    ImGui::End();

    for (GameObject* registerer : _transformPanelList)
        showTransformPanel(registerer);

    //ImGui::Text("Application average %.3f ms/frame (%.1f FPS)", 1000.0f / ImGui::GetIO().Framerate, ImGui::GetIO().Framerate);

    ImGui::Render();
    ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
}

void Gui::End()
{
    ImGui_ImplOpenGL3_Shutdown();
    ImGui_ImplGlfw_Shutdown();
    ImGui::DestroyContext();
}

void Gui::RegisterTransformPanel(GameObject* registerer)
{
    _transformPanelList.push_back(registerer);
}

void Gui::showTransformPanel(GameObject* registerer)
{
    ImGui::Begin(registerer->_name.c_str());
    ImGui::SliderFloat3("Position", glm::value_ptr(registerer->_transform._position), -20.f, 20.f);
    ImGui::SliderFloat3("Rotation", glm::value_ptr(registerer->_transform._rotation), -180.f, 180.f);
    ImGui::SliderFloat3("Scale", glm::value_ptr(registerer->_transform._scale), -20.f, 20.f);
    glm::vec3 forward = registerer->_transform.GetForward();
    glm::vec3 up = registerer->_transform.GetUp();
    glm::vec3 right = registerer->_transform.GetRight();
    ImGui::Text("Forward\t\t(%.3f, %.3f, %.3f)", forward.x, forward.y, forward.z);
    ImGui::Text("Up\t\t\t(%.3f, %.3f, %.3f)", up.x, up.y, up.z);
    ImGui::Text("Right\t\t(%.3f, %.3f, %.3f)", right.x, right.y, right.z);
    
    IOutlineable* outlineable = dynamic_cast<IOutlineable*>(registerer);
    if (outlineable != nullptr)
    {
        ImGui::Checkbox("Outline", &outlineable->_outline);
    }

    Light* li = dynamic_cast<Light*>(registerer);
    if (li != nullptr)
    {
        ImGui::SliderFloat3("Ambient", glm::value_ptr(li->_ambient), 0.f, 1.f);
        ImGui::SliderFloat3("Diffuse", glm::value_ptr(li->_diffuse), 0.f, 1.f);
        ImGui::SliderFloat3("Specular", glm::value_ptr(li->_specular), 0.f, 1.f);
    }
    SpotLight* sl = dynamic_cast<SpotLight*>(registerer);
    if (sl != nullptr)
    {
        ImGui::SliderFloat("CutOff", &sl->_cutOff, 0.f, glm::pi<float>());
        ImGui::SliderFloat("OuterCutOff", &sl->_outerCutOff, 0.f, glm::pi<float>());
    }
    PointLight* pl = dynamic_cast<PointLight*>(registerer);
    if (pl != nullptr)
    {
        ImGui::SliderFloat("Constant", &pl->_constant, 0.f, 3.f);
        ImGui::SliderFloat("Linear", &pl->_linear, 0.f, 1.f);
        ImGui::SliderFloat("Quadratic", &pl->_quadratic, 0.f, 1.f);
    }

    ImGui::End();
}
