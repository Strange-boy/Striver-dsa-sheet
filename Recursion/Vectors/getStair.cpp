#include <bits/stdc++.h>
using namespace std;

//Logic : give three recursive calls with n - 1, n - 2 and n - 3
vector<string> getStairPaths(int stair){
    if(stair < 0){
        vector<string> base;
        return base;
    }

    //this is a valid case
    if(stair == 0){
        vector<string> base;
        base.push_back("");
        return base;
    }

    vector<string> paths1 = getStairPaths(stair - 1);
    vector<string> paths2 = getStairPaths(stair - 2);
    vector<string> paths3 = getStairPaths(stair - 3);

    //in order to store the resultant paths
    vector<string> resPaths;

    //paths with 1 jump
    for(auto path: paths1){
        resPaths.push_back(to_string(1)  + path);
    }

    //paths with 2 jump
    for(auto path: paths2){
        resPaths.push_back(to_string(2)  + path);
    }

    //paths with 3 jump
    for(auto path: paths3){
        resPaths.push_back(to_string(3)  + path);
    }

    return resPaths;
}

int main(){
    int stair;
    cin >> stair;

    vector<string> paths = getStairPaths(stair);

    //we need to print all the paths
    for(auto path: paths){
        cout << path << '\n';
    }
}