#include <bits/stdc++.h>
using namespace std;

//optimal approach to solve the problem
void moveZeros(vector<int> &nums){
    //here we would use the two pointer approach to solve the problem
    //TC: O(N)      SC:O(1)
    
    //at first we would find the index where the zero appears first
    int zeroIdx = -1;

    for(int idx = 0; idx < nums.size(); idx += 1){
        if(nums[idx] == 0){
            zeroIdx = idx;
            break;
        }
    }

    if(zeroIdx == -1) return;

    //then we go on swapping non zero elements with zero
    for(int idx = zeroIdx + 1; idx < nums.size(); idx += 1){
        if(nums[idx] != 0){
            swap(nums[idx], nums[zeroIdx]);
            zeroIdx += 1;
        }
    }
}

//in order to move the zeros
void bruteMoveZeros(vector<int> &nums){
    // TC: O(2N)  -> SC: O(Non zero elements)
    vector<int> temp;

    for(int value: nums){
        if(value != 0)
            temp.push_back(value);
    }

    for(int idx = 0; idx < temp.size(); idx += 1){
        nums[idx] = temp[idx];
    }

    //finally we have to replace with all zeros
    for(int idx = temp.size(); idx < nums.size(); idx += 1){
        nums[idx] = 0;
    }
}

int main(){
    int length;
    cin >> length;

    vector<int> nums(length);

    //in order to take the input 
    for(auto &value: nums){
        cin >> value;
    }

    bruteMoveZeros(nums);
    // moveZeros(nums);

    //print the final answer
    for(auto value: nums){
        cout << value << ' ';
    }
}