#include <bits/stdc++.h>
using namespace std;


//optimal approach to solve the problem
int optimalKadane(vector<int> &nums){
    int sum = 0;

    //O(N) time complexity
    // O(1) space complexity
    int maxSum = INT_MIN;
    int currSum = 0;

    for(int idx = 0; idx < nums.size(); idx += 1){
        currSum += nums[idx];

        if(maxSum < currSum) maxSum = currSum;

        if(currSum < 0){
            currSum = 0;
        }
    }

    return maxSum;
}

//brute force approach to solve the problem
//it gets time limit exceeded error
int bruteKadane(vector<int> &nums){
    int maxSum = nums[0];

    for(int first = 0; first < nums.size(); first += 1){
        int currSum = nums[first];

        if(maxSum < currSum) maxSum = currSum;

        for(int second = first + 1; second < nums.size(); second += 1){
            currSum = currSum + nums[second];

            if(maxSum < currSum) maxSum = currSum;
        }
    }

    return maxSum;
}

int main(){
    int length;
    cin >> length;

    vector<int> nums(length);

    //in order to input the elements of the array
    for(auto &value: nums){
        cin >> value;
    }

    //in order to find the maximum subarray sum
    int maxSum = optimalKadane(nums);
    cout << maxSum << '\n';
}