#include <bits/stdc++.h>
using namespace std;

void displayBox(vector<bool> &box){
    //in order to display the content in the box
    for(int item = 0; item < box.size(); item += 1){
        if(box[item]) cout << "i";
        else cout << "_";
    }

    cout << '\n';
}

//print combination - item chooses box
void printCombination(vector<bool> &box, int selectItem, int totalItem, int lastBox){
    if(selectItem > totalItem){
        displayBox(box);
        return;
    }

    //high level thinking
    for(int currBox = lastBox + 1; currBox < box.size(); currBox += 1){
        if(!box[currBox]){
            box[currBox] = true;
            printCombination(box, selectItem + 1, totalItem, currBox);
            box[currBox] = false;
        }
    }
}

int main(){
    int nboxes, rItems;
    cin >> nboxes >> rItems;

    vector<bool> boxes(nboxes, false);

    //in order to print the combinations 
    printCombination(boxes, 1, rItems, -1);
}