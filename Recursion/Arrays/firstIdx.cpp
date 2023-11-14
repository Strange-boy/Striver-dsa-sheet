#include <bits/stdc++.h>
using namespace std;

//Logic: as soon as we find the element we return its idx(recursion on way up)
int findFirstIdx(int arr[], int key, int idx, int length){
    if(idx == length) return -1;
    if(arr[idx] == key) return idx;

    //high level thinking
    int firstIdx = findFirstIdx(arr, key, idx + 1, length);
    return firstIdx;
}

int main(){
    int length, key;
    cin >> length >> key;

    int arr[length];

    //input the elements
    for(auto &element: arr) cin >> element;

    int firstIdx = findFirstIdx(arr, key, 0, length);
    cout << firstIdx << '\n';
}