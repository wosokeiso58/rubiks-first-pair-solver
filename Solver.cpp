#include <iostream>
#include "Solver.h"
#include "Cube.h"

void solve(AppState& state)
{
    state.solving = true;

    Cube cube;
    cube.doMoveSequence(state.scrambleBuffer);
    state.crossSolution = cube.cross();
    cube.doMoveSequence(state.crossSolution);
    state.pairSolution = cube.firstPair();
    state.solving = false;
    state.solved = true;
}