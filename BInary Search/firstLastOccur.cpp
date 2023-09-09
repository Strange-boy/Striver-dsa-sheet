#include <bits/stdc++.h>
using namespace std;

//in order to find the first occurence
int findFirstOccurence(vector<int> &nums, int target){
    int length = nums.size();
    int low = 0;
    int high = length - 1;
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

//in order to find the last occurence
int findLastOccurence(vector<int> &nums, int target){
    int length = nums.size();
    int low = 0;
    int high = length - 1;
    int last = -1;

    while(low <= high){
        int mid = (low + high) / 2;

        if(nums[mid] == target){
            last = mid;
            low = mid + 1;
        } else if(nums[mid] < target){
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }

    return last;
}



//optimal: using simple binary search to solve the problem
pair<int, int> binFirstLastPosition(vector<int> &nums, int target){
    int first = findFirstOccurence(nums, target);
    if(first == -1){
        return {-1, -1};
    }

    int last = findLastOccurence(nums, target);
    return {first, last};
}

//code to find the upper bound
int findUpperBound(vector<int> &nums, int target){
    int size = nums.size();
    int low = 0;
    int high = size - 1;

    int ansIdx = size;

    while(low <= high){
        int mid = (low + high) / 2;

        if(nums[mid] > target){
            ansIdx = mid;
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }

    return ansIdx;
}

//code to find the lower bound
int findLowerBound(vector<int> &nums, int target){
    int length = nums.size();
    int low = 0;
    int high = length - 1;
    
    int ansIdx = length;

    while(low <= high){
        int mid = (low + high) / 2;

        if(nums[mid] >= target){
            ansIdx = mid;
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }

    //here we have to check if we found the target elements
    if(ansIdx == length or nums[ansIdx] != target){
        ansIdx = -1;
    }

    return ansIdx;
}

//optimal:binary search - lowerBound(first occur) and upperBound(last)(edge case)
//Time complexity: O(2LogN)
pair<int, int> FirstLastPosition(vector<int> &nums, int target){
    int firstOccur = findLowerBound(nums, target);

    if(firstOccur == -1){
        return {-1, -1};
    }

    //else there exits an upper bound
    int lastOccur = findUpperBound(nums, target);

    return {firstOccur, lastOccur - 1};
}

//brute: inorder to find the first and last position via linear search
// Time complexity: O(2n)
// Space complexity: O(1)

pair<int, int> bruteFirstLastPosition(vector<int> &nums, int target){
    int firstOccur = -1;
    int lastOccur = -1;
    int length = nums.size();

    //in order to find the first occurence
    for(int idx = 0; idx < length; idx += 1){
        if(nums[idx] == target){
            firstOccur = idx;
            break;
        }
    }

    //in order to find the last occurence
    for(int idx = length - 1; idx >= 0; idx -= 1){
        if(nums[idx] == target){
            lastOccur = idx;
            break;
        }
    }

    return {firstOccur, lastOccur};
}

int main(){
    int length, target;
    cin >> length >> target;

    vector<int> nums(length);

    //in order to enter the elements
    for(auto &element: nums) cin >> element;

    pair<int, int> firstLastPos = binFirstLastPosition(nums, target);
    //in order to print the first and last position of the target element
    cout << firstLastPos.first << ' ' << firstLastPos.second << '\n';
}