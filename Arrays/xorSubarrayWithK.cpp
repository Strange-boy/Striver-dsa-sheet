#include <bits/stdc++.h>
using namespace std;

//optimal approach to find the subarray with sum k
int optimalSubarraysWithSumK(vector<int> &nums, int target){
    //time complexity : O(Nlog(N)) or O(N) depending on the map
    //space complexity: O(N)
    int cntSubarrays = 0;
    
    map<int, int> freqMap;
    int xorValue = 0;

    freqMap[xorValue] += 1; //{0, 1}

    for(int idx = 0; idx < nums.size(); idx += 1){
        xorValue ^= nums[idx];

        int x = xorValue ^ target;
        cntSubarrays += freqMap[x];

        freqMap[xorValue] += 1;
    }

    return cntSubarrays;
}

int betterCntXorSubbarrays(vector<int> &nums, int target){
    //TC: O(N^2)
    //SC: O(1)
    int cntSubarrays = 0;

    for(int first = 0; first < nums.size(); first += 1){
        int xorValue = 0;
        for(int second = first; second < nums.size(); second += 1){
            xorValue ^= nums[second];

            if(xorValue == target) cntSubarrays += 1;
        }
    }

    return cntSubarrays;
}

//in order to find the subarray with xor k
int bruteCntXorSubbarrays(vector<int> &nums, int target){
    /*Time complexity: O(N^3) | Space complexity: O(1)*/
    int cntSubarrays = 0;

    for(int first = 0; first < nums.size(); first += 1){
        for(int second = first; second < nums.size(); second += 1){
            int xorValue = 0;

            for(int idx = first; idx <= second; idx += 1){
                xorValue ^= nums[idx];
            }

            if(xorValue == target) cntSubarrays += 1;
        }
    }

    return cntSubarrays;
}

int main(){
    int length, target;
    cin >> length >> target;

    vector<int> nums(length);

    //in order to input the values
    for(auto &element: nums){
        cin >> element;
    }

    // int cntSubarrays = bruteCntXorSubbarrays(nums, target);
    // int cntSubarrays = betterCntXorSubbarrays(nums, target);
    int cntSubarrays = optimalSubarraysWithSumK(nums, target);

    cout << cntSubarrays << '\n';
}