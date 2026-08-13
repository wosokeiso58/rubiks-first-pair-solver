//
// Created by Burge on 2026/08/13.
//

#include "Cube.h"
#include <iostream>

Cube::Cube() {
    for (int i = 0; i < 9; ++i)
        stickers[i] = 'W';
    for (int i = 9; i < 18; ++i)
        stickers[i] = 'R';
    for (int i = 18; i < 27; ++i)
        stickers[i] = 'G';
    for (int i = 27; i < 36; ++i)
        stickers[i] = 'Y';
    for (int i = 36; i < 45; ++i)
        stickers[i] = 'O';
    for (int i = 45; i < 54; ++i)
        stickers[i] = 'B';
}

bool Cube::isSolved() const {
    for (int face = 0; face < 6; ++face) {
        int start = face * 9;
        char centre = stickers[start + 4];

        for (int i = 0; i < 9; ++i) {
            if (stickers[start + i] != centre)
                return false;
        }
    }

    return true;
}

void Cube::print() const {
    auto p = [&](int i) { std::cout << stickers[i] << ' '; };

    std::cout << "        "; p(0); p(1); p(2); std::cout << "\n";
    std::cout << "        "; p(3); p(4); p(5); std::cout << "\n";
    std::cout << "        "; p(6); p(7); p(8); std::cout << "\n\n";

    for (int row = 0; row < 3; ++row) {
        for (int i = 36 + row * 3; i < 39 + row * 3; ++i) p(i);
        std::cout << " ";
        for (int i = 18 + row * 3; i < 21 + row * 3; ++i) p(i);
        std::cout << " ";
        for (int i = 9 + row * 3; i < 12 + row * 3; ++i) p(i);
        std::cout << " ";
        for (int i = 45 + row * 3; i < 48 + row * 3; ++i) p(i);
        std::cout << "\n";
    }

    std::cout << "\n";

    std::cout << "        "; p(27); p(28); p(29); std::cout << "\n";
    std::cout << "        "; p(30); p(31); p(32); std::cout << "\n";
    std::cout << "        "; p(33); p(34); p(35); std::cout << "\n";
}