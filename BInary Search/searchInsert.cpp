#include <bits/stdc++.h>
using namespace std;

//optimal: binary search using lower bound 
//time complexity: O(Nlog(N))
//space complexity: O(1)
int searchInsertPosition(vector<int> &nums, int target){
    int position = nums.size();

    int low = 0;
    int high = nums.size() - 1;

    while(low <= high){
        int mid = (low + high) / 2;

        if(nums[mid] >= target){
            position = mid;
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }

    return position;
}

//in order to find the brute force approach to solve the problem
int bruteSearchInsert(vector<int> &nums, int target){
    int position = nums.size();

    for(int idx = 0; idx < nums.size(); idx += 1){
        if(nums[idx] >= target){
            position = idx;
            break;
        }
    }

    return position;
}

int main(){
    int length, target;
    cin >> length >> target;

    vector<int> nums(length);

    //in order to enter the elements
    for(auto &element: nums) cin >> element;

    int position = searchInsertPosition(nums, target);
    cout << position << '\n';
}