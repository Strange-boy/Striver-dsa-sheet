#include <bits/stdc++.h>
using namespace std;

//opitmal approach to solve the problem
int optimalCountSubarrayWithSumK(vector<int> &nums,int sum){
    //Time complexity : O(Nlog(N))
    //space complexity: O(N)
    int cntSubarray = 0;

    int prefixSum = 0;
    //{prefixSum, count}
    map<int, int> prefixsumMap;
    prefixsumMap[0] = 1;

    for(int idx = 0; idx < nums.size(); idx += 1){
        prefixSum = prefixSum + nums[idx];

        int remove = prefixSum - sum;
        cntSubarray = cntSubarray + prefixsumMap[remove];

        //now we need to add the count to prefixsum map
        prefixsumMap[prefixSum] += 1;
    }

    return cntSubarray;
}

//modification of the brute approach to solve the problem
int betterCountSubarrayWithSumK(vector<int> &nums,int sum){
    int cntSubarray = 0;

    for(int first = 0; first < nums.size(); first += 1){
        int subSum = 0;
        for(int second = first; second < nums.size(); second += 1){
            subSum += nums[second];

            if(subSum == sum) cntSubarray += 1;
        }
    }

    return cntSubarray;
}

//in order to count the subarray
int countSubarrayWithSumK(vector<int> &nums,int sum){
    //Time complexity: O(N^3)

    //here we would generate all the subarray and see if there is any subarray that matches the 
    //required condition

    //in order to count the subarrays
    int cntSubarray = 0;

    for(int first = 0; first < nums.size(); first += 1){
        for(int second = first; second < nums.size(); second += 1){
            
            int subSum = 0;
            //we would generate all the subarrays
            for(int idx = first; idx <= second; idx += 1){
                subSum = subSum + nums[idx];
            }

            if(subSum == sum) cntSubarray += 1;
        }
    }

    return cntSubarray;
}


int main(){
    int length, sum;
    cin >> length >> sum;

    vector<int> nums(length);

    //in order to insert the array elements
    for(auto &element: nums) cin >> element;

    // int cntSubarray = countSubarrayWithSumK(nums, sum);
    // int cntSubarray = betterCountSubarrayWithSumK(nums, sum);
    int cntSubarray = optimalCountSubarrayWithSumK(nums, sum);

    cout << cntSubarray << '\n';
}