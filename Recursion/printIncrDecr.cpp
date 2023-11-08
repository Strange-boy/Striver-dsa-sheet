#include <bits/stdc++.h>
using namespace std;

//in order to print increasing and decreasing number
void printIncrDecr(int number){
    //base case
    if(number == 0) return;

    //recursion on the way up
    cout << number << '\n';
    printIncrDecr(number - 1);
    //recursion on the way down
    cout << number << '\n';
}

int main(){
    int number;
    cin >> number;

    printIncrDecr(number);
}