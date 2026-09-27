cmake_minimum_required(VERSION 3.26)
project(Keibe)

set(CMAKE_CXX_STANDARD 20)

find_package(glfw3 CONFIG REQUIRED)

add_executable(Keibe
        main.cpp
        Cube.cpp
        Cube.h

        external/imgui/imgui.cpp
        external/imgui/imgui_draw.cpp
        external/imgui/imgui_tables.cpp
        external/imgui/imgui_widgets.cpp

        external/imgui/backends/imgui_impl_glfw.cpp
        external/imgui/backends/imgui_impl_opengl3.cpp
        Solver.cpp
        Solver.h
)

target_include_directories(Keibe PRIVATE
        external/imgui
        external/imgui/backends
)

find_package(OpenGL REQUIRED)

target_link_libraries(Keibe PRIVATE
        glfw
        OpenGL::GL
)