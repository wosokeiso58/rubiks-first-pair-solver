#include <iostream>
#include "cmake-build-debug/Cube.h"

int main() {
    Cube cube;
    cube.doMoveSequence("");
    cube.print();

    std::cout << "Solved: "
              << (cube.isSolved() ? "yes" : "no")
              << "\n";
    std::cout << cube.coloursAtCorner("UFR")<< "\n" << cube.coloursAtEdge("UF");

}
