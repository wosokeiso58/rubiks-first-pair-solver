#include <iostream>
#include "cmake-build-debug/Cube.h"
#include <chrono>

int main() {
//U' F' B U B D' B D2 F' R' B2 R' U2 D2 R' U2 R2
// D' L U' R F' U L F2 L' B U2 L D2 L' F2 L D2 B2 R2 D2 R
// this scramble sucks
    Cube cube1;
    std::cout << "Scramble 1\n";
    cube1.doMoveSequence("D2 F L2 D2 F U2 F2 R2 B' D2 F' R2 U' B' R' F D U' L F' R2");
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
        "B' L B' F2 D2 L2 D' B2 U' B2 D2 R2 U' B2 L R U B' D2 F' L",
        "D2 F2 U2 R2 B2 L B2 L' B2 L D2 R U F2 D2 R D' B F2 D B'",
        "U L D' R B2 U' L R2 B U2 B U2 R2 D2 B R2 B' L2 D2 U' F",
        "U F' L2 F2 U B2 U B2 L2 D L2 F2 D' B R2 D F2 R' U L U",
        "U B' D F2 D' F R2 U' R D2 L2 U2 B' U2 F2 D2 L2 D2 R2 F2 R",
        "D2 B2 R2 B2 R2 U' R2 U2 F2 D F2 B' U F2 D2 L' B' L2 U' R'",
        "U F2 D2 F2 D2 B R D2 F' R2 L2 D B2 U D' B2 U' L2 B2",
        "B2 F2 U' L2 U2 B2 F2 U2 B2 R' D B R' U2 F' R2 D' U2 R'",
        "U2 F2 D R2 U B2 R2 F2 R2 B' U' L' D' B U2 R U' F2 L"
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
        std::cout << "\nPair solution: ";
        for (const std::string& move : pairSolution) {
            std::cout << move << " ";
        }
        auto end = std::chrono::high_resolution_clock::now();
        avg+=(end-start);
        std::cout << "\nTime for cross plus one:"<<std::chrono::duration_cast<std::chrono::milliseconds>((end-start))<<"\n\n";
    }

    std::cout<<"\nAverage ms: "<<std::chrono::duration_cast<std::chrono::milliseconds>(avg/9);
}