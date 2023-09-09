#include <bits/stdc++.h>
using namespace std;

//in order to find the first occurence of the element
int findFirstOccurence(vector<int> &nums,int target){
    int low = 0;
    int high = nums.size() - 1;

    int first = -1;

    while(low <= high){
        int mid = (low + high) / 2;
        if(nums[mid] == target){
            first = mid;
            high = mid - 1;
        } else if(nums[mid] < target){
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }

    return first;
}

int findLastOccurence(vector<int> &nums, int target){
    int low = 0;
    int high = nums.size() - 1;

    int last = -1;
    while(low <= high){
        int mid = (low + high) / 2;

        if(nums[mid] == target){
            last = mid;
            low = mid + 1;
        } else if(nums[mid] > target){
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }

    return last;
}

//optimal: binary search to find first and last occurence -> last - first + 1
int countOccurence(vector<int> &nums, int target){
    int first = findFirstOccurence(nums, target);

    if(first == -1) return 0;
    int last = findLastOccurence(nums, target);

    return last - first + 1;
}

int main(){
    int length, target;
    cin >> length >> target;

    vector<int> nums(length);

    //in order to enter the elements in array
    for(auto &element: nums) cin >> element;

    int cntOccur = countOccurence(nums, target);
    cout << cntOccur << '\n';
}