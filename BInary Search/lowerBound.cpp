#include <bits/stdc++.h>
using namespace std;

//brute force: we could use linear search to find the first lower bound element
//optimal: we could use binary search to keep on finding the lower bound

int lowerBound(vector<int> &nums, int target){
    int low = 0;
    int high = nums.size() - 1;
    int ans = high + 1;

    while(low <= high){
        int mid = (low + high) / 2;

        //here there are two cases :
        //1. We found the answer
        //2. We did not found the answer
        if(target <= nums[mid]){
            ans = mid;
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }

    return ans;
}

//here we are going to try to find the lower bound of all the elements
int main(){
    int length, target;
    cin >> length >> target;

    vector<int> nums(length);

    //in order to enter the elements
    for(auto &element: nums) cin >> element;

    int lowerIdx = lowerBound(nums, target);
    cout << lowerIdx << '\n';
}