//in order to print the elements of the 2d matrix in a spiral manner
#include <bits/stdc++.h>
using namespace std;

//in order to print the matrix
void printMatrix(vector<vector<int>> &matrix){
    int rowSize = matrix.size();
    int colSize = matrix[0].size();

    //in order to print the matrix
    for(int row = 0; row < rowSize; row += 1){
        for(int col = 0; col < colSize; col += 1){
            cout << matrix[row][col] << ' ';
        }
        cout << '\n';
    }
}

vector<int> spiralOrder(vector<vector<int>> &matrix){
    //time complexity and space complexity: O(rowSize * colSize)
    int rowSize = matrix.size();
    int colSize = matrix[0].size();

    //in order to store the answer
    vector<int> spiral;

    //now we have to mark the all the coordinates
    int top = 0;
    int bottom = rowSize - 1;
    int left = 0;
    int right = colSize - 1;

    //this needs to continue until
    while(left <= right && top <= bottom){

        //first we have to print it in the top manner
        for(int col = left; col <= right; col += 1){
            int value = matrix[top][col];
            spiral.push_back(value);
        }

        top += 1;

        //now we have to print the right pillar of the matrix
        for(int row = top; row <= bottom; row += 1){
            int value = matrix[row][right];
            spiral.push_back(value);
        }

        right -= 1;

        if(top <= bottom){
            //now we have to print the bottom row
            for(int col = right; col >= left; col -= 1){
                int value = matrix[bottom][col];
                spiral.push_back(value);
            }

            bottom -= 1;
        }

        //we have to check for edge case in left too
        if(left <= right){
            //now we have to finally print the left pillar
            for(int row = bottom; row >= top; row -= 1){
                int value = matrix[row][left];
                spiral.push_back(value);
            }

            left += 1;
        }
    }

    return spiral;
}

int main(){
    int rowSize, colSize;
    cin >> rowSize >> colSize;

    vector<vector<int>> matrix(rowSize, vector(colSize, 0));

    for(int row = 0; row < rowSize; row += 1){
        for(int col = 0; col < colSize; col += 1){
            cin >> matrix[row][col];
        }
    }

    vector<int> spiral = spiralOrder(matrix);

    for(auto value: spiral){
        cout << value << ' ';
    }
}