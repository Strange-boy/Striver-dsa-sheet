#include <bits/stdc++.h>
using namespace std;

//predicate function to count the number of splits
int possibleSplits(vector<int> &nums, int maxSplitValue){
    int split = 1;
    int currValue = 0;

    for(int value: nums){
        if(currValue + value > maxSplitValue){
            split += 1;
            currValue = value;
        } else {
            currValue += value;
        }
    }

    //return the splits formed
    return split;
}

// Optimal: binary search the range [max(nums), sum(nums)], find the min answer
// Time complexity: O(log(sum - max + 1)) * O(length)
int largestSubarraySumMinimized(vector<int> &nums, int split){
    int low = *max_element(nums.begin(), nums.end());
    int high = accumulate(nums.begin(), nums.end(), 0);

    while(low <= high){
        int mid = (low + high) / 2;

        int cntSplits = possibleSplits(nums, mid);
        if(cntSplits > split){
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }

    return low;
}

// Brute: form the range [max(nums), sum(nums)], find the min answer
// Time complexity: O(sum - max + 1) * O(length)
int bruteSplitArray(vector<int> &nums, int split){
    int minPossible = *max_element(nums.begin(), nums.end());
    int maxPossible = accumulate(nums.begin(), nums.end(),0);

    for(int minValue = minPossible; minValue <= maxPossible; minValue += 1){
        int cntSplits = possibleSplits(nums, minValue);
        if(cntSplits == split) return minValue;
    }

    //if the condition is not satisfied
    return -1;
}

int main(){
    int length, split;
    cin >> length >> split;

    vector<int> nums(length);

    //input
    for(auto &value: nums) cin >> value;

    int minLargeSum = bruteSplitArray(nums, split);
    cout << minLargeSum << '\n';
}