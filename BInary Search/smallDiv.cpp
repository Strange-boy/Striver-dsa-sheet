#include <bits/stdc++.h>
using namespace std;

bool satisfyCondition(vector<int> &nums, int div, int threshold){
    int sum = 0;

    for(auto value: nums){
        sum += ((value + div - 1) / div);
    }

    if(sum <= threshold) return true;
    else return false;
}

//Logic:iterate through range(using binary search) and find the div which satisfy the condition
//Time complexity: O(N(Log(maxValue)))
//Space complexity: O(1)
int smallestDivisor(vector<int> &nums, int threshold){
    //if the minimum sum is less than size of array
    if(nums.size() > threshold) return -1;
    
    int maxValue = -1;

    for(auto value: nums) maxValue = max(maxValue, value);

    int low = 1;
    int high = maxValue;
    int smallDiv = -1;

    while(low <= high){
        int mid = (low + high) / 2;

        if(satisfyCondition(nums, mid, threshold)){
            high = mid - 1;
            smallDiv = mid;
        } else {
            low = mid + 1;
        }
    }

    return smallDiv;
}


//Logic:iterate through range and find the div which satisfy the condition
//Time complexity: O(maxValue* N)
//Space complexity: O(1)
int bruteFindSmallDiv(vector<int> &nums, int threshold){
    //first we need to find the max number
    int maxValue = -1;

    for(auto value: nums) maxValue = max(maxValue, value);
    
    for(int div = 1; div <= maxValue; div += 1){
        if(satisfyCondition(nums, div, threshold)){
            return div;
        }
    }

    return -1;
}

int main(){
    int length, threshold;
    cin >> length >> threshold;

    vector<int> nums(length);

    //now we need to enter the elements in the vector
    for(auto &elements:nums) cin >> elements;

    //now we need to find the smallest divisor 
    // int smallDiv = bruteFindSmallDiv(nums, threshold);
    int smallDiv = smallestDivisor(nums, threshold);

    cout << smallDiv << '\n';
}