#include <string>
#include <vector>

struct AppState
{
    std::string scramble;
    char scrambleBuffer[256] = "";
    bool generateScramble = false;
    bool showCube = false;

    bool solving = false;
    bool solved = false;

    std::vector<std::string> crossSolution;
    std::vector<std::string> pairSolution;

    std::string firstPair;
};
