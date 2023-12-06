#include <bits/stdc++.h>
using namespace std;

//in order to display the content on the board
void displayBoard(vector<vector<int>> &chess){
    //in order to content in the chess board
    for(int row = 0; row < chess.size(); row += 1){
        for(int col = 0; col < chess[row].size(); col += 1){
            if(chess[row][col] == 0) cout << "_ ";
            else cout << "q" << chess[row][col] << " ";
        }
        cout << '\n';
    }
    cout << '\n';
}

//Time complexity: O(n^2n)
//Space complexity: O(n)
void printQueensPermutations(vector<vector<int>> &chess, int qpsf, int totalQueens){
    //base case => on placing all the queens successfully
    if(qpsf == totalQueens){
        displayBoard(chess);
        return;
    }


    //high logic => queen chooses from all the available options
    for(int row = 0; row < chess.size(); row += 1){
        for(int col = 0; col < chess[row].size(); col += 1){
            if(chess[row][col] == 0){
                chess[row][col] = qpsf + 1;
                printQueensPermutations(chess, qpsf + 1, totalQueens);
                chess[row][col] = 0;
            }
        }
    }
}

int main(){
    int size;
    cin >> size;

    // in order to declare 2d vector
    vector<vector<int>> chess(size, vector<int> (size, 0));

    printQueensPermutations(chess, 0, size);
}