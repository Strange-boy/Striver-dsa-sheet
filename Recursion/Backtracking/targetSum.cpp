#include <bits/stdc++.h>
using namespace std;


//time complexity: O(2^n)
//space complexity: O(1)
void printTargetSumSubsets(vector<int> &nums, int idx, int sos, string asf, int target){
    //better base case
    if(idx == nums.size()){
        if(sos == target){
            asf += ".";
            cout << asf << '\n';
        }
        return;
    }

    //high level thinking
    //every stage => either take the number or leave the number
    printTargetSumSubsets(nums, idx + 1, sos + nums[idx], asf + to_string(nums[idx]) + ", ", target);
    printTargetSumSubsets(nums, idx + 1, sos, asf, target);
}

int main(){
    int length, target;
    cin >> length >> target;

    vector<int> nums(length);

    //in order to enter the elements in the array
    for(auto &element: nums) cin >> element;

    //in order to target sum subsets
    printTargetSumSubsets(nums, 0, 0, "", target);
}