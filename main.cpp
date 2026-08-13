#include <iostream>
#include "cmake-build-debug/Cube.h"

int main() {
    Cube cube;

    cube.print();

    std::cout << "Solved: "
              << (cube.isSolved() ? "yes" : "no")
              << "\n";
}
