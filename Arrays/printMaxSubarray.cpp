#include <bits/stdc++.h>
using namespace std;

//in order to print the length of the maximum subarray sum
int longestSubrraySum(vector<int> &nums){
    long long int currSum = 0;
    long long int maxSum = 0;

    int currStart = -1;
    int maxStart = -1;
    int maxEnd = -1;

    for(int idx = 0;idx < nums.size(); idx += 1){
        if(currSum == 0){
            currStart = idx;
        }

        currSum += nums[idx];

        if(maxSum < currSum){
            maxSum = currSum;
            maxStart = currStart;
            maxEnd = idx;
        }

        if(currSum < 0) currSum = 0;
    }

    int maxLength = maxEnd - maxStart;

    return maxLength;
}

int main(){
    int length;
    cin >> length;
    
    vector<int> nums(length);

    for(auto &value: nums){
        cin >> value;
    }

    int longestLength = longestSubrraySum(nums);
    cout << longestLength << '\n';
}