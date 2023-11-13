#include <bits/stdc++.h>
using namespace std;

//logic: we would use recursion on the way down
void displayArrayReverse(int arr[], int idx, int length){
    if(idx == length) return;
    
    //high level thinking
    displayArrayReverse(arr, idx + 1, length);
    cout << arr[idx] << ' ';
}

int main(){
    int length;
    cin >> length;

    int arr[length];

    // in order to enter the input
    for(auto &element: arr) cin >> element;

    displayArrayReverse(arr, 0, length);
}