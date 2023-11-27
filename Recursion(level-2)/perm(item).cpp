#include <bits/stdc++.h>
using namespace std;

//in order to display the content in box
void displayBoxes(vector<int> &boxes){
    for(int box = 0; box < boxes.size(); box += 1){
        if(boxes[box] == 0) cout << "_";
        else cout << boxes[box];
    }

    cout << '\n';
}

//here the items chooses the box
//Time complexity: O(n ^ r)
//Space complexity: O(r)
void printPermutations(vector<int> &boxes, int currItem, int totalItem){
    if(currItem > totalItem){
        displayBoxes(boxes);
        return;
    }

    //we would iterate through boxes
    for(int box = 0; box < boxes.size(); box += 1){
        if(boxes[box] == 0){
            boxes[box] = currItem;
            printPermutations(boxes, currItem + 1, totalItem);
            boxes[box] = 0;
        }
    }
}

int main(){
    int nboxes; 
    cin >> nboxes;

    vector<int> boxes(nboxes, 0);

    int rItems;
    cin >> rItems;

    //in order to print all the possible permutations
    printPermutations(boxes, 1, rItems);
}