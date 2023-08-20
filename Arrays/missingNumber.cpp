#include <bits/stdc++.h>
using namespace std;

//in order to find the missing number by using the xor operation
int xorMissingNumber(vector<int> &nums){
    int xor1 = 0;
    int xor2 = 0;

    for(int idx = 0; idx < nums.size(); idx += 1){
        xor2 = xor2 ^ nums[idx];
        xor1 = xor1 ^ (idx + 1);
    }

    int ans = xor1 ^ xor2;
    return ans;
}

//space complexity : O(1)  Time complexity:O(N)
int optimalSumMissingNumber(vector<int> &nums){
    int maxValue = nums.size();

    int sum = maxValue * (maxValue + 1) / 2;
    int sumObtained = 0;

    for(int value: nums){
        sumObtained += value;
    }

    int ans = sum - sumObtained;
    return ans;
}

//in order to sort the number
int missingNumber(vector<int> &nums){
    //sort the array
    sort(nums.begin(), nums.end());

    int len = nums.size();
    int missingNumber = -1;

    if(nums[0] != 0){
        return 0;
    } 

    for(int idx = 1; idx < nums.size(); idx += 1){
        if(nums[idx] - nums[idx - 1] > 1){
            missingNumber = nums[idx - 1] + 1;
            break;
        }
    }

    if(nums[len - 1] != len){
        return len;
    }

    return missingNumber;
}

//in order to solve the problem using hashing approach
int hashMissingNumber(vector<int> &nums){
    int maxValue = nums.size();

    int hash[maxValue + 1] = {0};

    //now we have to iterate through the hash
    for(auto value: nums){
        hash[value] = 1;
    }

    //now we have to check for the missing number
    int missingNumber = -1;

    for(int value = 0; value <= maxValue; value += 1){
        if(hash[value] == 0){
            missingNumber = value;
            break;
        }
    }

    return missingNumber;
}

int bruteMissingNumber(vector<int> &nums){
    int maxValue =  nums.size();
    int ans = -1;

    //this approach take a O(N^2) TC
    //we have to check whether every value from [0 ..... maxValue] is present
    for(int value = 0; value <= maxValue; value += 1){
        bool found = false;

        for(auto num: nums){
            if(value == num){
                found = true;
                break;
            }
        }

        if(!found){ 
            ans = value;
            break;
        }
    }

    return ans;
}

int main(){
    int length;
    cin >> length;

    vector<int> nums(length);

    //in order to input the array elements
    for(auto &value: nums){
        cin >> value;
    }

    int value = xorMissingNumber(nums);
    cout << value ; 
}