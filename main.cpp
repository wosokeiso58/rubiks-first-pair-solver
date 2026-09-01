#include <iostream>
#include "cmake-build-debug/Cube.h"
#include <chrono>

int main() {

    Cube cube1;
    cube1.doMoveSequence("L' D2 B D F2 B2 L D' B2 L' U2 L' U2 L2 F2 U2 D2 L U2 D2 F'");
    auto start1 = std::chrono::high_resolution_clock::now();
    std::cout << cube1.crossPlusOne();
    auto end1 = std::chrono::high_resolution_clock::now();
    auto avg = start1-end1;
    std::array<std::string,7> scrambles{
        "R' U2 D' R D B' R2 D R' B2 U2 B2 R2 D' B2 R2 U2 R2 U B2 U",
        "F R' B2 D2 L D' B' D' L2 B2 D2 F2 D R2 L2 D' L2 B2 D F",
        "L' U2 R2 D' L' F D2 F' L' D B2 L2 B2 L2 D L2 D' R2 L2 D",
        "D2 L R2 D2 F2 D2 R' D2 L' F R B' L' F L' D' L U' F",
        "F B2 R2 F2 D L2 D2 L2 D2 B2 D' F2 B U' B' L' D' L U",
        "D B D R2 D' F2 L2 U' F2 L2 U F2 R2 L U' L B2 R B U'",
        "B' U2 L2 F2 L' B2 F2 R D2 L B2 U2 B' U2 R D B L2 U F2"

    };


    for(const auto& scramble : scrambles){
        Cube cube;
        cube.doMoveSequence(scramble);
        auto start = std::chrono::high_resolution_clock::now();
        std::cout << cube.crossPlusOne();
        auto end = std::chrono::high_resolution_clock::now();
        avg+=(end-start);
    }

    std::cout<<"\nAverage ms: "<<std::chrono::duration_cast<std::chrono::milliseconds>(avg/10);
}