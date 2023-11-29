#include <bits/stdc++.h>
using namespace std;

//here box chooses items(permutations)
//Time complexity: O(r^n)
//Space complexity: O(r)
void printPermutations(int currBox, int totalBox, vector<int> &items, int selectItem, int totalItem, string asf){
    //low level thinking
    if(currBox > totalBox){
        if(selectItem == totalItem){
            cout << asf << '\n';
        }

        return;
    }

    //high level thinking
    printPermutations(currBox + 1, totalBox, items, selectItem, totalItem, asf + "_"); //selecting no items

    //selecting one of the r items and marking accordingly
    for(int currItem = 0; currItem < totalItem; currItem += 1){
        if(items[currItem] == 0){
            items[currItem] = 1;
            printPermutations(currBox + 1, totalBox, items, selectItem + 1, totalItem, asf + to_string(currItem + 1));
            items[currItem] = 0;
        }
    }
}

int main(){
    int nboxes, ritems;
    cin >> nboxes >> ritems;

    vector<int> items(ritems, 0);

    //recursive function to print permutations
    printPermutations(1, nboxes, items, 0, ritems, "");
}