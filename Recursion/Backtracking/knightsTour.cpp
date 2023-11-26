#include <bits/stdc++.h>
using namespace std;

//in order to display the board 
void displayBoard(vector<vector<int>> &board){
    for(int row = 0; row < board.size(); row += 1){
        for(int col = 0; col < board.size(); col += 1){
            cout << board[row][col] << ' ';
        }
        cout << '\n';
    }

    cout << '\n';
}

//backtracking logic to print the knights
void printKnightsTour(vector<vector<int>> &knights, int row, int col, int move){
    int limit = knights.size() * knights.size();
    //there would be all these base cases
    if(row < 0 || row >= knights.size() || col < 0 || col >= knights.size() || 
    knights[row][col] > 0){
        return;
    }

    //when the answer if found
    if(move == limit){
        knights[row][col] = move;
        displayBoard(knights);
        knights[row][col] = 0;
        return;
    }

    //there would be 8 calls
    knights[row][col] = move;
    printKnightsTour(knights, row - 2, col + 1, move + 1);
    printKnightsTour(knights, row - 1, col + 2, move + 1);
    printKnightsTour(knights, row + 1, col + 2, move + 1);
    printKnightsTour(knights, row + 2, col + 1, move + 1);

    printKnightsTour(knights, row + 2, col - 1, move + 1);
    printKnightsTour(knights, row + 1, col - 2, move + 1);
    printKnightsTour(knights, row - 1, col - 2, move + 1);
    printKnightsTour(knights, row - 2, col - 1, move + 1);
    knights[row][col] = 0;
}

int main(){
    int size;
    cin >> size;

    int row, col;
    cin >> row >> col;

    vector<vector<int>> knights(size, vector<int>(size, 0));

    printKnightsTour(knights, row, col, 1);
}