#include <iostream>
#include "cmake-build-debug/Cube.h"

int main() {
    Cube cube;
    cube.doMoveSequence("U' R' F2 L D' L2 F' D U2 L2 F' U2 F' U2 B R2 B' U2 R2 F'");
    cube.print();

    std::cout << "Solved: "
              << (cube.isSolved() ? "yes" : "no")
              << "\n";
//    std::cout << cube.coloursAtCorner("UFR")<< "\n" << cube.coloursAtEdge("UF");
//    std::cout << "\n" << cube.findCorner("WGR");
//    std::cout << "\n" << cube.findCorner("GWR");
//    std::cout << "\n" << cube.findEdge("YR");
//    std::cout << "\n" << cube.findEdge("RY");

    std::cout << "\n" << cube.findPair("BRY");


}
