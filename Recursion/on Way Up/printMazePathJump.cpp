#include <bits/stdc++.h>
using namespace std;

//Logic: using recursion on way up
//Time complexity: O(2 ^ n)
//Space complexity: O(1)
void printMazePathJump(int srcRow, int srcCol, int destRow, int destCol, string psf){

    //base case
    if(srcRow == destRow and srcCol == destCol){
        cout << psf << '\n';
        return;
    }

    //high level thinking

    //horizontal moves
    for(int hmove = 1; hmove <= destCol - srcCol; hmove += 1){
        printMazePathJump(srcRow, srcCol + hmove, destRow, destCol, psf + "h" + to_string(hmove));
    }

    //vertical moves
    for(int vmove = 1; vmove <= destRow - srcRow; vmove += 1){
        printMazePathJump(srcRow + vmove, srcCol, destRow, destCol, psf + "v" + to_string(vmove));
    }

    //diagonal moves
    for(int dmove = 1; dmove <= destCol - srcCol and dmove <= destRow - srcRow; dmove += 1){
        printMazePathJump(srcRow + dmove, srcCol + dmove, destRow, destCol, psf + "d" + to_string(dmove));
    }
}

int main(){
    int rows, cols;
    cin >> rows >> cols;

    printMazePathJump(1, 1, rows, cols, "");
}