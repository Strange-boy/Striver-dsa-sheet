#include <bits/stdc++.h>
using namespace std;

//in order to get the majority elements
int majorityElements(vector<int> &nums){

    //in order to handle the edge case
    if(nums.size() == 1){
        return nums[0];
    }

    //O(n(logn)) complexity
    sort(nums.begin(), nums.end());

    int currCount = 0;
    int maxCurrCount = 0;
    int majorElement = 0;

    for(int idx = 1; idx < nums.size(); idx += 1){
        if(nums[idx - 1] == nums[idx]) {
            currCount += 1;
        } else if(maxCurrCount < currCount) {
            maxCurrCount = currCount;
            majorElement = nums[idx - 1];

            currCount = 0;
        } else {
            currCount = 0;
        }
    }

    //at the last we have to check again
    if(maxCurrCount < currCount){
        majorElement = nums[nums.size() - 1];
    }

    return majorElement;
}

//solving the problem using map data structure
int mapMajorityElements(vector<int> &nums){
    map<int, int> elements;
    int majorElement = -1;

    //in order to map the values to the elements
    for(auto value: nums){
        elements[value] += 1;
    }

    for(auto it:elements){
        if(it.second > (nums.size() / 2)){
            majorElement = it.first;
            break;
        }
    }

    return majorElement;
}

//in order to solve the problem using moore's voting algorithm
int optimalMajorElement(vector<int> &nums){
    int majorElement = 0;
    int cnt = 0;

    //time complexity:O(N)
    //space complexity:O(1)
    for(auto value: nums){
        if(cnt == 0){
            majorElement = value;
            cnt += 1;
        } else if(majorElement == value){
            cnt += 1;
        } else {
            cnt -= 1;
        }
    }

    //finally we have to check whether the elements we obtained are maximum elements
    int maxOccur = 0;
    for(auto value: nums){
        if(value == majorElement){
            maxOccur += 1;
        }
    }

    if(maxOccur <= (nums.size() / 2))
        majorElement = -1;
    
    return majorElement;

}

int main(){
    int length;
    cin >> length;

    vector<int> nums(length);

    //we have to take the input of the vector elements
    for(auto &value:nums) cin >> value;

    // int majorElement = majorityElements(nums);
    //in order to solve the problem using maps
    int majorElement = optimalMajorElement(nums);

    cout << majorElement << '\n';
}