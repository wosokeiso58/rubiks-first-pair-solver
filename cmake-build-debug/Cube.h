//
// Created by Burge on 2026/08/13.
//

#ifndef KEIBE_CUBE_H
#define KEIBE_CUBE_H


#pragma once

#include <array>
#include <string>
#include <map>
#include <unordered_set>

class Cube {
public:
    Cube();

    Cube(std::array<char, 54> state);

    void print() const;

    const std::array<char, 54> &getStickers() const;

    void doMoveSequence(const std::string &move);

    std::string crossPlusOne();

    int countMisorientedEdges();


    static int heuristic(const Cube);

private:
    std::array<char, 54> stickers{};
    std::map<char,int> startPos = {{'U',0},{'L',9},{'F',18},{'R',27},{'B',36},{'D',45}};
    std::unordered_set<char> validChar{'R','r','L','l','F','f','B','b','D','d','U','u','E','S','M','x','y','z'};

    std::array<int,12> oneMove{21, 23, 30, 32, 39, 41, 12, 14, 48, 50, 46, 52};

    std::array<int,4> goodFace{46,48,50,52};
    std::array<char,4> goodEdge{46,48,50,52};

    std::array<std::string,12> testMoves = {"U","U'","F","F'","R","R'","L","L'"};

    std::map<std::string,std::array<int,3>> corners = {{"UBL",{0,38,9}},
                                                       {"UBR",{2,36,29}},
                                                       {"UFR",{8,20,27}},
                                                       {"UFL",{6,18,11}},
                                                       {"DFL",{45,24,17}},
                                                       {"DFR",{47,26,33}},
                                                       {"DBR",{53,42,35}},
                                                       {"DBL",{51,44,15}}};

    std::map<std::string,std::array<int,2>> edges = {{"UF",{7,19}},
                                                     {"UB",{1,37}},
                                                     {"UR",{5,28}},
                                                     {"UL",{3,10}},
                                                     {"FR",{23,30}},
                                                     {"FL",{21,14}},
                                                     {"DR",{50,34}},
                                                     {"DB",{52,43}},
                                                     {"DL",{48,16}},
                                                     {"DF",{46,25}},
                                                     {"BR",{39,32}},
                                                     {"BL",{41,12}}};

    std::array<std::string,4> f2l = {"WGR","WGO","WOB","WBR"};

    [[nodiscard]] bool isSolved() const;
    std::string coloursAtCorner(const std::string &corner);

    std::string findCorner(const std::string &cornerColours);
    std::string findEdge(const std::string &cornerColours) const;
    void turnFaceAntiClockwise(char layer);

    void doMovePrime(const char &move);

    void doMoveDouble(const char &move);

    void doMove(const char &move);
    void turnFaceClockwise(char layer);
    void rotateFaceStickersClockwise(char layer);
    void rotateFaceStickersAntiClockwise(char layer);
    void doRotation(const std::string &move);
    std::string coloursAtEdge(const std::string &edge);
    bool sameCorner(std::string corner1, std::string corner2);

    bool sameEdge(std::string edge1, std::string edge2) const;

    char findWhiteOfCorner(const std::string &cornerColours);
    bool isWhiteCrossSolved();
    std::string findPair(const std::string &cornerColours);

    bool isPaired(const std::string &cornerColours);

    bool isCornerSolved(const std::string &edge);

    bool isEdgeSolved(const std::string& edge);

    bool isPairSolved(const std::string& corner);
    int bestPairScore();


    bool goal();

    std::string toString();

    int countUnsolvedCrossEdges();

    int countF2LNotPaired();

};


#endif //KEIBE_CUBE_H
