#include <bits/stdc++.h>
using namespace std;

//in order to find the single element using the xor operation
int xorSingleElement(vector<int> &nums){
    int singleElement = 0;

    for(int value: nums){
        singleElement ^= value;
    }

    return singleElement;
}

//in order to find the element using hashmap
int hashmapSingleElement(vector<int> &nums){

    map<int,int> freqMap;

    for(auto value: nums){
        freqMap[value] += 1;
    }

    for(auto it: freqMap){
        if(it.second == 1){
            return it.first;
        }
    }

    return -1;
}

//in order to find the element which occurs only once
int findSingleElement(vector<int> &nums){
    int length = nums.size();

    if(length == 1){
        return nums[0];
    }

    //first we need to sort the array
    sort(nums.begin(), nums.end());

    int cnt = 1;
    int singleElement = -1;

    //we have to check for the first element and last element by brute
    //for the first element
    if(nums[0] != nums[1]){
        return nums[0];
    }

    //in order to check for the last element
    if(nums[length - 1] != nums[length - 2]){
        return nums[length - 1];
    }


    for(int idx = 0; idx < nums.size() - 1; idx += 1){
        if(nums[idx] != nums[idx + 1]){
            if(cnt == 1){
                singleElement = nums[idx];
                break;
            }

            cnt = 1;
        } else {
            cnt += 1;
        }
    }

    return singleElement;
}


int main(){
    int length;
    cin >> length;

    vector<int> nums(length);

    //in order to input the elements of the vector
    for(auto &elements: nums){
        cin >> elements;
    }

    // int singleElement = findSingleElement(nums);
    // int singleElement = hashmapSingleElement(nums);
    int singleElement = xorSingleElement(nums);

    cout << singleElement << '\n';
}