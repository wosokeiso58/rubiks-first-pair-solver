#include "Solver.h"
#include "imgui.h"
#include "imgui_impl_glfw.h"
#include "imgui_impl_opengl3.h"
#include "Cube.h"
#include <GLFW/glfw3.h>
#include <iostream>

void drawSticker(ImDrawList* drawList, float x, float y, float size, char colour)
{
    ImU32 colourValue = IM_COL32(255,0,255,255); // pink error colour

    switch(colour)
    {
        case 'W':
            colourValue = IM_COL32(255,255,255,255);
            break;

        case 'Y':
            colourValue = IM_COL32(255,255,0,255);
            break;

        case 'R':
            colourValue = IM_COL32(255,0,0,255);
            break;

        case 'G':
            colourValue = IM_COL32(0,255,0,255);
            break;

        case 'B':
            colourValue = IM_COL32(0,0,255,255);
            break;

        case 'O':
            colourValue = IM_COL32(255,128,0,255);
            break;
    }

    drawList->AddRectFilled(
            ImVec2(x,y),
            ImVec2(x+size,y+size),
            colourValue
    );

    drawList->AddRect(
            ImVec2(x,y),
            ImVec2(x+size,y+size),
            IM_COL32(0,0,0,255)
    );
}

void drawFace(ImDrawList* drawList, Cube& cube, int startIndex, float x, float y)
{
    auto stickers = cube.getStickers();
    float size = 30;

    for(int i=0;i<9;i++)
    {
        drawSticker(drawList,x + (i%3)*size,y + (i/3)*size,size,stickers[startIndex+i]);
    }
}
void drawCube(Cube& cube)
{
    ImDrawList* drawList = ImGui::GetWindowDrawList();
    ImVec2 pos = ImGui::GetCursorScreenPos();

    drawFace(drawList, cube, 0, pos.x+100, pos.y);

    drawFace(drawList, cube, 9, pos.x, pos.y+100);
    drawFace(drawList, cube, 18, pos.x+100, pos.y+100);
    drawFace(drawList, cube, 27, pos.x+200, pos.y+100);
    drawFace(drawList, cube, 36, pos.x+300, pos.y+100);

    drawFace(drawList, cube, 45, pos.x+100, pos.y+200);
}

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


        ImGui::Begin(
                "Cube Trainer",
                nullptr,
                ImGuiWindowFlags_NoResize |
                ImGuiWindowFlags_NoMove
        );

        ImGui::Text("The cube goblin has awakened.\nAll cross solutions done on white cross with green front.\nStart cross solutions with a z2 rotation.");

        ImGui::InputText("Scramble",state.scrambleBuffer,IM_ARRAYSIZE(state.scrambleBuffer));

        if(ImGui::Button("Solve"))
        {
            state.solving = true;
            solve(state);
        }
        if(state.solving)
        {
            ImGui::Text("Solving...");
        }
        if(state.solved){
            ImGui::Text("Solved in %lld ms.", state.solveTime);
            ImGui::Checkbox("Show scramble",&state.showScrambleCube);
            if(state.showScrambleCube){
                drawCube(state.scrambleCube);
                ImGui::Dummy(ImVec2(400,300));
            }

            ImGui::Text("Cross solution: ");

            if(state.crossSolution.empty()){
                ImGui::SameLine();
                ImGui::Text("Cross already solved!");
            }
            else{
                for(const auto& move : state.crossSolution){
                    ImGui::SameLine();
                    ImGui::Text("%s", move.c_str());
                }
            }
            ImGui::SameLine();
            ImGui::Checkbox("Show cross",&state.showCrossCube);
            if(state.showCrossCube){
                drawCube(state.crossCube);
                ImGui::Dummy(ImVec2(400,300));
            }
            if(state.pairSolution.empty()){
                ImGui::Text("First pair already paired!");
            }
            else{
                ImGui::Text("First pair solution");
                ImGui::SameLine();
                ImGui::Text("(%s):", state.solvedPair.c_str());
                for(const auto& move : state.pairSolution){
                    ImGui::SameLine();
                    ImGui::Text("%s", move.c_str());
                }
                ImGui::SameLine();
                ImGui::Checkbox("Show pair",&state.showPairCube);
                if(state.showPairCube){
                    drawCube(state.pairCube);
                    ImGui::Dummy(ImVec2(400,300));
                }
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