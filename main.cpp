#include <iostream>
#include "cmake-build-debug/Cube.h"
#include <chrono>

int main() {

    Cube cube1;
    std::cout << "Scramble 1\n";
    cube1.doMoveSequence("D B2 L' D F' U B' R' F D2 F2 B' R2 F2 B' R2 D2 L2 U2 D'");
    auto start1 = std::chrono::high_resolution_clock::now();
    std::vector<std::string> crossSolution1 = cube1.cross();
    std::cout << "Cross solution: ";
    for (const auto& move : crossSolution1) {
        std::cout  << move << " ";
    }
    std::cout << "\n";
    cube1.doMoveSequence(crossSolution1);
    std::vector<std::string> pairSolution1 = cube1.firstPair();
    std::cout << "\nPair solution: ";
    for (const std::string& move : pairSolution1) {
        std::cout << move << " ";
    }
    auto end1 = std::chrono::high_resolution_clock::now();
    auto avg = start1-end1;
    std::array<std::string,9> scrambles{
        "L2 R2 B2 U' R2 U2 F2 L2 B2 U' R2 D' R' U L' F U2 B R D R",
        "R' B2 F2 L B2 R U2 L D2 B2 R2 B' L2 R2 U' F' L2 U B'",
        "L' U2 R F2 R B2 L U2 B2 R' D2 F' L' F' D F' R B' D' B",
        "D F2 L F2 L2 D2 R B2 U2 B2 D2 F2 D' F' L R B D' L' B",
        "U R B2 D2 F2 L2 U2 L D2 R' F2 R' U R B' F2 R2 B' U",
        "L' D' R2 D2 L2 D F2 L2 U' R2 B2 R2 F R F L2 B' U2 L' D L'",
        "F2 D2 B2 R' D2 B2 F2 R D2 L B' R2 B' D' F2 D' L F2 D2",
        "L' U2 F U2 B2 D2 F' U2 R2 B D2 F U' B' L' R D' B' L F",
        "B' U2 B R2 F L2 B' D2 F R2 L B' L2 D L2 F' R' U' F2 R'"
    };
    int count = 2;
    std::cout << "\n\n";
    for(const auto& scramble : scrambles){
        std::cout << "Scramble " << count++ << ": " <<scramble<<"\n";
        Cube cube;
        cube.doMoveSequence(scramble);
        auto start = std::chrono::high_resolution_clock::now();
        std::vector<std::string> crossSolution = cube.cross();
        std::cout << "Cross solution: ";
        for (const std::string& move : crossSolution) {
            std::cout << move << " ";
        }
        std::cout << "\n";
        cube.doMoveSequence(crossSolution);
        std::vector<std::string> pairSolution = cube.firstPair();
        for (const std::string& move : pairSolution) {
            std::cout << move << " ";
        }
        auto end = std::chrono::high_resolution_clock::now();
        avg+=(end-start);
        std::cout << "\nTime for cross plus one:"<<std::chrono::duration_cast<std::chrono::milliseconds>((end-start))<<"\n\n";
    }

    std::cout<<"\nAverage ms: "<<std::chrono::duration_cast<std::chrono::milliseconds>(avg/9);
}