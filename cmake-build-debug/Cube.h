//
// Created by Burge on 2026/08/13.
//

#ifndef KEIBE_CUBE_H
#define KEIBE_CUBE_H


#pragma once

#include <array>
#include <string>
#include <map>

class Cube {
public:
    Cube();

    [[nodiscard]] bool isSolved() const;
    void print() const;
    void doMove(const std::string& move);
    void turnFaceClockwise(char layer);

private:
    std::array<char, 54> stickers{};
    std::map<char,int> startPos = {{'U',0},{'L',9},{'F',18},{'R',27},{'B',36},{'D',45}};
};


#endif //KEIBE_CUBE_H
