//
// Created by Burge on 2026/08/13.
//

#include "Cube.h"
#include <iostream>

Cube::Cube() {
    for (int i = 0; i < 9; ++i)
        stickers[i] = 'W';
    for (int i = 9; i < 18; ++i)
        stickers[i] = 'O';
    for (int i = 18; i < 27; ++i)
        stickers[i] = 'G';
    for (int i = 27; i < 36; ++i)
        stickers[i] = 'R';
    for (int i = 36; i < 45; ++i)
        stickers[i] = 'B';
    for (int i = 45; i < 54; ++i)
        stickers[i] = 'Y';
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

void Cube::doRotation(const std::string &rotation) {
    if (rotation == "x") {
        std::array<char, 9> buffFace{};
        for (int i = 0; i < 9; ++i) {
            buffFace[i] = stickers[i];
            stickers[i] = stickers[i + 18];
        }
        for (int i = 18; i < 27; ++i)
            stickers[i] = stickers[i + 27];
        for (int i = 45; i < 54; ++i)
            stickers[i] = stickers[i - 9];
        for (int i = 36; i < 45; ++i)
            stickers[i] = buffFace[i - 36];
        rotateFaceStickersClockwise('D');
        rotateFaceStickersClockwise('D');
        rotateFaceStickersClockwise('B');
        rotateFaceStickersClockwise('B');
        rotateFaceStickersClockwise('R');
        rotateFaceStickersAntiClockwise('L');
    } else if (rotation == "x'") {
        std::array<char, 9> buffFace{};
        for (int i = 0; i < 9; ++i) {
            buffFace[i] = stickers[i];
            stickers[i] = stickers[i + 36];
        }
        for (int i = 36; i < 45; ++i)
            stickers[i] = stickers[i + 9];
        for (int i = 45; i < 54; ++i)
            stickers[i] = stickers[i - 27];
        for (int i = 18; i < 27; ++i)
            stickers[i] = buffFace[i - 18];
        rotateFaceStickersClockwise('U');
        rotateFaceStickersClockwise('U');
        rotateFaceStickersClockwise('B');
        rotateFaceStickersClockwise('B');
        rotateFaceStickersAntiClockwise('R');
        rotateFaceStickersClockwise('L');
    } else if (rotation == "y") {
        std::array<char, 9> buffFace{};
        for (int i = 9; i < 18; ++i) {
            buffFace[i - 9] = stickers[i];
            stickers[i] = stickers[i + 9];
        }
        for (int i = 18; i < 27; ++i)
            stickers[i] = stickers[i + 9];
        for (int i = 27; i < 36; ++i)
            stickers[i] = stickers[i + 9];
        for (int i = 36; i < 45; ++i)
            stickers[i] = buffFace[i - 36];
        rotateFaceStickersClockwise('U');
        rotateFaceStickersAntiClockwise('D');
    } else if (rotation == "y'") {
        std::array<char, 9> buffFace{};
        for (int i = 9; i < 18; ++i) {
            buffFace[i - 9] = stickers[i];
            stickers[i] = stickers[i + 27];
        }
        for (int i = 36; i < 45; ++i)
            stickers[i] = stickers[i - 9];
        for (int i = 27; i < 36; ++i)
            stickers[i] = stickers[i - 9];
        for (int i = 18; i < 27; ++i)
            stickers[i] = buffFace[i - 18];
        rotateFaceStickersAntiClockwise('U');
        rotateFaceStickersClockwise('D');
    } else if (rotation == "z") {
        std::array<char, 9> buffFace{};
        for (int i = 0; i < 9; ++i) {
            buffFace[i] = stickers[i];
            stickers[i] = stickers[i + 9];
        }
        for (int i = 9; i < 18; ++i)
            stickers[i] = stickers[i + 36];
        for (int i = 45; i < 54; ++i)
            stickers[i] = stickers[i - 18];
        for (int i = 27; i < 36; ++i)
            stickers[i] = buffFace[i - 27];
        rotateFaceStickersClockwise('F');
        rotateFaceStickersAntiClockwise('B');
        rotateFaceStickersClockwise('R');
        rotateFaceStickersClockwise('L');
        rotateFaceStickersClockwise('U');
        rotateFaceStickersClockwise('D');
    } else if (rotation == "z'") {
        std::array<char, 9> buffFace{};
        for (int i = 0; i < 9; ++i) {
            buffFace[i] = stickers[i];
            stickers[i] = stickers[i + 27];
        }
        for (int i = 27; i < 36; ++i)
            stickers[i] = stickers[i + 18];
        for (int i = 45; i < 54; ++i)
            stickers[i] = stickers[i - 36];
        for (int i = 9; i < 18; ++i)
            stickers[i] = buffFace[i - 9];
        rotateFaceStickersAntiClockwise('F');
        rotateFaceStickersClockwise('B');
        rotateFaceStickersAntiClockwise('R');
        rotateFaceStickersAntiClockwise('L');
        rotateFaceStickersAntiClockwise('U');
        rotateFaceStickersAntiClockwise('D');

    }


}

void Cube::doMoveSequence(const std::string &move) {
    int n = move.size();
    for (int k = 0; k < n; k++) {
        char curr = move[k];
        if (validChar.contains(curr)) {
            if (k < n - 1) {
                if (move[k + 1] == 'w') {
                    if (k < n - 2) {
                        if (move[k + 2] == '\'') {
                            doMovePrime(static_cast<char>(std::tolower(static_cast<unsigned char>(curr))));
                        } else if (move[k + 2] == '2') {
                            doMoveDouble(static_cast<char>(std::tolower(static_cast<unsigned char>(curr))));
                        } else {
                            doMove(static_cast<char>(std::tolower(static_cast<unsigned char>(curr))));
                        }
                    } else {
                        doMove(static_cast<char>(std::tolower(static_cast<unsigned char>(curr))));
                    }
                } else if (move[k + 1] == '\'') {
                    doMovePrime(curr);
                } else if (move[k + 1] == '2') {
                    doMoveDouble(curr);
                } else {
                    doMove(curr);
                }
            }
            else{
                doMove(curr);
            }
        }
    }
}

std::string Cube::coloursAtCorner(const std::string &corner){
    std::string colours;
    for(int i : corners[corner]){
        colours+=stickers[i];
    }
    return colours;
}
std::string Cube::coloursAtEdge(const std::string &edge){
    std::string colours;
    for(int i : edges[edge]){
        colours+=stickers[i];
    }
    return colours;
}

void Cube::doMove(const char &move) {
    if (move == 'x') {
        doRotation("x");
    } else if (move == 'y') {
        doRotation("y");
    } else if (move == 'z') {
        doRotation("z");
    } else {
        turnFaceClockwise(static_cast<char>(std::toupper(static_cast<unsigned char>(move))));
        if (move == 'r') {
            turnFaceAntiClockwise('M');
        } else if (move == 'l') {
            turnFaceClockwise('M');
        } else if (move == 'f') {
            turnFaceClockwise('S');
        } else if (move == 'b') {
            turnFaceAntiClockwise('S');
        } else if (move == 'u') {
            turnFaceAntiClockwise('E');
        } else if (move == 'd') {
            turnFaceClockwise('E');
        }
    }
}

void Cube::doMoveDouble(const char &move) {
    if (move == 'x') {
        doRotation("x'");
        doRotation("x'");
    } else if (move == 'y') {
        doRotation("y'");
        doRotation("y'");
    } else if (move == 'z') {
        doRotation("z'");
        doRotation("z'");
    } else {
        turnFaceAntiClockwise(static_cast<char>(std::toupper(static_cast<unsigned char>(move))));
        turnFaceAntiClockwise(static_cast<char>(std::toupper(static_cast<unsigned char>(move))));
        if (move == 'r') {
            turnFaceClockwise('M');
            turnFaceClockwise('M');
        } else if (move == 'l') {
            turnFaceAntiClockwise('M');
            turnFaceAntiClockwise('M');
        } else if (move == 'f') {
            turnFaceAntiClockwise('S');
            turnFaceAntiClockwise('S');

        } else if (move == 'b') {
            turnFaceClockwise('S');
            turnFaceClockwise('S');
        } else if (move == 'u') {
            turnFaceClockwise('E');
            turnFaceClockwise('E');
        } else if (move == 'd') {
            turnFaceAntiClockwise('E');
            turnFaceAntiClockwise('E');
        }
    }
}

void Cube::doMovePrime(const char &move) {
    if (move == 'x') {
        doRotation("x'");
    } else if (move == 'y') {
        doRotation("y'");
    } else if (move == 'z') {
        doRotation("z'");
    } else {
        turnFaceAntiClockwise(static_cast<char>(std::toupper(static_cast<unsigned char>(move))));
        if (move == 'r') {
            turnFaceClockwise('M');
        } else if (move == 'l') {
            turnFaceAntiClockwise('M');
        } else if (move == 'f') {
            turnFaceAntiClockwise('S');
        } else if (move == 'b') {
            turnFaceClockwise('S');
        } else if (move == 'u') {
            turnFaceClockwise('E');
        } else if (move == 'd') {
            turnFaceAntiClockwise('E');
        }
    }
}

void Cube::rotateFaceStickersClockwise(char layer) {
    int faceStart = startPos[layer];

    //Rotate face corners
    char buffCorner = stickers[faceStart];
    stickers[faceStart] = stickers[faceStart + 6];
    stickers[faceStart + 6] = stickers[faceStart + 8];
    stickers[faceStart + 8] = stickers[faceStart + 2];
    stickers[faceStart + 2] = buffCorner;
    //Rotate face edges
    char buffEdge = stickers[faceStart + 1];
    stickers[faceStart + 1] = stickers[faceStart + 3];
    stickers[faceStart + 3] = stickers[faceStart + 7];
    stickers[faceStart + 7] = stickers[faceStart + 5];
    stickers[faceStart + 5] = buffEdge;
}

void Cube::rotateFaceStickersAntiClockwise(char layer) {
    int faceStart = startPos[layer];

    //Rotate face corners
    char buffCorner = stickers[faceStart];
    stickers[faceStart] = stickers[faceStart + 2];
    stickers[faceStart + 2] = stickers[faceStart + 8];
    stickers[faceStart + 8] = stickers[faceStart + 6];
    stickers[faceStart + 6] = buffCorner;
    //Rotate face edges
    char buffEdge = stickers[faceStart + 1];
    stickers[faceStart + 1] = stickers[faceStart + 5];
    stickers[faceStart + 5] = stickers[faceStart + 7];
    stickers[faceStart + 7] = stickers[faceStart + 3];
    stickers[faceStart + 3] = buffEdge;
}

void Cube::turnFaceClockwise(char layer) {
    if (layer == 'U') {
        //Rotate stickers on face
        rotateFaceStickersClockwise(layer);
        //Adjust other layer stickers
        // Rotate corners 1
        char buffCorner1 = stickers[18];
        stickers[18] = stickers[27];
        stickers[27] = stickers[36];
        stickers[36] = stickers[9];
        stickers[9] = buffCorner1;
        //Rotate corners 2
        char buffCorner2 = stickers[20];
        stickers[20] = stickers[29];
        stickers[29] = stickers[38];
        stickers[38] = stickers[11];
        stickers[11] = buffCorner2;
        //Rotate edges
        char buffEdge1 = stickers[19];
        stickers[19] = stickers[28];
        stickers[28] = stickers[37];
        stickers[37] = stickers[10];
        stickers[10] = buffEdge1;
    } else if (layer == 'L') {
        //Rotate stickers on face
        rotateFaceStickersClockwise(layer);
        //Adjust other layer stickers
        //Rotate corners 1
        char buffCorner1 = stickers[0];
        stickers[0] = stickers[44];
        stickers[44] = stickers[45];
        stickers[45] = stickers[18];
        stickers[18] = buffCorner1;
        //Rotate corners 2
        char buffCorner2 = stickers[38];
        stickers[38] = stickers[51];
        stickers[51] = stickers[24];
        stickers[24] = stickers[6];
        stickers[6] = buffCorner2;
        //Rotate edges
        char buffEdge1 = stickers[3];
        stickers[3] = stickers[41];
        stickers[41] = stickers[48];
        stickers[48] = stickers[21];
        stickers[21] = buffEdge1;
    } else if (layer == 'F') {
        //Rotate stickers on face
        rotateFaceStickersClockwise(layer);
        //Adjust other layer stickers
        //Rotate corners 1
        char buffCorner1 = stickers[6];
        stickers[6] = stickers[17];
        stickers[17] = stickers[47];
        stickers[47] = stickers[27];
        stickers[27] = buffCorner1;
        //Rotate corners 2
        char buffCorner2 = stickers[8];
        stickers[8] = stickers[11];
        stickers[11] = stickers[45];
        stickers[45] = stickers[33];
        stickers[33] = buffCorner2;
        //Rotate edges
        char buffEdge1 = stickers[7];
        stickers[7] = stickers[14];
        stickers[14] = stickers[46];
        stickers[46] = stickers[30];
        stickers[30] = buffEdge1;
    } else if (layer == 'R') {
        //Rotate stickers on face
        rotateFaceStickersClockwise(layer);
        //Adjust other layer stickers
        //Rotate corners 1
        char buffCorner1 = stickers[2];
        stickers[2] = stickers[20];
        stickers[20] = stickers[47];
        stickers[47] = stickers[42];
        stickers[42] = buffCorner1;
        //Rotate corners 2
        char buffCorner2 = stickers[8];
        stickers[8] = stickers[26];
        stickers[26] = stickers[53];
        stickers[53] = stickers[36];
        stickers[36] = buffCorner2;
        //Rotate edges
        char buffEdge1 = stickers[5];
        stickers[5] = stickers[23];
        stickers[23] = stickers[50];
        stickers[50] = stickers[39];
        stickers[39] = buffEdge1;
    } else if (layer == 'B') {
        //Rotate stickers on face
        rotateFaceStickersClockwise(layer);
        //Adjust other layer stickers
        //Rotate corners 1
        char buffCorner1 = stickers[0];
        stickers[0] = stickers[29];
        stickers[29] = stickers[53];
        stickers[53] = stickers[15];
        stickers[15] = buffCorner1;
        //Rotate corners 2
        char buffCorner2 = stickers[2];
        stickers[2] = stickers[35];
        stickers[35] = stickers[51];
        stickers[51] = stickers[9];
        stickers[9] = buffCorner2;
        //Rotate edges
        char buffEdge1 = stickers[1];
        stickers[1] = stickers[32];
        stickers[32] = stickers[52];
        stickers[52] = stickers[12];
        stickers[12] = buffEdge1;
    } else if (layer == 'D') {
        //Rotate stickers on face
        rotateFaceStickersClockwise(layer);
        //Adjust other layer stickers
        //Rotate corners 1
        char buffCorner1 = stickers[26];
        stickers[26] = stickers[17];
        stickers[17] = stickers[44];
        stickers[44] = stickers[35];
        stickers[35] = buffCorner1;
        //Rotate corners 2
        char buffCorner2 = stickers[24];
        stickers[24] = stickers[15];
        stickers[15] = stickers[42];
        stickers[42] = stickers[33];
        stickers[33] = buffCorner2;
        //Rotate edges
        char buffEdge1 = stickers[25];
        stickers[25] = stickers[16];
        stickers[16] = stickers[43];
        stickers[43] = stickers[34];
        stickers[34] = buffEdge1;
    } else if (layer == 'M') {
        //Rotate edges 1
        char buffEdge1 = stickers[1];
        stickers[1] = stickers[43];
        stickers[43] = stickers[46];
        stickers[46] = stickers[19];
        stickers[19] = buffEdge1;
        //Rotate edges 2
        char buffEdge2 = stickers[7];
        stickers[7] = stickers[37];
        stickers[37] = stickers[52];
        stickers[52] = stickers[25];
        stickers[25] = buffEdge2;
        //Rotate centres
        char buffCentre = stickers[4];
        stickers[4] = stickers[40];
        stickers[40] = stickers[49];
        stickers[49] = stickers[22];
        stickers[22] = buffCentre;

    } else if (layer == 'S') {
        //Rotate edges 1
        char buffEdge1 = stickers[3];
        stickers[3] = stickers[16];
        stickers[16] = stickers[50];
        stickers[50] = stickers[28];
        stickers[28] = buffEdge1;
        //Rotate edges 2
        char buffEdge2 = stickers[5];
        stickers[5] = stickers[10];
        stickers[10] = stickers[48];
        stickers[48] = stickers[34];
        stickers[34] = buffEdge2;
        //Rotate centres
        char buffCentre = stickers[4];
        stickers[4] = stickers[13];
        stickers[13] = stickers[49];
        stickers[49] = stickers[31];
        stickers[31] = buffCentre;

    } else if (layer == 'E') {
        //Rotate edges 1
        char buffEdge1 = stickers[21];
        stickers[21] = stickers[12];
        stickers[12] = stickers[39];
        stickers[39] = stickers[30];
        stickers[30] = buffEdge1;
        //Rotate edges 2
        char buffEdge2 = stickers[23];
        stickers[23] = stickers[14];
        stickers[14] = stickers[41];
        stickers[41] = stickers[32];
        stickers[32] = buffEdge2;
        //Rotate centres
        char buffCentre = stickers[22];
        stickers[22] = stickers[13];
        stickers[13] = stickers[40];
        stickers[40] = stickers[31];
        stickers[31] = buffCentre;

    } else {
        std::cout << "WTF IS THAT MOVE LMFAO";
        std::cout << layer;

    }


}

void Cube::turnFaceAntiClockwise(char layer) {
    if (layer == 'U') {
        //Rotate stickers on face
        rotateFaceStickersAntiClockwise(layer);
        //Adjust other layer stickers
        //Rotate corners 1
        char buffCorner1 = stickers[18];
        stickers[18] = stickers[9];
        stickers[9] = stickers[36];
        stickers[36] = stickers[27];
        stickers[27] = buffCorner1;
        //Rotate corners 2
        char buffCorner2 = stickers[20];
        stickers[20] = stickers[11];
        stickers[11] = stickers[38];
        stickers[38] = stickers[29];
        stickers[29] = buffCorner2;
        //Rotate edges
        char buffEdge1 = stickers[19];
        stickers[19] = stickers[10];
        stickers[10] = stickers[37];
        stickers[37] = stickers[28];
        stickers[28] = buffEdge1;
    } else if (layer == 'L') {
        //Rotate stickers on face
        rotateFaceStickersAntiClockwise(layer);
        //Adjust other layer stickers
        //Rotate corners 1
        char buffCorner1 = stickers[0];
        stickers[0] = stickers[18];
        stickers[18] = stickers[45];
        stickers[45] = stickers[44];
        stickers[44] = buffCorner1;
        //Rotate corners 2
        char buffCorner2 = stickers[38];
        stickers[38] = stickers[6];
        stickers[6] = stickers[24];
        stickers[24] = stickers[51];
        stickers[51] = buffCorner2;
        //Rotate edges
        char buffEdge1 = stickers[3];
        stickers[3] = stickers[21];
        stickers[21] = stickers[48];
        stickers[48] = stickers[41];
        stickers[41] = buffEdge1;
    } else if (layer == 'F') {
        //Rotate stickers on face
        rotateFaceStickersAntiClockwise(layer);
        //Adjust other layer stickers
        //Rotate corners 1
        char buffCorner1 = stickers[6];
        stickers[6] = stickers[27];
        stickers[27] = stickers[47];
        stickers[47] = stickers[17];
        stickers[17] = buffCorner1;
        //Rotate corners 2
        char buffCorner2 = stickers[8];
        stickers[8] = stickers[33];
        stickers[33] = stickers[45];
        stickers[45] = stickers[11];
        stickers[11] = buffCorner2;
        //Rotate edges
        char buffEdge1 = stickers[7];
        stickers[7] = stickers[30];
        stickers[30] = stickers[46];
        stickers[46] = stickers[14];
        stickers[14] = buffEdge1;
    } else if (layer == 'R') {
        //Rotate stickers on face
        rotateFaceStickersAntiClockwise(layer);
        //Adjust other layer stickers
        //Rotate corners 1
        char buffCorner1 = stickers[2];
        stickers[2] = stickers[42];
        stickers[42] = stickers[47];
        stickers[47] = stickers[20];
        stickers[20] = buffCorner1;
        //Rotate corners 2
        char buffCorner2 = stickers[8];
        stickers[8] = stickers[36];
        stickers[36] = stickers[53];
        stickers[53] = stickers[26];
        stickers[26] = buffCorner2;
        //Rotate edges
        char buffEdge1 = stickers[5];
        stickers[5] = stickers[39];
        stickers[39] = stickers[50];
        stickers[50] = stickers[23];
        stickers[23] = buffEdge1;
    } else if (layer == 'B') {
        //Rotate stickers on face
        rotateFaceStickersAntiClockwise(layer);
        //Adjust other layer stickers
        //Rotate corners 1
        char buffCorner1 = stickers[0];
        stickers[0] = stickers[15];
        stickers[15] = stickers[53];
        stickers[53] = stickers[29];
        stickers[29] = buffCorner1;
        //Rotate corners 2
        char buffCorner2 = stickers[2];
        stickers[2] = stickers[9];
        stickers[9] = stickers[51];
        stickers[51] = stickers[35];
        stickers[35] = buffCorner2;
        //Rotate edges
        char buffEdge1 = stickers[1];
        stickers[1] = stickers[12];
        stickers[12] = stickers[52];
        stickers[52] = stickers[32];
        stickers[32] = buffEdge1;
    } else if (layer == 'D') {
        //Rotate stickers on face
        rotateFaceStickersAntiClockwise(layer);
        //Adjust other layer stickers
        //Rotate corners 1
        char buffCorner1 = stickers[26];
        stickers[26] = stickers[35];
        stickers[35] = stickers[44];
        stickers[44] = stickers[17];
        stickers[17] = buffCorner1;
        //Rotate corners 2
        char buffCorner2 = stickers[24];
        stickers[24] = stickers[33];
        stickers[33] = stickers[42];
        stickers[42] = stickers[15];
        stickers[15] = buffCorner2;
        //Rotate edges
        char buffEdge1 = stickers[25];
        stickers[25] = stickers[34];
        stickers[34] = stickers[43];
        stickers[43] = stickers[16];
        stickers[16] = buffEdge1;
    } else if (layer == 'M') {
        //Rotate edges 1
        char buffEdge1 = stickers[1];
        stickers[1] = stickers[19];
        stickers[19] = stickers[46];
        stickers[46] = stickers[43];
        stickers[43] = buffEdge1;
        //Rotate edges 2
        char buffEdge2 = stickers[7];
        stickers[7] = stickers[25];
        stickers[25] = stickers[52];
        stickers[52] = stickers[37];
        stickers[37] = buffEdge2;
        //Rotate centres
        char buffCentre = stickers[4];
        stickers[4] = stickers[22];
        stickers[22] = stickers[49];
        stickers[49] = stickers[40];
        stickers[40] = buffCentre;

    } else if (layer == 'S') {
        //Rotate edges 1
        char buffEdge1 = stickers[3];
        stickers[3] = stickers[28];
        stickers[28] = stickers[50];
        stickers[50] = stickers[16];
        stickers[16] = buffEdge1;
        //Rotate edges 2
        char buffEdge2 = stickers[5];
        stickers[5] = stickers[34];
        stickers[34] = stickers[48];
        stickers[48] = stickers[10];
        stickers[10] = buffEdge2;
        //Rotate centres
        char buffCentre = stickers[4];
        stickers[4] = stickers[31];
        stickers[31] = stickers[49];
        stickers[49] = stickers[13];
        stickers[13] = buffCentre;

    } else if (layer == 'E') {
        //Rotate edges 1
        char buffEdge1 = stickers[21];
        stickers[21] = stickers[30];
        stickers[30] = stickers[39];
        stickers[39] = stickers[12];
        stickers[12] = buffEdge1;
        //Rotate edges 2
        char buffEdge2 = stickers[23];
        stickers[23] = stickers[32];
        stickers[32] = stickers[41];
        stickers[41] = stickers[14];
        stickers[14] = buffEdge2;
        //Rotate centres
        char buffCentre = stickers[22];
        stickers[22] = stickers[31];
        stickers[31] = stickers[40];
        stickers[40] = stickers[13];
        stickers[13] = buffCentre;

    } else {
        std::cout << "WTF IS THAT MOVE LMFAO";
    }
}


void Cube::print() const {
    auto p = [&](int i) { std::cout << stickers[i] << ' '; };


    std::cout << "        ";
    p(0);
    p(1);
    p(2);
    std::cout << "\n";
    std::cout << "        ";
    p(3);
    p(4);
    p(5);
    std::cout << "\n";
    std::cout << "        ";
    p(6);
    p(7);
    p(8);
    std::cout << "\n\n";

    for (int row = 0; row < 3; ++row) {
        for (int i = 9 + row * 3; i < 12 + row * 3; ++i) p(i);
        std::cout << " ";
        for (int i = 18 + row * 3; i < 21 + row * 3; ++i) p(i);
        std::cout << " ";
        for (int i = 27 + row * 3; i < 30 + row * 3; ++i) p(i);
        std::cout << " ";
        for (int i = 36 + row * 3; i < 39 + row * 3; ++i) p(i);
        std::cout << "\n";
    }

    std::cout << "\n";
    std::cout << "        ";
    p(45);
    p(46);
    p(47);
    std::cout << "\n";
    std::cout << "        ";
    p(48);
    p(49);
    p(50);
    std::cout << "\n";
    std::cout << "        ";
    p(51);
    p(52);
    p(53);
    std::cout << "\n\n";


}
