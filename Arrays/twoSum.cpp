#include <bits/stdc++.h>
using namespace std;

//in order to use a better approach to solve the problem
vector<int> betterTwoSum(vector<int> &nums,int target){
    map<int,int> freqMap;

    //Time complexity: O(Nlog(N))
    //Space complexity: O(N)
    
    for(int idx = 0; idx < nums.size(); idx += 1){
        int value = nums[idx];
        int moreNeeded = target - value;

        if(freqMap.find(moreNeeded) != freqMap.end()){
            return {freqMap[moreNeeded], idx};
        }

        freqMap[value] = idx;
    }

    return {-1, -1};
}

//in order to solve the problem in a brute force manner
vector<int> bruteTwoSum(vector<int> &nums, int target){
    vector<int> index;

    //o(N^2) approach to solve the problem
    for(int first = 0; first < nums.size(); first += 1){
        int value = nums[first];
        for(int second = first + 1; second < nums.size(); second += 1){
            if(nums[second] + value == target){
                index.push_back(first);
                index.push_back(second);
                break;
            }
        }
    }

    return index;
}

int main(){
    int length, target;
    cin >> length >> target;

    vector<int> nums(length);

    //in order to input the elements
    for(auto &element: nums){
        cin >> element;
    }

    // vector<int> index = bruteTwoSum(nums, target);
    vector<int> index = betterTwoSum(nums, target);


    //in order to finally print the answer
    for(auto element: index) cout << element << ' '; 
}