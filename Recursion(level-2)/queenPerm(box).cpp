#include <bits/stdc++.h>
using namespace std;

//Time complexity: (n + 1)^(n^2)
//space complexity: n^2
void queensPermutation(int qpsf, int totalQueens, int row, int col, string asf, vector<bool> &queensPlaced){
    //base case of the problem
    if(row == totalQueens){
        if(qpsf == totalQueens){
            cout << asf << '\n';
        }
        return;
    }


    int newRow = 0;
    int newCol = 0;
    string sep = "";

    if(col == totalQueens - 1){
        newRow = row + 1;
        newCol = 0;
        sep = "\n";
    } else {
        newRow = row;
        newCol = col + 1;
        sep = "\t";
    }

    //when we choose the queen to be placed
    for(int idx = 0; idx < totalQueens; idx += 1){
        if(queensPlaced[idx] == false){
            queensPlaced[idx] = true;
            queensPermutation(qpsf + 1, totalQueens, newRow, newCol,asf + "q"+ to_string(idx + 1) + sep ,queensPlaced);
            queensPlaced[idx] = false;
        }
    }

    //when we choose the queen to be not placed
    queensPermutation(qpsf, totalQueens, newRow, newCol, asf + "-" + sep, queensPlaced);
}

int main(){
    int boardSize;
    cin >> boardSize;

    vector<bool> queensPlaced(boardSize, false);

    queensPermutation(0, boardSize, 0, 0, "", queensPlaced);
}