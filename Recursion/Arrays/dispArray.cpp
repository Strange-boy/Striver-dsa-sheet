#include <bits/stdc++.h>
using namespace std;

//in order to display the elements of the array
//Logic: Solved the problem using recursion on the way up
void displayArray(int arr[], int idx, int length){
    //base case of the recursion
    if(idx == length) return;

    //high level thinking
    cout << arr[idx] << " ";
    displayArray(arr, idx + 1, length);
}

int main(){
    int length;
    cin >> length;

    int arr[length];

    for(auto &element: arr) cin >> element;

    //invoke the function
    displayArray(arr, 0, length);
}