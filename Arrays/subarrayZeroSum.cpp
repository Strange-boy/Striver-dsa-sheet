#include <bits/stdc++.h>
using namespace std;


//in order to find the optimal answer for the problem
//Time complexity: O(Nlog(N))
//Space complexity: O(N)
int optimalLongestSubarray(vector<int> &nums){
    map<int,int> prefixMap;

    int sum = 0;
    int maxLength = 0;

    for(int idx = 0; idx < nums.size(); idx += 1){
        sum += nums[idx];

        if(sum == 0){
            maxLength = idx + 1;
        } else {
            if(prefixMap.find(sum) != prefixMap.end()){
                int currLength = idx - prefixMap[sum];
                maxLength = max(maxLength, currLength);
            } else {
                prefixMap[sum] = idx;
            }
        }
    }

    return maxLength;
}

//TC : O(N^2)
//SC: O(1)
int getLongestSubarrayWithZeroSum(vector<int> &nums){
    int maxLength = 0;

    for(int first = 0; first < nums.size(); first += 1){
        int sum = 0;
        for(int second = first; second < nums.size(); second += 1){
            sum += nums[second];

            if(sum == 0){
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

    vector<int> nums(length);

    //in order to take the input elements
    for(auto &element: nums){
        cin >> element;
    }

    // int maxLength = getLongestSubarrayWithZeroSum(nums);
    int maxLength = optimalLongestSubarray(nums);

    cout << maxLength << '\n';
}