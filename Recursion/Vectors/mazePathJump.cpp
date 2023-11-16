#include <bits/stdc++.h>
using namespace std;

//we have to find all the maze paths with jump
vector<string> getMazePathsWithJumps(int srcRow, int srcCol, int destRow, int destCol){
    //base case of the problem
    if(srcRow == destRow and srcCol == destCol){
        vector<string> base;
        base.push_back("");
        return base;
    }

    //high level thinking
    vector<string> paths; // in order to store all the current paths

    //horizontal paths
    for(int hmove = 1; hmove <= destCol - srcCol; hmove += 1){
        vector<string> hpaths = getMazePathsWithJumps(srcRow, srcCol + hmove, destRow, destCol);

        //now we need to stick the current path
        for(auto hpath: hpaths){
            paths.push_back("h" + to_string(hmove) + hpath);
        }
    }

    //vertical paths possible
    for(int vmove = 1; vmove <= destRow - srcRow; vmove += 1){
        vector<string> vpaths = getMazePathsWithJumps(srcRow + vmove, srcCol, destRow, destCol);

        //now we need to stick the current path
        for(auto vpath: vpaths){
            paths.push_back("v" + to_string(vmove) + vpath);
        }
    }

    //diagonal paths possible
    for(int dmove = 1; dmove <= destRow - srcRow and dmove <= destCol - srcCol; dmove += 1){
        vector<string> dpaths = getMazePathsWithJumps(srcRow + dmove, srcCol + dmove, destRow, destCol);

        //now we need to stick the diagonal paths
        for(auto dpath: dpaths){
            paths.push_back("d" + to_string(dmove) + dpath);
        }
    }

    return paths;
}

int main(){
    int row, col;
    cin >> row >> col;

    vector<string> paths = getMazePathsWithJumps(1, 1, row, col);

    //we have print all the possible paths
    for(auto path: paths){
        cout << path << '\n';
    }
}