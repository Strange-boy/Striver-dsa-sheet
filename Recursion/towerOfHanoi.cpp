#include <bits/stdc++.h>
using namespace std;

//in order to print the tower of hanoi
//Logic: Just understand the flow of Euler Tree
void towerOfHanoi(int disks, int source, int destination, int helper){
    //low level thinking 
    if(disks == 0) return;

    //high level thinking
    towerOfHanoi(disks - 1, source, helper, destination);
    cout << disks << "[" << source << " -> " << destination << "]" << '\n';
    towerOfHanoi(disks - 1, helper, destination, source);
}

int main(){
    int disks;
    cin >> disks;

    int source, helper, destination;
    cin >> source >> destination >> helper;

    //print the instruction to move disks
    towerOfHanoi(disks, source, destination, helper);
}
