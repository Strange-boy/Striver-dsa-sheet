#include <bits/stdc++.h>
using namespace std;

//in order to print the number in decreasing fashion
void printDecreasing(int number){
    if(number == 0) return;
    
    printDecreasing(number - 1);
    cout << number << '\n';
}

int main(){
    int number;
    cin >> number;

    printDecreasing(number);
}