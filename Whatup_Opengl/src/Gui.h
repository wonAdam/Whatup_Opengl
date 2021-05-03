#pragma once

#include <vector>

#include <imgui.h>
#include <imgui_impl_glfw.h>
#include <imgui_impl_opengl3.h>

class GameObject;
struct Transform;

class Gui
{
private:
    std::vector<GameObject*> _transformPanelList;

public:
    Gui(GLFWwindow* window);
    Gui(const Gui& rhs) = delete;
    virtual ~Gui();

public:
    void Update();
    void End();

    void RegisterTransformPanel(GameObject* registerer);

private:
    void showTransformPanel(GameObject* registerer);
};

