#include <bits/stdc++.h>
using namespace std;

/*
Crux:
1. check whether left or right is sorted
2. find min from the sorted part
3. if elements are equal move right and left inside by one position
*/

int findMinElement(vector<int> &nums){
    int minElement = INT_MAX;

    int low = 0;
    int high = nums.size() - 1;

    while(low <= high){
        int mid = (low + high) / 2;
        //if we found the same element then shrink the search space inside
        if(nums[low] == nums[mid] and nums[mid] == nums[high]){
            minElement = min(minElement, nums[mid]);
            // cout << "min Elment:" << minElement;
            low = low + 1;
            high = high - 1;
            continue;
        }

        //left part is sorted
        if(nums[low] <= nums[mid]){
            minElement = min(minElement, nums[low]);
            low = mid + 1;
        } else {
            //right part is sorted
            minElement = min(minElement, nums[mid]);
            high = mid - 1;
        }
    }

    return minElement;
}

int main(){
    int length;
    cin >> length;

    vector<int> nums(length);

    //enter the elements in the array
    for(auto &element: nums) cin >> element;

    int minElement = findMinElement(nums);
    cout << minElement << '\n';
}