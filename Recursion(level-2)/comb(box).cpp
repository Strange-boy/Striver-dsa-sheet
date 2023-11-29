#include <bits/stdc++.h>
using namespace std;

//at each level , a box either selects the item or not selects the item
//Time complexity: O(2 ^ boxes)
void printCombinations(int currBox, int totalBox, int currItem, int reqItem, string asf){
    //base case of the recursion
    if(currBox > totalBox){
        if(currItem == reqItem){
            cout << asf << '\n';
        }
        return;
    }

    //high level thinking
    //at each level, the box has two options either to put the item or not put the item
    printCombinations(currBox + 1, totalBox, currItem, reqItem, asf + "-");
    printCombinations(currBox + 1, totalBox, currItem + 1, reqItem, asf + "i");

}

int main(){
    int nboxes, ritems;
    cin >> nboxes >> ritems;

    //in order to print the permutations
    printCombinations(1, nboxes, 0, ritems, "");
}