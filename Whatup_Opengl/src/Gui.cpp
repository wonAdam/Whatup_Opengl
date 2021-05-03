#include "Gui.h"

#include <glm/gtc/type_ptr.hpp>
#include "GameObject.h"

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
    ImGui::End();
}
