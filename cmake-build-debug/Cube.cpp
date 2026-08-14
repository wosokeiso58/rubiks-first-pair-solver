//
// Created by Burge on 2026/08/13.
//

#include "Cube.h"
#include <iostream>

Cube::Cube() {
    for (int i = 0; i < 9; ++i)
        stickers[i] = 'Y';
    for (int i = 9; i < 18; ++i)
        stickers[i] = 'R';
    for (int i = 18; i < 27; ++i)
        stickers[i] = 'G';
    for (int i = 27; i < 36; ++i)
        stickers[i] = 'O';
    for (int i = 36; i < 45; ++i)
        stickers[i] = 'B';
    for (int i = 45; i < 54; ++i)
        stickers[i] = 'W';
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

void Cube::doMove(const std::string& move){
    if(move=="R"){
        turnFaceClockwise('R');
    }
    else if(move=="R2"){
        turnFaceClockwise('R');
        turnFaceClockwise('R');
    }
    else if(move=="R'"){
        turnFaceClockwise('R');
        turnFaceClockwise('R');
        turnFaceClockwise('R');
    }
    else if(move=="U"){
        turnFaceClockwise('U');
    }
    else if(move=="U2"){
        turnFaceClockwise('U');
        turnFaceClockwise('U');
    }
    else if(move=="U'"){
        turnFaceClockwise('U');
        turnFaceClockwise('U');
        turnFaceClockwise('U');
    }
    else if(move=="F"){
        turnFaceClockwise('F');
    }
    else if(move=="F2"){
        turnFaceClockwise('F');
        turnFaceClockwise('F');
    }
    else if(move=="F'"){
        turnFaceClockwise('F');
        turnFaceClockwise('F');
        turnFaceClockwise('F');
    }
    else if(move=="L"){
        turnFaceClockwise('L');
    }
    else if(move=="L2"){
        turnFaceClockwise('L');
        turnFaceClockwise('L');
    }
    else if(move=="L'"){
        turnFaceClockwise('L');
        turnFaceClockwise('L');
        turnFaceClockwise('L');
    }
    else if(move == "B"){
        turnFaceClockwise('B');
    }
    else if(move == "B2"){
        turnFaceClockwise('B');
        turnFaceClockwise('B');
    }
    else if(move == "B'"){
        turnFaceClockwise('B');
        turnFaceClockwise('B');
        turnFaceClockwise('B');
    }
    else if(move == "D"){
        turnFaceClockwise('D');
    }
    else if(move == "D2"){
        turnFaceClockwise('D');
        turnFaceClockwise('D');
    }
    else if(move == "D'"){
        turnFaceClockwise('D');
        turnFaceClockwise('D');
        turnFaceClockwise('D');
    }
    else if(move == "M"){
        turnFaceClockwise('M');
    }
    else if(move == "M2"){
        turnFaceClockwise('M');
        turnFaceClockwise('M');
    }
    else if(move == "M'"){
        turnFaceClockwise('M');
        turnFaceClockwise('M');
        turnFaceClockwise('M');
    }
    else if(move == "S"){
        turnFaceClockwise('S');
    }
    else if(move == "S2"){
        turnFaceClockwise('S');
        turnFaceClockwise('S');
    }
    else if(move == "S'"){
        turnFaceClockwise('S');
        turnFaceClockwise('S');
        turnFaceClockwise('S');
    }
    else if(move == "E"){
        turnFaceClockwise('E');
    }
    else if(move == "E2"){
        turnFaceClockwise('E');
        turnFaceClockwise('E');
    }
    else if(move == "E'"){
        turnFaceClockwise('E');
        turnFaceClockwise('E');
        turnFaceClockwise('E');
    }
}

void Cube::turnFaceClockwise(char layer){
    int faceStart = startPos[layer];

    //Rotate face corners
    char buffCorner = stickers[faceStart];
    stickers[faceStart+0]=stickers[faceStart+6];
    stickers[faceStart+6]=stickers[faceStart+8];
    stickers[faceStart+8]=stickers[faceStart+2];
    stickers[faceStart+2]=buffCorner;
    //Rotate face edges
    char buffEdge = stickers[faceStart+1];
    stickers[faceStart+1]=stickers[faceStart+3];
    stickers[faceStart+3]=stickers[faceStart+7];
    stickers[faceStart+7]=stickers[faceStart+5];
    stickers[faceStart+5]=buffEdge;

    //Adjust other layer stickers

    if(layer=='U'){
        std::array<char, 3> buffLayer = {stickers[9],stickers[10],stickers[11]};
        for(int i = 1; i<=3; i++){
            int start = i*9;
            for(int k = start; k<start+3; k++){
                stickers[k]=stickers[k+9];
            }
        }
        stickers[36]=buffLayer[0];
        stickers[37]=buffLayer[1];
        stickers[38]=buffLayer[2];
    }
    else if(layer=='L'){
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
    }
    else if(layer=='F'){
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
    }
    else if(layer=='R'){
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
    }
    else if(layer=='B'){
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
    }
    else if(layer=='D'){
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
    }
    else if(layer=='M'){
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

    }
    else if(layer=='S'){
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

    }
    else if(layer=='E'){
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

    }
    else{
        std::cout << "WTF IS THAT MOVE LMFAO";
    }







}

void Cube::print() const {
    auto p = [&](int i) { std::cout << stickers[i] << ' '; };


    std::cout << "        "; p(0); p(1); p(2); std::cout << "\n";
    std::cout << "        "; p(3); p(4); p(5); std::cout << "\n";
    std::cout << "        "; p(6); p(7); p(8); std::cout << "\n\n";

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
    std::cout << "        "; p(45); p(46); p(47); std::cout << "\n";
    std::cout << "        "; p(48); p(49); p(50); std::cout << "\n";
    std::cout << "        "; p(51); p(52); p(53); std::cout << "\n\n";


}