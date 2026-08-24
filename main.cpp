#include <iostream>
#include "cmake-build-debug/Cube.h"

int main() {
    Cube cube;
    cube.doMoveSequence("R U F");
    cube.print();
    std::cout << cube.crossPlusOne();


}
