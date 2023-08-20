#include <bits/stdc++.h>
using namespace std;

//in order to find all the superior elements
vector<int> superiorElements(vector<int> &nums){

    vector<int> superior;
    int maxElement = 0;

    //O(N) approach to solve the problem
    //O(ans) extra space
    for(int idx = nums.size()  - 1; idx >= 0; idx -= 1){
        if(maxElement < nums[idx]){
            superior.push_back(nums[idx]);
            maxElement = nums[idx];
        }
    }

    return superior;
}

int main(){
    int length;
    cin >> length;

    vector<int> nums(length);

    //in order to take the input of the value
    for(auto &value: nums){
        cin >> value;
    }

    vector<int> superior = superiorElements(nums);

    //in order to print the superior elements
    for(auto value: superior){
        cout << value << ' ';
    }
}