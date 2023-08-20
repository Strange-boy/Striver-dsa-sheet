#include <bits/stdc++.h>
using namespace std;

//efficient two pointer approach to solve the problem
int removeDuplicatesTwoPoint(vector<int> &nums){
    int numsIdx = 0;

    for(int idx = 0; idx < nums.size(); idx += 1){
        if(nums[idx] != nums[numsIdx]){
            numsIdx += 1;

            nums[numsIdx] = nums[idx];
        }
    }

    return numsIdx + 1;
}

//in order to remove the duplicate elements from the array
int removeDuplicates(vector<int> &nums){

    //-100 to 100
    int hash[203] = {0};

    //perform the hashing
    for(auto element: nums){
        hash[element + 100] += 1;
    }

    int cntValues = 0;
    int numsIdx = 0;

    for(int idx = 0; idx <= 200; idx += 1){
        if(hash[idx] > 0){
            int value = idx - 100;
            // cout << "value: " << value << " hash value: " << hash[idx] << '\n';
            cntValues += 1;
            nums[numsIdx] = value;
            numsIdx += 1;
        }
    }

    return cntValues;
}

int main(){
    int length;
    cin >> length;

    vector<int> nums(length);

    //in order to take the input
    for(auto &value: nums){
        cin >> value;
    }

    int uniqueElements = removeDuplicatesTwoPoint(nums);
    cout << uniqueElements << '\n';

    // cout << "The Final Array:\n";
    
    // for(auto value: nums){
    //     cout << value << ' ';
    // }
}