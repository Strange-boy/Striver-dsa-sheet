#include <bits/stdc++.h>
using namespace std;

//Crux: handling base case(tricky) , do faith + expectatn approach
//Similar to stair path solution
vector<string> getMazePaths(int sourceRow, int sourceCol, int destRow, int destCol){
    //base case => low level thinking
    //when we would move outside the maze
    if(sourceRow > destRow or sourceCol > destCol){
        vector<string> base;
        return base;
    }

    //when we finally found the answer
    if(sourceRow == destRow and sourceCol == destCol){
        vector<string> base;
        base.push_back("");
        return base;
    }

    //high level thinking 
    vector<string> hpaths = getMazePaths(sourceRow, sourceCol + 1, destRow, destCol);
    vector<string> vpaths = getMazePaths(sourceRow + 1, sourceCol, destRow, destCol);

    vector<string> paths; //in order to store all the paths

    //first we would traverse through the horizontal paths
    for(auto hpath: hpaths){
        paths.push_back("h" + hpath);
    }

    //then we would traverse through the vertical paths
    for(auto vpath: vpaths){
        paths.push_back("v" + vpath);
    }

    return paths;
}

int main(){
    int row, col;
    cin >> row >> col;

    vector<string> paths = getMazePaths(0, 0, row - 1, col - 1);

    //in order to print all the paths
    for(auto path: paths){
        cout << path << '\n';
    }
}