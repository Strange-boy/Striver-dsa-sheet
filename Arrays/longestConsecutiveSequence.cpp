#include <bits/stdc++.h>
using namespace std;


int optimalConsecutive(vector<int> &nums){
    //here we would use a set data structure to solve the problem
    unordered_set<int> st;
    int len = nums.size();

    if(len == 0) return 0;
    
    int longest = 1;

    //in order to insert the value in set
    for(auto value: nums){
        st.insert(value);
    }

    for(auto element: st){
        if(st.find(element - 1) == st.end()){
            int currCnt = 1;
            int currValue = element;

            while(st.find(currValue + 1) != st.end()){
                currCnt += 1;
                currValue += 1;
            }

            longest = max(longest, currCnt);
        }
    }

    return longest;
}

//using last smaller 
int striverConsecutive(vector<int> &nums){
    //first we need to sort the array
    sort(nums.begin(), nums.end());
    int len = nums.size();

    int lastSmaller = INT_MIN;
    int currCnt = 0;
    int longest = 1;
    

    if(len == 0) return 0;

    for(int idx = 0; idx < len; idx += 1){
        if(nums[idx] - 1 == lastSmaller){
            currCnt += 1;
            lastSmaller = nums[idx];
        } else if(lastSmaller != nums[idx]){
            currCnt = 1;
            lastSmaller = nums[idx];
        }

        longest = max(longest, currCnt);
    }

    return longest;
}

//in order to find the length of the longest sequence
//Time complexity: O(Nlog(N))
int longestConsecutive(vector<int> &nums){
    //first we have to sort the array
    sort(nums.begin(), nums.end());

    //then we have to iterate and find the max Length
    int maxLength = 1;
    int currLength = 1;

    //edge case 
    if(nums.size() == 0) return 0;

    for(int idx = 1; idx < nums.size(); idx += 1){
        if(nums[idx] - nums[idx - 1] == 1){
            currLength += 1;
        } else if(nums[idx] - nums[idx - 1] == 0){
            continue;
        } else {
            maxLength = max(maxLength, currLength);
            currLength = 1;
        }
    }

    if(currLength > 1) maxLength = max(maxLength, currLength);

    return maxLength;
}

int main(){
    int length;
    cin >> length;

    vector<int> nums(length);

    //in order to input the elements of the array
    for(auto &value: nums){
        cin >> value;
    }

    int maxLength = optimalConsecutive(nums);

    cout << maxLength << '\n';
}