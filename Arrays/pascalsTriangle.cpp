#include <bits/stdc++.h>
using namespace std;

//in order to generate the rows
vector<int> generateRows(int rows){

    vector<int> ans;
    ans.push_back(1);

    int res = 1;

    for(int col = 1; col < rows; col += 1){
        res = res * (rows - col);
        res = res / col;

        ans.push_back(res);
    }

    return ans;
}

//in order to generate the pascals triangle
vector<vector<int>> pascalsTriangle(int totalRows){

    vector<vector<int>> pasTriangle;

    for(int currRow = 1; currRow <= totalRows; currRow += 1){
        vector<int> tempTriangle = generateRows(currRow);
        pasTriangle.push_back(tempTriangle);
    }

    return pasTriangle;
}

//in order to generate the pascals triangle
vector<vector<int>> generatePascalsTriangle(int numRows){
    vector<vector<int>> triangle;
    vector<int> first(1,1);

    //in order to add the first element
    triangle.push_back(first);
    if(numRows == 1) return triangle;

    vector<int> second(2, 1);

    //in order to second element
    triangle.push_back(second);
    if(numRows == 2) return triangle;

    for(int currRows = 3; currRows <= numRows; currRows += 1){
        vector<int> temp;
        for(int cols = 0; cols < currRows; cols += 1){
            int element;
            if(cols == 0 or cols == currRows - 1){
                element = 1;
            } else {
                element = triangle[currRows - 2][cols - 1] + triangle[currRows - 2][cols];
            }

            temp.push_back(element);
        }
        triangle.push_back(temp);
    }

    return triangle;
}


int main(){
    int numRows;
    cin >> numRows;

    // vector<vector<int>> triangle = generatePascalsTriangle(numRows);
    vector<vector<int>> triangle = pascalsTriangle(numRows);

    for(int rows = 0; rows < triangle.size(); rows += 1){
        for(int cols = 0; cols < triangle[rows].size(); cols += 1){
            cout << triangle[rows][cols] << ' ';
        }
        cout << '\n';
    }
}