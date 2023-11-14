#include <bits/stdc++.h>
using namespace std;

//Logic: traverse till the end of the array and find the element from last(recursion on way down)
int findLastIdx(int arr[], int key, int idx, int length){
    //base case
    if(idx == length){
        return -1;
    }

    int lisa = findLastIdx(arr, key, idx + 1, length);

    //high level thinking
    if(lisa == -1 and arr[idx] == key){
        return idx;
    } else {
        return lisa;
    }
}

int main(){
    int length, key;
    cin >> length >> key;

    int arr[length];

    //input the elements
    for(auto &element: arr) cin >> element;
    int lastIdx = findLastIdx(arr, key, 0, length);
    cout << lastIdx << '\n';
}