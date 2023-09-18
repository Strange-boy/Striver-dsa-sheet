#include <bits/stdc++.h>
using namespace std;

/* 
Crux: 
1. look whether left part is sorted or right
2. find the minimum in the sorted part 
*/
int findMinElement(vector<int> &nums){
    int minElement = INT_MAX;

    int low = 0;
    int high = nums.size() - 1;

    while(low <= high){
        int mid = (low + high) / 2;

        //optimization:
        //if the array is already , nums[low] will be the answer
        if(nums[low] <= nums[high]){
            minElement = min(minElement, nums[low]);
            break;
        }

        //left part sorted
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

    //in order to enter the elements of the vector
    for(auto &elements: nums) cin >> elements;

    int minElement = findMinElement(nums);
    cout << minElement << '\n';
}