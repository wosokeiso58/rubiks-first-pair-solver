#include "Solver.h"
#include "imgui.h"
#include "imgui_impl_glfw.h"
#include "imgui_impl_opengl3.h"
#include <GLFW/glfw3.h>
#include <iostream>

int main()
{
    glfwInit();

    GLFWwindow* window = glfwCreateWindow(
            800,
            600,
            "Keibe Cube Trainer",
            nullptr,
            nullptr
    );

    glfwMakeContextCurrent(window);

    IMGUI_CHECKVERSION();
    ImGui::CreateContext();

    ImGui_ImplGlfw_InitForOpenGL(window, true);
    ImGui_ImplOpenGL3_Init("#version 130");


    AppState state;

    while (!glfwWindowShouldClose(window))
    {
        glfwPollEvents();

        ImGui_ImplOpenGL3_NewFrame();
        ImGui_ImplGlfw_NewFrame();
        ImGui::NewFrame();


        ImGui::Begin("Cube Trainer");

        ImGui::Text("The cube goblin has awakened.");

        ImGui::InputText("Scramble",state.scrambleBuffer,IM_ARRAYSIZE(state.scrambleBuffer));

        if(ImGui::Button("Solve"))
        {
            state.solving = true;
        }
        if(state.solving)
        {
            solve(state);
            state.solving = false;
        }
        if(state.solved){
            ImGui::Text("Cross solution: ");

            for(const auto& move : state.crossSolution){
                ImGui::SameLine();
                ImGui::Text("%s", move.c_str());
            }

            ImGui::Text("First pair solution: ");
            for(const auto& move : state.pairSolution){
                ImGui::SameLine();
                ImGui::Text("%s", move.c_str());
            }
        }
        ImGui::End();


        ImGui::Render();

        glClear(GL_COLOR_BUFFER_BIT);

        ImGui_ImplOpenGL3_RenderDrawData(
                ImGui::GetDrawData()
        );

        glfwSwapBuffers(window);
    }


    ImGui_ImplOpenGL3_Shutdown();
    ImGui_ImplGlfw_Shutdown();
    ImGui::DestroyContext();

    glfwDestroyWindow(window);
    glfwTerminate();

    return 0;
}