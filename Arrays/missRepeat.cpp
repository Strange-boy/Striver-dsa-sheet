#include <bits/stdc++.h>
using namespace std;

//optimal: xor approach (bit manipulation)
//TC: O(N)
//SC: O(1)
vector<int> optimalMissingRepeatingXor(vector<int> &nums){
    int xorValue = 0;
    int length = nums.size();

    for(int idx = 0; idx < length; idx += 1){
        xorValue ^= nums[idx];
        xorValue ^= (idx + 1);
    }

    int bitNumber = 0; //now we have to find the bit which is set

    //logic to find the set bit
    while(true){
        if((xorValue & (1 << bitNumber)) != 0){
            break;
        }

        bitNumber += 1;
    }

    //after finding the set bit, we have to group the elements into zero and one bit club
    int zero = 0;
    int one = 0;

    //first we iterate through the elements in the array
    for(int idx = 0; idx < length; idx += 1){
        if((nums[idx] & (1 << bitNumber) ) != 0){
            one ^= nums[idx]; //part of the one club
        } else {
            zero ^= nums[idx]; // part of the zero club
        }
    }

    //now we have to iterate through all the numbers
    for(int number = 1; number <= length; number += 1){
        if((number & (1 << bitNumber)) != 0){
            one ^= number; //part of the one club
        } else {
            zero ^= number; //part of the zero club
        }
    }

    int cnt = 0;
    for(auto element: nums)
        if(element == zero) cnt += 1;

    if(cnt == 2) return {zero, one};
    else return {one, zero};
}


// optimal: Maths (linear equations)
//TC: O(N)
//SC: O(1)
vector<int> optimalMissingRepeatingMaths(vector<int> &nums){
    long long n = nums.size();

    //xminy = S - SN (sum of natural numbers) (x <- repeating and y -< missing)
    //x2miny2 = S2 - S2N 

    long long SN = ((n) * (n + 1)) / 2;
    long long S2N = ((n) * (n + 1) *(2*n + 1)) / 6;

    //we need to find the sum of given numbers
    long long S = 0, S2 = 0;

    for(auto element: nums){
        S += (long long)(element);
        S2 += ((long long)element * (long long)element);
    }

    long long xminy = S - SN;
    long long x2miny2 = S2 - S2N;

    long long xplusy = x2miny2 / xminy;

    long long x = (xminy + xplusy) / 2;
    long long y = xplusy - x;

    return {(int)x, (int)y};
}

//we can solve the problem using hashmap or even hash array
//Time complexity: O(N)
//Space complexity: O(N)
vector<int> betterMissingRepeating(vector<int> &nums){
    unordered_map<int,int> freqMap; //in order to store the frequency of commonly occuring elements

    int missing = -1;
    int repeating = -1;
    int maxValue = nums.size();

    //O(Nlog(N))
    for(auto element: nums){
        freqMap[element] += 1;
    }

    for(int number = 1; number <= maxValue; number += 1){
        if(freqMap.find(number) != freqMap.end()){
            if(freqMap[number] == 2) repeating = number;
        } else {
            missing = number;
        }

        if(repeating != -1 and missing != -1) break;
    }

    return {repeating, missing};
}

//brute approach: double iteration approach O(N2)
vector<int> bruteMissingRepeating(vector<int> &nums){
    int missing = -1;
    int repeating = -1;

    int maxValue = nums.size();

    for(int number = 1; number <= maxValue; number += 1){
        int cnt = 0;
        for(auto element: nums){
            if(element == number) cnt += 1;
        }

        //we have to find the repeating 
        if(cnt == 2) repeating = number;
        if(cnt == 0) missing = number;

        if(repeating != -1 and missing != -1) break;
    }

    return {repeating, missing};
}

int main(){
    int length;
    cin >> length;

    vector<int> nums(length);

    //in order to input the vector elements
    for(auto &element: nums) cin >> element;
    
    // vector<int> ans = bruteMissingRepeating(nums);
    // vector<int> ans = betterMissingRepeating(nums);
    vector<int> ans = optimalMissingRepeatingXor(nums);


    for(int idx = 0; idx < ans.size(); idx += 1){
        cout << ans[idx] << ' ';
    }
}