#include <bits/stdc++.h>
using namespace std;

//optimal approach to solve the problem
void optimalSetZeros(vector<vector<int>> &matrix){
    //here we would use 
    //int col = matrix[0][.....]
    //int row = matrix[.....][0]

    //since there is overlapping in both cases
    int colZero = 1;

    for(int row = 0; row < matrix.size(); row += 1){
        for(int col = 0; col < matrix[row].size(); col += 1){
            if(matrix[row][col] == 0){
                //mark the row as zero
                matrix[0][col] = 0;

                //mark the column as zero (check for the 0 case)
                if(row > 0) matrix[row][0] = 0;
                else colZero = 0;
            }
        }
    }

    //now we have to mark all the elements except the first row and first col
    for(int row = 1; row < matrix.size(); row += 1){
        for(int col = 1; col < matrix[0].size(); col += 1){
            //we have to check if the row or column is zero
            if(matrix[row][0] == 0 or matrix[0][col] == 0){
                matrix[row][col] = 0;
            }
        }
    }

    if(matrix[0][0] == 0){
        for(int row = 0; row < matrix.size(); row += 1){
            matrix[row][0] = 0;
        }
    }

    //if the zero column is zero
    if(colZero == 0){
        for(int col = 0; col < matrix[0].size(); col += 1){
            matrix[0][col] = 0;
        }
    }
}


//better approach to solve the problem
void betterSetZero(vector<vector<int>> &matrix){
    //here we would just the mark the rows and columns where the zero's appear
    //TC: O(rowSize * colSize) SC: O(rowSize + colSize)
    int rowSize = matrix.size();
    int colSize = matrix[0].size();

    int markRows[rowSize] = {0};
    int markCols[colSize] = {0};

    //now we have to look for zeros and mark that particular rows and columns with that value
    for(int row = 0; row < rowSize; row += 1){
        for(int col = 0; col < colSize; col += 1){
            if(matrix[row][col] == 0){
                markRows[row] = 1;
                markCols[col] = 1;
            }
        }
    }


    for(int row = 0; row < rowSize; row += 1){
        for(int col = 0; col < colSize; col += 1){
            if(markRows[row] or markCols[col]){
                matrix[row][col] = 0;
            }
        }
    }
}

//in order to mark the rows with zero
void markRow(vector<vector<int>> &matrix, vector<vector<bool>> &markMatrix, int currRow){

    for(int col = 0; col < matrix[currRow].size(); col += 1){
        if(matrix[currRow][col] != 0) markMatrix[currRow][col] = true;
    }
}

//in order to mark the columns with -1
void markCol(vector<vector<int>> &matrix, vector<vector<bool>> &markMatrix, int currCol){
    for(int row = 0; row < matrix.size(); row += 1){
        if(matrix[row][currCol] != 0) markMatrix[row][currCol] = true;
    }
}

//brute set matrix zeros
void bruteSetZeros(vector<vector<int>> &matrix){
    //we need to set the row and column to zero
    int rowSize = matrix.size();
    int colSize = matrix[0].size();

    vector<vector<bool>> markMatrix(rowSize, vector<bool>(colSize, false));

    //TC : O(N^3)
    for(int row = 0; row < matrix.size(); row += 1){
        for(int col = 0; col < matrix[row].size(); col += 1){
            if(matrix[row][col] == 0){
                markRow(matrix, markMatrix, row);
                markCol(matrix, markMatrix, col);
            }
        }
    }

    //finally we have to mark all the elements with -1 to zero
    for(int row = 0; row < matrix.size(); row += 1){
        for(int col = 0; col < matrix[row].size(); col += 1){
            if(markMatrix[row][col] == true){
                matrix[row][col] = 0;
            }
        }
    }
}

int main(){
    int rowSize, colSize;
    cin >> rowSize >> colSize;

    vector<vector<int>> matrix;

    //input the elements of the matrix
    for(int row = 0; row < rowSize; row += 1){
        vector<int> temp;
        for(int col = 0;col < colSize; col += 1){
            int data;
            cin >> data;

            temp.push_back(data);
        }

        matrix.push_back(temp);
    }

    // bruteSetZeros(matrix);
    optimalSetZeros(matrix);

    //in order to print the elements of the ans
    for(int row = 0; row < matrix.size(); row += 1){
        for(int col = 0; col < matrix[row].size(); col += 1){
            cout << matrix[row][col] << ' ';
        }
        cout << endl;
    }
}