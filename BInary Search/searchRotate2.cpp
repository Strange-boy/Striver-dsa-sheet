#include <bits/stdc++.h>
using namespace std;

/*
Crux: 
1. we have to find whether the left portion is sorted or right
2. then we have to find whether the element lies in sorted part 
3. we have to check whether the mid and low and high are not equal.
*/

//Time complexity: O(log(N))
//Worst case: O(n / 2) (shrink half of array)
bool searchElement(vector<int> &nums, int target){
    int length = nums.size();
    int low = 0;
    int high = length - 1;

    while(low <= high){
        int mid = (low + high) / 2;
        //if we find the element
        if(nums[mid] == target){
            return true;
        }

        //if the elements occured as same as mid
        if(nums[low] == nums[mid] && nums[mid] == nums[high]){
            low = low + 1;
            high = high - 1;
            continue; //as this process keeps on repeating until repetation is avoided
        }

        //left part sorted
        if(nums[low] <= nums[mid]){
            if(nums[low] <= target and target <= nums[mid]){
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        } else {
            //right part is sorted
            if(nums[mid] <= target and target <= nums[high]){
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
    }

    //if the element in not present in the search space
    return false;
}

int main(){
    int length, target;
    cin >> length >> target;

    vector<int> nums(length);

    //in order to enter the elements
    for(auto &element: nums) cin >> element;

    bool ans = searchElement(nums, target);
    if(ans) cout << "yes\n";
    else cout << "no\n";
}