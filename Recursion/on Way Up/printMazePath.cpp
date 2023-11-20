#include <bits/stdc++.h>
using namespace std;

//Logic: recursion on way up to print the paths
//Time complexity: O(2^n)
//Space complexity: O(1)

void printMazePaths(int srcRow, int srcCol, int destRow, int destCol, string asf){
    //edge base case
    if(srcRow > destRow or srcCol > destCol){
        return;
    }

    //answer base case
    if(srcRow == destRow and srcCol == destCol){
        cout << asf << '\n';
        return;
    }

    //high level thinking 
    printMazePaths(srcRow, srcCol + 1, destRow, destCol, asf + "h");
    printMazePaths(srcRow + 1, srcCol, destRow, destCol, asf + "v");
}

int main(){
    int rows, cols;
    cin >> rows >> cols;

    printMazePaths(1, 1, rows, cols, "");
}