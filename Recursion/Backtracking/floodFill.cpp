#include <bits/stdc++.h>
using namespace std;

//Logic : in order to find the path in the maze
//Time complexity: O(4*(n^2))
//Space complexity: O(n^2)
void floodFill(vector<vector<int>> &maze, int srcRow, int srcCol, string psf, vector<vector<bool>> &visited){
    //we need to handle all the edge cases
    int rowSize = maze.size() - 1;
    int colSize = maze[0].size() - 1;

    //if it goes outside the walls or hit the obstruction
    if(srcRow < 0 || srcRow > rowSize || srcCol < 0 || srcCol > colSize || 
        maze[srcRow][srcCol] == 1 || visited[srcRow][srcCol] == true){
        return;
    }

    //if it reaches the destination
    if(srcRow == rowSize && srcCol == colSize){
        cout << psf << '\n';
        return;
    }

    //high level thinking 
    //we need to move in this fashion => top, left , bottom , right
    //we also need to mantain a visited array to avoid the case of stack overflow
    visited[srcRow][srcCol] = true;
    floodFill(maze, srcRow - 1, srcCol, psf + "t", visited);
    floodFill(maze, srcRow, srcCol - 1, psf + "l", visited);
    floodFill(maze, srcRow + 1, srcCol, psf + "d", visited);
    floodFill(maze, srcRow, srcCol + 1, psf + "r", visited);
    visited[srcRow][srcCol] = false;

}

int main(){
    int row, col;
    cin >> row >> col;

    vector<vector<int>> maze(row, vector<int>(col, 0));

    //here we need to 2d array to mark the visited cells
    vector<vector<bool>> visited(row, vector<bool>(col, false));

    //we need to enter the values of the maze
    for(int currRow = 0; currRow < row; currRow += 1){
        for(int currCol = 0; currCol < col; currCol += 1){
            cin >> maze[currRow][currCol];
        }
    }

    //in order to call the algorithm
    floodFill(maze, 0, 0, "", visited);
}