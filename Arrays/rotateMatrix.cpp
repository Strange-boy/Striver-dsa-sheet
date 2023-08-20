#include <bits/stdc++.h>
using namespace std;

//in order to reverse the elements
void reverseRow(vector<int> &nums){
    int left = 0;
    int right = nums.size() - 1;

    while(left < right){
        swap(nums[left], nums[right]);
        left += 1;
        right -= 1;
    }
}

//in order to rotate the matrix using in place method
void optimalRotateMatrix(vector<vector<int>> &matrix){
    //time complexity: O(size * size) ||  space complexity: O(1)
    int size = matrix.size();

    //first we need to find the transpose of the matrix
    for(int row = 0; row < size - 1; row += 1){
        for(int col = row + 1; col < size; col += 1){
            //we need to swap the elements
            swap(matrix[row][col], matrix[col][row]);
        }
    }

    //then we need to reverse the elements of the matrix
    for(int row = 0; row < size; row += 1){
        reverseRow(matrix[row]);
    }
}

//in order to rotate the matrix by 90 degree
vector<vector<int>>  rotateMatrix(vector<vector<int>> &matrix){
    //time complexity and space complexity: (size * size)
    int size = matrix.size();

    vector<vector<int>> ans(size, vector(size, 0));

    //in order to store the answer in the resultant matrix
    for(int row = 0; row < size; row += 1){
        for(int col = 0; col < size; col += 1){
            ans[col][size - 1 - row] = matrix[row][col];
        }
    }

    return ans;
}

int main(){
    int size;
    cin >> size;

    vector<vector<int>> matrix(size, vector(size, 0));

    //in order to input the 2d array elements
    for(int row = 0; row < matrix.size(); row += 1){
        for(int col = 0; col < matrix[row].size(); col += 1){
            cin >> matrix[row][col];
        }
    }

    // vector<vector<int>> ans = rotateMatrix(matrix);
    optimalRotateMatrix(matrix);

    //in order to print the resultant matrix
    for(int row = 0; row < matrix.size(); row += 1){
        for(int col = 0; col < matrix[row].size(); col += 1){
            cout << matrix[row][col] << ' ';
        }
        cout << '\n';
    }
}