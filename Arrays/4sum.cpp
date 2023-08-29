#include <bits/stdc++.h>
using namespace std;

//striver's optimal solution to solve the problem

//optimal: double iteration + two pointer + ignoring all duplicates
//time complexity: O(N^3)
//space complexity: O(number of quads)
vector<vector<int>> fourSum(vector<int> &nums, int target){
    vector<vector<int>> quads;

    //first we need to sort the array
    sort(nums.begin(), nums.end());

    for(int first = 0; first < nums.size(); first += 1){
        //in order to remove the duplicates
        if(first > 0 and nums[first] == nums[first - 1]) continue;
        for(int second = first + 1; second < nums.size(); second += 1){
            if(second != first + 1 and nums[second] == nums[second - 1]) continue;

            //now we would use the two pointer approach to solve the problem
            int third = second + 1;
            int fourth = nums.size() - 1;

            while(third < fourth){
                long long sum = nums[first];
                sum = sum + nums[second];
                sum = sum + nums[third];
                sum = sum + nums[fourth];

                if(sum == target){
                    vector<int> temp = {nums[first], nums[second], nums[third], nums[fourth]};
                    quads.push_back(temp);

                    third += 1;
                    fourth -= 1;

                    while(third < fourth and nums[third] == nums[third - 1]) third += 1;
                    while(third < fourth and nums[fourth] == nums[fourth + 1]) fourth -= 1;
                } else if(sum < target){
                    third += 1;
                } else {
                    //sum > target
                    fourth -= 1;
                }
            }
        }
    }

    return quads;
}

//take care of the typecasting
//Optimal: using double iterations and two pointer
vector<vector<int>> optimal4sum(vector<int> &nums, int target){

    //at first we need to sort the array
    sort(nums.begin(), nums.end());
    int length = nums.size();

    set<vector<int>> unique;

    for(int first = 0; first < nums.size(); first += 1){
        for(int second = first + 1; second < nums.size(); second += 1){
            int third = second + 1;
            int fourth = length - 1;

            while(third < fourth){
                long long int result = nums[first] + nums[second];
                result = result + nums[third];
                result = result + nums[fourth];

                if(result == target){
                    vector<int> temp = {nums[first], nums[second], nums[third], nums[fourth]};
                    sort(temp.begin(), temp.end());
                    unique.insert(temp);
                    
                    //here we increase both
                    third += 1;
                    fourth -= 1;
                } else if(result > target){
                    fourth -= 1;
                } else {
                    third += 1;
                }
            }
        }
    }

    vector<vector<int>> answer(unique.begin(), unique.end());
    return answer;
}

//better: Here , we would use a hashset to store the answer and use three iterations
vector<vector<int>> better4sum(vector<int> &nums, int target){
    set<vector<int>> unique;

    for(int first = 0; first < nums.size(); first += 1){
        for(int second = first + 1; second < nums.size(); second += 1){
            //in order to store the answer in the hashset
            set<long long> hashSet;
            for(int third = second + 1; third < nums.size(); third += 1){
                long long sum = nums[first] + nums[second];
                sum += nums[third];

                long long fourth = target - (sum);

                if(hashSet.find(fourth) != hashSet.end()){
                    vector<int> temp = {nums[first], nums[second], nums[third], (int)(fourth)};
                    sort(temp.begin(), temp.end());
                    unique.insert(temp);
                }

                //at the end we have to add the element in to the hash set
                hashSet.insert(nums[third]);
            }
        }
    }

    vector<vector<int>> uniqueQuads(unique.begin(), unique.end());
    return uniqueQuads;
}

//Brute: in order to store the unique answers using four iterations
 //Time complexity: O(n^4)
vector<vector<int>> brute4sum(vector<int> &nums, int target){

    //in order to store the unique answers using four iterations
    set<vector<int>> unique;

    for(int first = 0; first < nums.size(); first += 1){
        for(int second = first + 1; second < nums.size(); second += 1){
            for(int third = second + 1; third < nums.size(); third += 1){
                for(int fourth = third + 1; fourth < nums.size(); fourth += 1){
                    // long long int result =  nums[first] + nums[second] + nums[third] + nums[fourth];

                    if((nums[first] + nums[second] + nums[third] + nums[fourth]) == target){
                        vector<int> temp = {nums[first], nums[second], nums[third], nums[fourth]};
                        sort(temp.begin(), temp.end());

                        unique.insert(temp);
                    }

                }
            }
        }
    }

    //we have to finally store the answer in a 2d vector
    vector<vector<int>> answer(unique.begin(), unique.end());
    return answer;
}

int main(){
    int size, target;
    cin >> size >> target;

    vector<int> nums(size);

    //in order to enter the elements
    for(auto &element: nums) cin >> element;

    // vector<vector<int>> ans = brute4sum(nums, target);
    // vector<vector<int>> ans = optimal4sum(nums, target);
    vector<vector<int>> ans = fourSum(nums, target);



    //in order to finally print the resulting answer
    for(int row = 0; row < ans.size(); row += 1){
        for(int col = 0; col < ans[row].size(); col += 1){
            cout << ans[row][col] << ' ';
        }
        cout << '\n';
    }
}