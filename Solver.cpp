#include <iostream>
#include <thread>
#include "Solver.h"
#include "Cube.h"

void solve(AppState& state)
{
    std::thread([&state]()
                {
                    state.solving = true;

                    Cube cube;
                    cube.doMoveSequence(state.scrambleBuffer);

                    state.scrambleCube = cube;

                    auto start = std::chrono::steady_clock::now();

                    cube.doMoveSequence("zz");

                    auto cross = cube.cross();

                    cube.doMoveSequence(cross);

                    state.crossCube = cube;

                    auto pair = cube.firstPair();
                    if(!pair.empty()){
                        state.solvedPair = pair.back();
                        std::cout<<state.solvedPair;
                        pair.pop_back();
                    }

                    auto end = std::chrono::steady_clock::now();

                    state.solveTime = std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count();

                    cube.doMoveSequence(pair);

                    state.pairCube = cube;

                    state.crossSolution = cross;
                    state.pairSolution = pair;

                    state.solving = false;
                    state.solved = true;

                }).detach();
}