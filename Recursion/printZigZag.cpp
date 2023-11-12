#include <bits/stdc++.h>
using namespace std;

//In order to understand the flow of recursion
void printZigZag(int number){
    //base case
    if(number == 0) return;

    
    cout << number << ' ';
    printZigZag(number - 1);
    cout << number << ' ';
    printZigZag(number - 1);
    cout << number << ' ';

}


int main(){
    int number;
    cin >> number;

    printZigZag(number);
}