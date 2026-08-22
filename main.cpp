#include <iostream>
#include "cmake-build-debug/Cube.h"

int main() {
    Cube cube;
    cube.doMoveSequence("");

    cube.print();

    std::cout << "\n"
              << "Paired: "
              << (cube.isPaired("WGR") ? "yes" : "no")
              << "\n";
    std::cout << "\n"
              << "Paired: "
              << (cube.isPaired("WBR") ? "yes" : "no")
              << "\n";
    std::cout << "\n"
              << "Paired: "
              << (cube.isPaired("WGO") ? "yes" : "no")
              << "\n";
    std::cout << "\n"
              << "Paired: "
              << (cube.isPaired("WOB") ? "yes" : "no")
              << "\n";
    std::cout << "\n"
              << "Cross solved?: "
              << (cube.isWhiteCrossSolved() ? "yes" : "no")
              << "\n";


}
