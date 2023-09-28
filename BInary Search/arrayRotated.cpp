#include <bits/stdc++.h>
using namespace std;

int findRotations(int &minValue, int lowValue, int idx, int rotations){
    if(minValue > lowValue){
        minValue = lowValue;
        return idx;
    } else {
        return rotations;
    } 
}

/*
Crux: find the minimum element using binary search and return its index
time complexity: o(log(N))
space complexity: O(1)
*/
int optimalFindRotations(vector<int> &nums){
    int low = 0;
    int high = nums.size() - 1;

    int minValue = INT_MAX;
    //find the rotations
    int rotations = nums.size();

    while(low <= high){
        int mid = (low + high) / 2;

        //both are sorted
        if(nums[low] <= nums[high]){
            rotations = findRotations(minValue, nums[low], low, rotations);
            break;
        }

        //left part is sorted
        if(nums[low] <= nums[mid]){
            rotations = findRotations(minValue, nums[low], low, rotations);
            low = mid + 1;
        } else {
            //right part is sorted
            rotations = findRotations(minValue, nums[mid], mid, rotations);
            high = mid - 1;
        }
    }

    return rotations;
}


/*
Crux: find the minimum element using linear search and return its index
time complexity: o(N)
space complexity: O(1)
*/
int bruteFindRotations(vector<int> &nums){
    int rotations = 0;

    int minValue = INT_MAX;

    for(int idx = 0; idx < nums.size(); idx += 1){
        if(minValue > nums[idx]){
            minValue = nums[idx];
            rotations = idx;
        }
    }

    return rotations;
}

int main(){
    int length;
    cin >> length;

    vector<int> nums(length);

    //enter the value in the array
    for(auto &element:nums) cin >> element;

    int rotations = optimalFindRotations(nums);
    cout << rotations << '\n';
}