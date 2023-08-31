#include <iostream>
#include <vector>
using namespace std;

/*
In case of overflow: (for instance , both are INT_MAX)
mid = low + (high - low) / 2
*/

//Time complexity: O(log(Search space))
//Space complexity: O(log(Search space))

int recursiveBinarySearch(vector<int> &nums, int low, int high, int target){
    //base case of recursion
    if(low > high) return -1;

    int mid = (low + high) / 2;
    if(target == nums[mid]) return mid;
    else if(target > nums[mid]) return recursiveBinarySearch(nums, mid + 1, high, target);
    else return recursiveBinarySearch(nums, low, mid - 1, target); // target < nums[mid]
}

//Time complexity: log(Search space)
//Space complexity: O(1)
int iterativeBinarySearch(vector<int> &nums, int target){
    //iterative approach to write the binary search code
    int low = 0;
    int high = nums.size() - 1;

    // [low .... high] -> search space
    while(low <= high){
        int mid = (low + high) / 2;

        if(target == nums[mid]){
            return mid;
        } else if(target > nums[mid]){
            low = mid + 1;
        } else {
            // target < nums[mid]
            high = mid - 1;
        }
    }

    //if we don't find the target element
    return -1;
}

int main(){
    int length, target;
    cin >> length >> target;

    vector<int> nums(length);

    //in order to input the elements
    for(auto &element: nums) cin >> element;

    // int targetIdx = iterativeBinarySearch(nums, target);
    int targetIdx = recursiveBinarySearch(nums, 0, nums.size() - 1, target);

    cout << targetIdx << '\n';
}