#include <bits/stdc++.h>
using namespace std;

//in order to solve the problem in an optimal manner
vector<int> optimalMajorityElement(vector<int> &nums){
    //here we are trying to use a modified moore's voting algorithm to solve the problem 
    int cntOne = 0;
    int cntTwo = 0;

    int elementOne = INT_MIN;
    int elementTwo = INT_MIN;

    //first we have to use the modified moore's voting algorithm
    for(int idx = 0; idx < nums.size(); idx += 1){
        if(cntOne == 0 and nums[idx] != elementTwo){
            cntOne = 1;
            elementOne = nums[idx];
        } else if(cntTwo == 0 and nums[idx] != elementOne){
            cntTwo = 1;
            elementTwo = nums[idx];
        } else if(elementOne == nums[idx]) cntOne += 1;
        else if(elementTwo == nums[idx]) cntTwo += 1;
        else {
            cntOne -= 1;
            cntTwo -= 1;
        }
    }

    vector<int> majority;

    //now we have to manually check whether the given answers are possible 
    cntOne = 0;
    cntTwo = 0;

    for(auto value: nums){
        if(value == elementOne) cntOne += 1;
        if(value == elementTwo) cntTwo += 1;
    }

    if(cntOne > nums.size() / 3) majority.push_back(elementOne);
    if(cntTwo > nums.size() / 3) majority.push_back(elementTwo);

    sort(majority.begin(), majority.end());

    return majority;
}

//in order to solve the answer by using maps
vector<int> betterMajorityElement(vector<int> &nums){
    map<int,int> freqMap;

    //in order to store the answer
    vector<int> majority;

    int minOccurence = nums.size() / 3 + 1;

    for(auto value: nums){
        freqMap[value] += 1;
        if(freqMap[value] == minOccurence) majority.push_back(value);

        //if the size becomes greater than 2 then we have to break from the array
        //major observation
        if(majority.size() == 2) break;
    }

    //finally we have to sort the elements in the array
    sort(majority.begin(), majority.end());

    return majority;
}

//the most major observation is there would be atmost two elements in the majority array
vector<int> bruteMajorityElement(vector<int> &nums){
    //we can give the answer array by 
    vector<int> majority;
    const int reqAns = nums.size() / 3;

    //simply checkig whether each element has great than n / 2 elements

    //Time complexity: O(N^2)
    for(int value: nums){
        if(majority.size() == 0 or majority[0] != value){
            int cnt = 0;

            for(int idx = 0; idx < nums.size(); idx += 1){
                if(nums[idx] == value) cnt += 1;
            }

            if(cnt > reqAns) majority.push_back(value);
        }

        //we have to check if the size exceed two or not
        if(majority.size() == 2) break;
    }

    return majority;
}

//Time complexity of this approach -> O(nlogn) approach 
//we need to find the elements which occur more than n / 3 times
vector<int> myApproachMajorityElement(vector<int> &nums){
    int length = nums.size();
    int reqTimes = length / 3;

    // cout << "Required length: " << reqTimes << '\n';
    vector<int> majority;

    //first we need to sort the array
    sort(nums.begin(), nums.end());

    //in order to print the array
    // for(auto value: nums) cout << value << ' ';
    // cout << endl;

    int currCnt = 1;

    for(int idx = 1; idx < length; idx += 1){
        if(nums[idx] == nums[idx - 1]){
            currCnt += 1;
        } else if(nums[idx] != nums[idx - 1] and currCnt > reqTimes) {
            currCnt = 1;
            majority.push_back(nums[idx - 1]);
        } else if(nums[idx] != nums[idx - 1]){
            currCnt = 1;
        }
    }

    //if the currCnt is not zero
    if(currCnt > 0 and  currCnt > reqTimes){
        majority.push_back(nums[length - 1]);
    }

    return majority;
}

int main(){
    int length;
    cin >> length;

    vector<int> nums(length);

    //in order to enter the elements of the array
    for(auto &element: nums){
        cin >> element;
    }

    // vector<int> ans = myApproachMajorityElement(nums);
    // vector<int> ans = bruteMajorityElement(nums);
    // vector<int> ans = betterMajorityElement(nums);
    vector<int> ans = optimalMajorityElement(nums);

    //we need to print the answer
    for(auto element: ans){
        cout << element << ' ';
    }
}