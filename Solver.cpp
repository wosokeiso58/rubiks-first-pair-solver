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

                    cube.doMoveSequence("zz");
                    auto cross = cube.cross();

                    cube.doMoveSequence(cross);

                    state.crossCube = cube;

                    auto pair = cube.firstPair();

                    cube.doMoveSequence(pair);

                    state.pairCube = cube;

                    state.crossSolution = cross;
                    state.pairSolution = pair;

                    state.solving = false;
                    state.solved = true;

                }).detach();
}