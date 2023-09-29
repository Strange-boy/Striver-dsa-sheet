#include <bits/stdc++.h>
using namespace std;

//optimal: binary search and elimination based on increasing-decrease fashion
int findPeakElement(vector<int> &nums){
    int length = nums.size();

    if(length == 1) return 0;

    if(nums[0] > nums[1]) return 0;
    if(nums[length - 1] > nums[length - 2]) return length - 1;

    int low = 1;
    int high = length - 2;

    while(low <= high){
        int mid = (low + high) / 2;

        //whether we found the peak element
        if(nums[mid] > nums[mid - 1] and nums[mid] > nums[mid + 1]){
            return mid;
        } else if(nums[mid] < nums[mid + 1]){
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }

    return -1;
}

//Brute: linear search and check the adjacent elements (if selected element is greater)
int bruteFindPeakElement(vector<int> &nums){
    int length = nums.size();

    //edge case
    if(length == 1) return 0;
    
    //first element check
    if(nums[0] > nums[1]) return 0;

    //last element check
    if(nums[length - 1] > nums[length - 2]) return length - 1;

    //in order to check in rest of the array
    for(int idx = 1; idx < length - 1; idx += 1){
        if((nums[idx] > nums[idx - 1]) and (nums[idx] > nums[idx + 1])){
            return idx;
        }
    }

    return -1;
}

int main(){
    int length;
    cin >> length;

    vector<int> nums(length);

    //in order to enter the elements
    for(auto &element: nums) cin >> element;

    int peakIdx = bruteFindPeakElement(nums);
    cout << peakIdx << "\n";
}