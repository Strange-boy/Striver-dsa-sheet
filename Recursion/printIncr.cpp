#include <bits/stdc++.h>
using namespace std;

//in order to print the number in decreasing fashion
void printDecreasing(int number){
    //base case
    if(number == 0) return;

    //high level thinking portion
    cout << number << '\n';
    printDecreasing(number - 1);
}

int main(){
    int number;
    cin >> number;

    printDecreasing(number);
}