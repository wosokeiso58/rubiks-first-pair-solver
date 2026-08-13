//
// Created by Burge on 2026/08/13.
//

#ifndef KEIBE_CUBE_H
#define KEIBE_CUBE_H


#pragma once

#include <array>

class Cube {
public:
    Cube();

    bool isSolved() const;
    void print() const;

private:
    std::array<char, 54> stickers;
};


#endif //KEIBE_CUBE_H
