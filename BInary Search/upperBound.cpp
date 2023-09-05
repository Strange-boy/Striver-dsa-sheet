#include <bits/stdc++.h>
using namespace std;


//Time complexity: O(log(N))
//Space complexity: O(1)
//in order to find the upper index of the array using binary search 
//optimal: either the answer exist (nums[mid] > target) or not
int upperBound(vector<int> &nums, int target){
    int low = 0;
    int high = nums.size() - 1;

    int upperIdx = nums.size();

    while(low <= high){
        int mid = (low + high) / 2;
        if(nums[mid] > target){
            upperIdx = mid;
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }

    return upperIdx;
}

//Time complexity: O(N)
//Space complexity: O(1)
//in order to find the upper index of the array
// Brute: simple iterate through the array and find the first element > target
int bruteUpperIdx(vector<int> &nums, int target){
    int upperIdx = nums.size();
    int lastIdx = nums.size() - 1;

    for(int idx = 0; idx < nums.size(); idx += 1){
        if(nums[idx] > target){
            upperIdx = idx;
            break;
        }
    }

    return upperIdx;
}

int main(){
    int length, target;
    cin >> length >> target;

    vector<int> nums(length);

    //enter the elements in nums array
    for(auto &element: nums) cin >> element;

    int upperIdx = bruteUpperIdx(nums, target);
    cout << upperIdx << '\n';
}