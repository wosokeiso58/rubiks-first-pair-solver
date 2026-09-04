#include <iostream>
#include "cmake-build-debug/Cube.h"
#include <chrono>

int main() {

    Cube cube1;
    cube1.doMoveSequence("F2 L' U2 B2 R' B2 R2 U2 F2 U2 L' D2 F' U B' R' D L' U2 B2 L2");
    std::string solution1 = cube1.cross();
    std::cout << solution1;
    cube1.doMoveSequence(solution1);
    auto start1 = std::chrono::high_resolution_clock::now();
    std::cout << cube1.firstPair();
    auto end1 = std::chrono::high_resolution_clock::now();
    auto avg = start1-end1;
    std::array<std::string,7> scrambles{
        "B' U' F B' U' R U' R' U2 F' R2 D2 R2 F R2 F2 R2 B U2 L2",
        "U2 R2 B L2 F R2 B2 L2 U2 B' L2 F' D R U2 L2 R' D L B' D",
        "R' U' D2 F' R2 B' D2 F D2 R2 B2 L2 B2 D' F2 L D2 F' L' R'",
        "R' U' R2 F2 R2 U2 L2 B' D2 B2 R2 B D2 R' F L' R2 D F' L2 D'",
        "B2 L' D2 F' D2 B2 D2 R2 F D2 B' L2 R2 B U' F' L2 R' D2 U F2",
        "L U' R' F2 D2 U2 L2 F2 R F2 L D2 L B' D' U F2 U R B2",
        "L' U2 R' B2 U2 R D2 U2 R2 D2 R' B' F' U' B' L' F' R2 B U"

    };

    int count = 2;
    for(const auto& scramble : scrambles){
        std::cout << "Scramble " << count++;
        Cube cube;
        cube.doMoveSequence(scramble);
        std::string solution = cube.cross();
        auto start = std::chrono::high_resolution_clock::now();
        std::cout << solution;
        cube.doMoveSequence(solution);
        std::cout << cube.firstPair();
        auto end = std::chrono::high_resolution_clock::now();
        avg+=(end-start);
        std::cout << "\n\n";
    }

    std::cout<<"\nAverage ms: "<<std::chrono::duration_cast<std::chrono::milliseconds>(avg/10);
}