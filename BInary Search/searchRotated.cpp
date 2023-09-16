#include <bits/stdc++.h>
using namespace std;

/*
Crux: 
1. we have to find whether the left portion is sorted or right
2. then we have to find whether the element lies in sorted part 
*/

//Time complexity: O(log(N))
int findElement(vector<int> &nums, int target){
    int length = nums.size();
    int low = 0;
    int high = length - 1;

    while(low <= high){
        int mid = (low + high) / 2;

        if(nums[mid] == target) {
            return mid;
        }

        //left sorted 
        if(nums[low] <= nums[mid]){
            if(nums[low] <= target and target <= nums[mid]){
                high = mid - 1;
            } else{
                low = mid + 1;
            }
        } else {
            //right sorted
            if(nums[mid] <= target and target <= nums[high]){
                low = mid + 1;
            } else {
                //eliminate the right portion
                high = mid - 1;
            }
        }
    }

    //if the element in still not found
    return -1;
}

int main(){
    int length, target;
    cin >> length >> target;

    vector<int> nums(length);

    //in order to enter the elements in the vector
    for(auto &element: nums) cin >> element;

    int idx = findElement(nums, target);

    cout << idx << '\n';
}