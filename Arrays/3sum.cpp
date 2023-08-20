#include <bits/stdc++.h>
using namespace std;

//in order to find all the triplets in an optimal manner
vector<vector<int>> optimalTriplet(vector<int> &nums){
    //in order to find the answers to the optimal triplets

    //here we are going to use a optimal two pointer approach to solve the problem
    sort(nums.begin(), nums.end());
    int length = nums.size();
    //we need an answer array to store the answer
    vector<vector<int>> ans;

    for(int first = 0; first < nums.size(); first += 1){
        if(first > 0 && nums[first] == nums[first - 1]) continue;

        int second = first + 1;
        int third = length - 1;

        while(second < third){
            int sum = nums[first] + nums[second] + nums[third];

            if(sum > 0){
                third -= 1;
            } else if(sum < 0){
                second += 1;
            } else {
                vector<int> temp = {nums[first], nums[second], nums[third]};
                ans.push_back(temp);

                second += 1;
                third -= 1;

                //we have to check the values of second and third
                while(second < third and nums[second] == nums[second - 1]) second += 1;
                while(second < third and nums[third] == nums[third + 1]) third -= 1;
            }
        }
    }

    return ans;
}

//in order to find all the possible triplets for the answer
vector<vector<int>> triplet(vector<int> &nums){
    //we need a set in order to store the answer
    set<vector<int>> unique;

    for(int first = 0; first < nums.size(); first += 1){
        set<int> hashset;
        for(int second = first + 1; second < nums.size(); second += 1){
            int third = -(nums[first] + nums[second]);

            if(hashset.find(third) != hashset.end()){
                vector<int> temp = {nums[first], nums[second], third};
                sort(temp.begin(), temp.end());
                unique.insert(temp);
            }
            //we have to add the element once computation is done
            hashset.insert(nums[second]);
        }
    }

    //finally we have to assign the answer array with all the elements
    vector<vector<int>> ans(unique.begin(), unique.end());
    return ans;

    //TC: O(N^2 * (NlogM))
    //SC: O(N)
}

//TC : O(n^3 + O(n * log(no of sets)))
//SC: O(2 * (no. of triplets))
vector<vector<int>> threeSum(vector<int> &nums){
    set<vector<int>> unique; //in order to store the unique answers

    //just iterate through all the elements of the array until the sum is zero
    for(int first = 0; first < nums.size(); first += 1){
        for(int second = first + 1; second < nums.size(); second += 1){
            for(int third = second + 1; third < nums.size(); third += 1){
                vector<int> temp;
                if(nums[first] + nums[second] + nums[third] == 0){
                    vector<int> temp = {nums[first], nums[second], nums[third]};
                    sort(temp.begin(), temp.end());
                    unique.insert(temp); //in order to avoid the duplicate sets
                }
            }
        }
    }

    //in order to store the final answer
    vector<vector<int>> ans(unique.begin(),unique.end()); 

    return ans;
}

int main(){
    int length;
    cin >> length;

    vector<int> nums(length);

    //in order to input the elements
    for(auto &element: nums){
        cin >> element;
    }

    // vector<vector<int>> ans = threeSum(nums);
    // vector<vector<int>> ans = triplet(nums);
    vector<vector<int>> ans = optimalTriplet(nums);

    //in order to print the final answer
    for(int row = 0; row < ans.size(); row += 1){
        for(int col = 0; col < ans[row].size(); col += 1){
            cout << ans[row][col] << ' ';
        }
        cout << endl;
    }
}