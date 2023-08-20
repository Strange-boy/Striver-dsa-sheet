#include <bits/stdc++.h>
using namespace std;

//in order to check whether the given array is sorted or not
int sortedArray(vector<int> nums, int n){
    int ans = 1;

    for(int idx = 1; idx < nums.size(); idx += 1){
        if(nums[idx - 1] > nums[idx]){
            ans = 0;
            break;
        }
    }

    return ans;
}

int main(){
    int length;
    cin >> length;

    vector<int> nums(length);

    //in order to take the input
    for(auto &value: nums){
        cin >> value;
    }

    int ans = sortedArray(nums, length);
    cout << ans << '\n';
}