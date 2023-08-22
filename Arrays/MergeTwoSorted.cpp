#include <bits/stdc++.h>
using namespace std;

//in order to merge the two sorted array using extra space
//Time complexity: O(N)
//Space complexity: O(N)
void mergeTwoSortedArrays(vector<int> &first,int oneSize, vector<int> &second, int twoSize){
    vector<int> merged;

    int left = 0;
    int right = 0;

    while(left < oneSize and right < twoSize){
        if(first[left] <= second[right]){
            merged.push_back(first[left]);
            left += 1;
        } else {
            merged.push_back(second[right]);
            right += 1;
        }
    }

    //now we have to put the remaining elements
    while(left < oneSize){
        merged.push_back(first[left]);
        left += 1;
    }

    while(right < twoSize){
        merged.push_back(second[right]);
        right += 1;
    }

    int currIdx = 0; //in order to keep track of the original answer
    //reassingn the elements
    for(int idx = 0; idx < first.size(); idx += 1){
        first[idx] = merged[currIdx];
        currIdx += 1;
    }
}

int main(){
    int oneSize, twoSize;
    cin >> oneSize >> twoSize;

    vector<int> first(oneSize + twoSize, 0);
    vector<int> second(twoSize);

    //in order to enter the elements into the vector
    for(int idx = 0;idx < oneSize; idx += 1){
        cin >> first[idx];
    }

    //in order to add the elements into the second vector
    for(auto &element: second){
        cin >> element;
    }

    mergeTwoSortedArrays(first, oneSize, second, twoSize);

    //now we need to print the first array
    for(auto elements: first){
        cout << elements << ' ';
    }

}