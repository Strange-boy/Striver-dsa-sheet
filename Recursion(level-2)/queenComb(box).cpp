#include <bits/stdc++.h>
using namespace std;

//in order to find all possible combinations of queens
void queensCombination(int qpsf, int totalQueens, int row, int col, string asf){
    //base case of the recursion call
    if(row == totalQueens){
        if(qpsf == totalQueens){
            cout << asf << '\n';
        }
        return;
    }

    int newRow = 0;
    int newCol = 0;
    string yasf = "";
    string nasf = "";

    //when we are approaching a new column
    if(col == totalQueens - 1){
        newRow = row + 1;
        newCol = 0;
        yasf = asf + "q\n";
        nasf = asf + "-\n";
    } else {
        //case when we are in the same column
        newRow = row;
        newCol = col + 1;
        yasf = asf + "q";
        nasf = asf + "-";
    }

    //when queen chooses the box
    queensCombination(qpsf + 1, totalQueens, newRow, newCol, yasf);
    //when queen does not chooses the box
    queensCombination(qpsf, totalQueens, newRow, newCol, nasf);
    
}

int main(){
    int boardSize;
    cin >> boardSize;

    // we have to place n queens in the chess board
    queensCombination(0, boardSize, 0, 0, "");
}