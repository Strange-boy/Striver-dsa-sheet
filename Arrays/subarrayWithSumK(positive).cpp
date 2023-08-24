#include <bits/stdc++.h>
using namespace std;

//optimal approach to solve the problem -> Two pointer approach to solve the problem
//TC: O(2n)
int twoPointerGetLongestSubarray(vector<int> &nums, long long int sum){
    int left = 0;
    int right = 0;

    long long currSum = nums[0];
    int maxLength = 0; //in order to store the maximum length of the subarray

    while(right < nums.size()){
        //while the sum is less than k , we have to keep adding the sum
        while(left <= right and currSum > sum){
            currSum = currSum - nums[left];
            left += 1;
        }

        if(currSum == sum){
            int currLength = right - left + 1;
            maxLength = max(maxLength, currLength);
        }

        right += 1;
        if(right < nums.size()) currSum += nums[right];
    }

    return maxLength;
}

//hashing + prefix method to solve the problem
int hashGetLongestSubarray(vector<int> &nums, long long int sum){
    map<long long int, int> prefixSumMap;

    long long int totalSum = 0;
    int maxLength = 0;

    for(int idx = 0; idx < nums.size(); idx += 1){
        totalSum = totalSum + nums[idx];

        if(totalSum == sum){
            int currLength = idx + 1;
            maxLength = max(maxLength, currLength);
        }

        long long int rem = totalSum - sum;

        if(prefixSumMap.find(rem) != prefixSumMap.end()){
            int currLength = idx - prefixSumMap[rem];
            maxLength = max(maxLength, currLength);
        }

        //we have to take the leftest value of the array
        //We have to consider the 0 in the array too
        if(prefixSumMap.find(totalSum) == prefixSumMap.end()){
            prefixSumMap[totalSum] = idx;
        }
    }

    return maxLength;
}

//time complexity: O(N^2) approach 
int getLongestSubarray(vector<int> &nums, long long int sum){
    int maxLength = 0;

    //here we could use the double loop approach to solve the problem
    for(int first = 0; first < nums.size(); first += 1){
        long long currSum = 0; //in order to set the current sum
        for(int second = first; second < nums.size(); second += 1){
            currSum = currSum + nums[second];

            if(currSum == sum){
                int currLength = second - first + 1;
                maxLength = max(currLength, maxLength);
            }
        }
    }

    return maxLength;
}

int main(){
    int length;
    cin >> length;

    long long int sum;
    cin >> sum;

    vector<int> nums(length);

    //in order to enter the elements of the array
    for(auto &element: nums){
        cin >> element;
    }

    // int longestSubarray = getLongestSubarray(nums, sum);
    // int longestSubarray = hashGetLongestSubarray(nums, sum);
    int longestSubarray = twoPointerGetLongestSubarray(nums, sum);

    cout << longestSubarray << '\n';
}