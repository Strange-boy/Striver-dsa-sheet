#include <bits/stdc++.h>
using namespace std;

//Logic: while going up , count the elements, while coming down mark them
//Recursion on way up + down
vector<int> findAllIndex(int arr[], int key, int idx, int length, int fsf){
    //base case
    if(idx == length) {
        vector<int> base(fsf, 0);
        return base;
    }

    //high level thinking
    if(arr[idx] == key){
        vector<int> idxVector = findAllIndex(arr, key, idx + 1, length, fsf + 1);
        idxVector[fsf] = idx;
        return idxVector;
    } else {
        vector<int> idxVector = findAllIndex(arr, key, idx + 1, length, fsf);
        return idxVector;
    }
}

int main(){
    int length, key;
    cin >> length >> key;

    int arr[length];

    //input 
    for(auto &element: arr) cin >> element;

    vector<int> idxVector = findAllIndex(arr, key, 0, length, 0);
    //if the array is empty => print -1
    if(idxVector.size() == 0) cout << -1;

    //if the elements are present then print all the idx
    for(auto idx: idxVector) cout << idx << ' ';
}