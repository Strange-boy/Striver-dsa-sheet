#include <bits/stdc++.h>
using namespace std;

//in order to check if it is safe to place the queen
bool isQueenSafe(vector<vector<int>> &chess, int row, int col){
    //we need to left diagonal
    for(int i = row - 1, j = col - 1; i >= 0 and j >= 0; i-- , j--){
        if(chess[i][j] == 1) return false;
    }

    //we need to check column wise
    for(int i = row - 1, j = col; i >= 0; i--){
        if(chess[i][j] == 1) return false;
    }

    //we need to check in the right diagonal
    for(int i = row - 1, j = col + 1; i >= 0 and j < chess.size(); i-- , j++){
        if(chess[i][j] == 1) return false;
    }

    //if these conditions are true
    return true;
}

//Time complexity: O(cols!)
//Space complexity: O(rows) 
void printNQueens(vector<vector<int>> &chess, string qsf, int row){
    //base case of the problem
    if(row == chess.size()){
        cout << qsf << '\n';
        return;
    }

    //high level thinking 
    for(int col = 0; col < chess.size(); col += 1){
        if(chess[row][col] == 0 and isQueenSafe(chess, row, col) == true){
            chess[row][col] = 1;
            printNQueens(chess, qsf + to_string(row) + "-" + to_string(col) + ", ", row + 1);
            chess[row][col] = 0;
        }
    }
}

int main(){
    //we need to enter the size of the chess board
    int size;
    cin >> size;

    //in order to declare a 2d vector
    vector<vector<int>> chess(size, vector<int>(size, 0));

    //we need to find the possible ways of printing nqueens
    printNQueens(chess, "", 0);
}