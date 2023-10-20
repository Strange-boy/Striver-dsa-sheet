#include <bits/stdc++.h>
using namespace std;

// Logic: find the index where the answer would lie
// Time complexity:O(log(N))
// Space complexity: O(1)
int findKthPositive(vector<int> &nums, int k){
    //Clean and optimised code
    int low = 0;
    int high = nums.size() - 1;

    while(low <= high){
        int mid = (low + high) / 2;

        int missing = nums[mid] - (mid + 1);
        if(missing < k) low = mid + 1;
        else high = mid - 1;
    }

    int missingNumber = k + low;
    return missingNumber;
}

// Logic: till we find value > K , keep incrementing k
// Time complexity:O(N)
// Space complexity: O(1)
int bruteFindKthPositive(vector<int> &nums, int k){
    //Clean and optimised code
    for(int value: nums){
        if(value <= k) k += 1;
        else break;
    }

    return k;
}

// Logic: Find all the missing numbers and find the kth in the list
// Time complexity:O(Constraint)
// Space complexity: O(Constraint)
int myBruteFindKthPositive(vector<int> &nums, int k){
    //in order to hash the array
    vector<bool> hash(2000, true);

    //hash the numbers which are already present 
    for(int value: nums){
        hash[value] = false;
    }

    vector<int> result;

    for(int idx = 1; idx <= 2000; idx += 1){
        if(hash[idx]) result.push_back(idx);
    }

    int missingNumber= result[k - 1];

    return missingNumber;
}

int main(){
    int length, k;
    cin >> length >> k;

    vector<int> nums(length);

    //input elements
    for(auto &value: nums) cin >> value;

    // int missingNumber = bruteFindKthPositive(nums, k);
    int missingNumber = findKthPositive(nums, k);

    cout << missingNumber << '\n';
}