#include <bits/stdc++.h>
using namespace std;

//in order to sort the colors in the order of 0, 1, 2
void sortColors(vector<int> &nums){
    //here we would count the number of zeros, ones and twos
    int countZero = 0;
    int countOne = 0;
    int countTwo = 0;

    for(auto value: nums){
        if(value == 0) countZero += 1;
        else if(value == 1) countOne += 1;
        else countTwo += 1;
    }

    //Time complexity : O(3n)
    int orgIdx = 0;

    //now we have to print the zero first, then one , then two
    for(int idx = 1;idx <= countZero; idx += 1){
        nums[orgIdx] = 0;
        orgIdx += 1;
    }

    for(int idx = 1; idx <= countOne; idx += 1){
        nums[orgIdx] = 1;
        orgIdx += 1;
    }

    for(int idx = 1; idx <= countTwo; idx += 1){
        nums[orgIdx] = 2;
        orgIdx += 1;
    }
}

//here we would use the optimal approach to solve the problem
void optimalSortColors(vector<int> &nums){
    //first we need to create the three pointers
    int low = 0;
    int mid = 0;
    int high = nums.size() - 1;

    //dutch national flag algorithm
    while(mid <= high){
        if(nums[mid] == 0) {
            swap(nums[mid], nums[low]);
            low += 1;
            mid += 1;
        } else if(nums[mid] == 1){
            mid += 1;
        } else {
            swap(nums[mid], nums[high]);
            high -= 1;
        }
    }
}

int main(){
    int length;
    cin >> length;

    vector<int> nums;

    for(int idx = 0; idx < length; idx += 1){
        int color;
        cin >> color;

        nums.push_back(color);
    }

    // sortColors(nums);
    optimalSortColors(nums);

    for(auto value:nums){
        cout << value << ' ';
    }
}