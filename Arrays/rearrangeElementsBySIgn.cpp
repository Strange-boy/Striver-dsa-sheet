#include <bits/stdc++.h>
using namespace std;


//in order to solve the problem when there are different number of positive and negative
vector<int> optimalRearrangeElementsBySignM(vector<int> &nums){
    //falling back to brute force approach 
    vector<int> positive;
    vector<int> negative;

    for(auto element: nums){
        if(element < 0) negative.push_back(element);
        else positive.push_back(element);
    }

    int minCommonSize = min(positive.size(), negative.size());

    for(int idx = 0; idx < minCommonSize; idx += 1){
        nums[idx * 2] = positive[idx];
        nums[idx * 2 + 1] = negative[idx];
    }

    //in order to handle the case when positive != negative
    int numsIdx = minCommonSize * 2;

    if(positive.size() > negative.size()){
        for(int idx = minCommonSize; idx < positive.size(); idx += 1){
            nums[numsIdx] = positive[idx];
            numsIdx += 1;
        }
    } else if(negative.size() > positive.size()){
        for(int idx = minCommonSize; idx < negative.size(); idx += 1){
            nums[numsIdx] = negative[idx];
            numsIdx += 1;
        }
    }

    return nums;
}

//optimal approach to solve the problem 
//time complexity: O(N) [single pass]
//space complexity: O(N)
vector<int> optimalRearrangeElementsBySign(vector<int> &nums){
    vector<int> ans(nums.size());

    int positiveIdx = 0;
    int negativeIdx = 1;

    for(int element: nums){
        if(element > 0){
            ans[positiveIdx] = element;
            positiveIdx += 2;
        } else {
            ans[negativeIdx] = element;
            negativeIdx += 2;
        }
    }

    return ans;
}


//time complexity: two pass solution
//space complexity: O(2N)
vector<int> bruteRearrangeElementsBySign(vector<int> &nums){
    vector<int> positive;
    vector<int> negative;

    for(int element: nums){
        if(element < 0) negative.push_back(element);
        else positive.push_back(element);
    }

    //in order to store the final answer
    vector<int> ans;

    for(int idx = 0; idx < positive.size(); idx += 1){
        ans.push_back(positive[idx]);
        ans.push_back(negative[idx]);
    }

    return ans;
}

int main(){
    int length;
    cin >> length;

    vector<int> nums(length);

    //take the input of the elements
    for(auto &elements: nums){
        cin >> elements;
    }

    vector<int> ans = optimalRearrangeElementsBySignM(nums);

    //in order to print the elements of the nums array
    for(auto elements: ans){
        cout << elements << ' ';
    }
}