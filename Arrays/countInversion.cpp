/* in order to count the number of inversions in the array*/
#include <bits/stdc++.h>
using namespace std;

//Optimal: extended version of merge sort (Great idea)
//time complexity: O(Nlog(N))
//space complexity: O(N)

//we should not try to distort the original array , we should try to create a copy 
//and perform operation on it
//the main logic to merge two sorted arrays
int merge(vector<int> &nums,int low, int mid, int high){
    int left = low;
    int right = mid + 1;

    int cntInversion = 0;

    //in order to store our answer temporarily
    vector<int> temp;

    while(left <= mid and right <= high){
        if(nums[left] <= nums[right]){
            temp.push_back(nums[left]);
            left += 1;
        } else {
            temp.push_back(nums[right]);
            cntInversion += (mid - left + 1);
            right += 1;
        }
    }

    //in case the left array is still remaining
    while(left <= mid){
        temp.push_back(nums[left]);
        left += 1;
    }

    //in case the right array is still remaining
    while(right <= high){
        temp.push_back(nums[right]);
        right += 1;
    }

    //we need to store the answer in to the original array
    for(int idx = low; idx <= high; idx += 1){
        nums[idx] = temp[idx - low];
    }

    return cntInversion;
}

int mergeSort(vector<int> &nums, int low, int high){
    int cntInversion = 0;
    if(low >= high) return cntInversion;

    int mid = (low + high) / 2;
    cntInversion += mergeSort(nums, low, mid);
    cntInversion += mergeSort(nums, mid + 1, high);
    cntInversion += merge(nums, low, mid, high);

    return cntInversion;
}

int optimalCountInversion(vector<int> &nums){
    return mergeSort(nums, 0, nums.size() - 1);
}

//brute: simply use the double loop to find the number of inversion
//Time complexity: O(N^2)
//Space complexity: O(1)
int bruteCountInversion(vector<int> &nums){
    int cntInversion = 0;

    for(int first = 0; first < nums.size(); first += 1){
        for(int second = first + 1; second < nums.size(); second += 1){
            if(first < second and nums[first] > nums[second]){
                cntInversion += 1;
            }
        }
    }

    return cntInversion;
}

int main(){
    int length;
    cin >> length;

    vector<int> nums(length);

    //in order to input the vector elements
    for(auto &element: nums) cin >> element;

    int cntInversion = optimalCountInversion(nums);
    cout << cntInversion << '\n';
}