#include <iostream>
#include "cmake-build-debug/Cube.h"

int main() {
    Cube cube;
    cube.doMoveSequence("");
    cube.print();

    std::cout << "\n"
              << "Is WGR paired? "
              << (cube.isPaired("WGR") ? "yes" : "no")
              << "\n";
    std::cout << "\n"
              << "Is WBR paired? "
              << (cube.isPaired("WBR") ? "yes" : "no")
              << "\n";


}
