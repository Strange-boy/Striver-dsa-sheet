#include <bits/stdc++.h>
using namespace std;

//Logic : to print the path so far
//Time complexity: O(3^n)
//Space complexity: O(1)

void printStairPaths(int stairs, string asf){
    //base case if the answer if not found
    if(stairs < 0){
        return;
    }

    //base if the answer if found
    if(stairs == 0){
        cout << asf << '\n';
        return;
    }

    //high level thinking
    for(int move = 1; move <= 3; move += 1){
        printStairPaths(stairs - move, asf + to_string(move));
    }
}

int main(){
    int stairs;
    cin >> stairs;

    printStairPaths(stairs, "");
}