#include <bits/stdc++.h>
using namespace std;

//we need to find the single element in the sorted array
//idea: Binary search based on the odd - even arrangement of elements
//Time complexity: O(LogN)
//Space complexity: O(LogN)

int optimalSingleElement(vector<int> &nums){
    int length = nums.size();

    //edge case
    if(length == 1) return nums[0];

    //first element check
    if(nums[0] != nums[1]) return nums[0];

    //last element check
    if(nums[length - 1] != nums[length - 2]) return nums[length - 1];

    //we shrink the search space 
    int low = 1;
    int high = length - 2;

    while(low <= high){
        int mid = (low + high) / 2;

        //check whether mid element is the single element
        if(nums[mid] != nums[mid - 1] and nums[mid] != nums[mid + 1]){
            return nums[mid];
        }

        //standing of the left half -> (even , odd) check
        if((mid % 2 == 0 and nums[mid] == nums[mid + 1]) 
        or (mid % 2 != 0 and nums[mid] == nums[mid - 1])){
        //in this scenario , we have to eliminate the left half
            low = mid + 1;
        } else {
            //if we are standing of the right half, then eliminate it
            high = mid - 1;
        }
    }

    return -1;
}




//idea: just do a linear search and check for the right and left elements
//Time complexity: O(N)
//Space complexity: O(N)

int bruteSingleElement(vector<int> &nums){

    int length = nums.size();
    int singleElement = -1;

    //edge case to be taken care of
    if(length == 1) return nums[0];

    for(int idx = 1; idx < nums.size() - 1; idx += 1){
        if((nums[idx] != nums[idx - 1] )and (nums[idx] != nums[idx + 1])){
            singleElement = nums[idx];
            break;
        }
    }

    //we have to check for the first element
    if(nums[0] != nums[1]) singleElement = nums[0];

    //in order to check for the last element
    if(nums[length - 1] != nums[length - 2]) singleElement = nums[length - 1];

    //else if it doesn't satisfy any of these cases
    return singleElement;
}

int main(){
    int length;
    cin >> length;

    vector<int> nums(length);

    //enter the elements
    for(auto &value: nums) cin >> value;

    int element = optimalSingleElement(nums);
    cout << element << '\n';
}