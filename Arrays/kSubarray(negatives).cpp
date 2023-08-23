#include <bits/stdc++.h>
using namespace std;

int getLongestSubarray(vector<int> &nums, long long int sum){
    long long totalSum = 0;
    int maxLength = 0;

    map<long long int, int> prefixSumMap;

    for(int idx = 0; idx < nums.size(); idx += 1){
        totalSum = totalSum + nums[idx];

        if(totalSum == sum){
            int currLength = idx + 1;
            maxLength = max(maxLength, currLength);
        }

        //we have to check if the remaining elements was previously stored or not
        long long int remaining = totalSum - sum;
        if(prefixSumMap.find(remaining) != prefixSumMap.end()){
            int currLength = idx - prefixSumMap[remaining];
            maxLength = max(maxLength, currLength);
        }

        //we have to consider for zero too
        if(prefixSumMap.find(totalSum) == prefixSumMap.end()){
            prefixSumMap[totalSum] = idx;
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

    //in order to input the elements
    for(auto &element: nums) cin >> element; 

    int maxLength = getLongestSubarray(nums, sum);
    cout << maxLength << '\n';
}