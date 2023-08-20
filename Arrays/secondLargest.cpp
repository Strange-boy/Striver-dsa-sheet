#include <bits/stdc++.h>
using namespace std;

//optimal approach to solve the problem
vector<int> optimalSecondElement(vector<int> &a, int n){
    int maxElement = -1, minElement = INT_MAX;
    int secLargest = -1, secSmallest = INT_MAX;

    for(auto value: a){
        if(maxElement < value){
            secLargest = maxElement;
            maxElement = value;
        } else if(value < maxElement and value > secLargest){
            secLargest = value;
        }

        if(minElement > value){
            secSmallest = minElement;
            minElement = value;
        } else if(minElement < value and value < secSmallest){
            secSmallest = value;
        }
    }

    vector<int> ans;
    ans.push_back(secLargest);
    ans.push_back(secSmallest);

    return ans;
}

//second way to solve the problem
//O(N) approach
vector<int> betterSecondElement(vector<int> &a, int n){
    int maxElement = a[0];
    int minElement =  a[0];

    for(auto value: a){
        if(maxElement < value) maxElement = value;

        if(minElement > value) minElement = value;
    }

    int secMaxElement = -1;
    int secMinElement = INT_MAX;
    for(auto value: a){
        if(value != maxElement and secMaxElement < value) secMaxElement = value;
        if(value != minElement and secMinElement > value) secMinElement = value;
    }

    vector<int> ans;
    ans.push_back(secMaxElement);
    ans.push_back(secMinElement);

    return ans;
}

//in order to find the second largest and second smallest element
//O(Nlogn) approach
vector<int> bruteSecondElement(vector<int> &a, int n){
    //simply sort the array
    sort(a.begin(), a.end());
    int secondLargest = -1;

    for(int idx = n - 2; idx >= 0; idx += 1){
        if(a[idx] != a[n - 1]){
            secondLargest = a[idx];
            break;
        }
    }
    
    int secondSmallest = -1;

    //in order to find the second secondSmallest element
    for(int idx = 1; idx < n; idx += 1){
        if(a[idx] != a[0]){
            secondSmallest = a[idx];
            break;
        }
    }

    vector<int> ans;
    ans.push_back(secondLargest);
    ans.push_back(secondSmallest);

    return ans;
}

int main(){
    int length;
    cin >> length;

    vector<int> nums(length);

    for(auto &value: nums){
        cin >> value;
    }

    vector<int> ans = optimalSecondElement(nums, length);

    //in order to print the ans
    for(int value: ans){
        cout << value << ' ';
    }
}