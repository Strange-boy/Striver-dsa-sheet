//in order to find the maximum consecutive ones in the array
#include <bits/stdc++.h>
using namespace std;

//TC: O(n) SC:O(1)
int maxConsecutiveOnes(vector<int> &nums){
    //logic to find the maximum ones
    int currOnes = 0;
    int maxOnes = 0;

    for(int idx = 0; idx < nums.size(); idx += 1){
        if(nums[idx] == 1) currOnes += 1;
        else currOnes = 0;

        maxOnes = max(maxOnes, currOnes);
    }

    return maxOnes;
}

int main(){
    int length;
    cin >> length;

    vector<int> nums(length);

    //in order to enter the elements into the array
    for(auto &elements: nums){
        cin >> elements;
    }

    int maxOnes = maxConsecutiveOnes(nums);

    //in order to print the maximum number of ones
    cout << maxOnes << '\n';
}