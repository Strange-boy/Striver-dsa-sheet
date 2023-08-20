#include <bits/stdc++.h>
using namespace std;

//in order to print the next permutations
vector<int> nextPermutations(vector<int> &nums){

    //The way to solve this problem is :
    // 1. we have to find the first number such that A[i] < A[i + 1]
    int size = nums.size();
    int breakIdx = -1;

    for(int idx = size - 2; idx >= 0; idx -= 1){
        if(nums[idx + 1] > nums[idx]){
            breakIdx = idx;
            break;
        }
    }

    //if the break idx is -1 then we have to simply reverse the array and return the vector
    if(breakIdx == -1){
        reverse(nums.begin(), nums.end());
        return nums;
    } else {

        // 2. we have to number which is just greater than the break point and swap it with the other
        for(int idx = size - 1;idx >= 0; idx -= 1){
            if(nums[breakIdx] < nums[idx]){
                swap(nums[breakIdx], nums[idx]);
                break;
            }
        }

        // 3. we have to just the sort the remaining elements to get the final answer
        reverse(nums.begin() + breakIdx + 1, nums.end());
        return nums;
    }
}

int main(){
    int length;
    cin >> length;

    vector<int> nums(length);

    //in order to take the values
    for(auto &value: nums){
        cin >> value;
    }

    vector<int> ans = nextPermutations(nums);

    //in order to print the final values
    for(auto value: ans){
        cout << value << ' ';
    }
}