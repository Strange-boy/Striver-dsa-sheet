#include <bits/stdc++.h>
using namespace std;


//binary search to find the ceil value
int getCeilValue(int nums[], int length, int target){
    int low = 0;
    int high = length - 1;

    int ans = -1;

    while(low <= high){
        int mid = (low + high) / 2;

        if(nums[mid] >= target){
            ans = nums[mid];
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }

    return ans;
}

//binary search to get the floor value
int getFloorValue(int nums[], int length, int target){
    int low = 0;
    int high = length - 1;

    int ans = -1;

    while(low <= high){
        int mid = (low + high) / 2;

        if(nums[mid] <= target){
            ans = nums[mid];
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }

    return ans;
}

pair<int, int> getFloorAndCeil(int nums[], int length, int target){
    sort(nums, nums + length);
    int ceilValue = getCeilValue(nums, length, target);
    int floorValue = getFloorValue(nums, length, target);

    return {floorValue, ceilValue};
}

//O(N) solution -> sorting + linear search

// in order to find the ceil and floor of a given number
pair<int, int> bruteCeilFloor(int nums[],int length, int target){
    //first we need to sort the elements in the array
    sort(nums, nums + length);

    int floorValue = -1;
    int ceilValue = -1;


    for(int idx = 0; idx < length; idx += 1){
        if(nums[idx] >= target){
            ceilValue = nums[idx];
            break;
        }
    }

    //now we need to find the floor value
    for(int idx = length- 1; idx >= 0; idx -= 1){
        if(nums[idx] <= target){
            floorValue = nums[idx];
            break;
        }
    }

    return {floorValue, ceilValue};
}

int main(){
    int length, target;
    cin >> length >> target;

    int nums[length];

    //in order to enter the vector elements
    for(int idx = 0; idx < length; idx += 1){
        cin >> nums[idx];
    }

    pair<int,int> ans = getFloorAndCeil(nums, length, target);
    cout << ans.first << ' ' << ans.second << '\n';
}