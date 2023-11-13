#include <bits/stdc++.h>
using namespace std;

//Logic: here in each step, we would find the maximum in the array
int maximumArray(int arr[], int idx, int length){
    //base case 
    if(idx == length) return -1;

    int maxTillNow = maximumArray(arr, idx + 1, length);
    int maxValue = max(maxTillNow, arr[idx]);
    return maxValue;
}

int main(){
    int length;
    cin >> length;

    int arr[length];

    //in order to input the elements in array
    for(auto &element: arr) cin >> element;

    int maxElement = maximumArray(arr, 0, length);
    cout << maxElement << '\n';
}