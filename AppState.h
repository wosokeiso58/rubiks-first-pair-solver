#pragma once
#include <string>
#include <vector>
#include <atomic>
#include "Cube.h"

class Cube;

struct AppState
{
    std::string scramble;
    char scrambleBuffer[256] = "";
    bool showScrambleCube = false;
    Cube scrambleCube;
    bool showCrossCube = false;
    Cube crossCube;
    bool showPairCube = false;
    Cube pairCube;
    bool solved = false;
    std::string solvedPair;
    long long solveTime = 0;
    std::atomic<bool> solving = false;

    std::vector<std::string> crossSolution;
    std::vector<std::string> pairSolution;

    std::string firstPair;
};
