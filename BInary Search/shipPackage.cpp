#include <bits/stdc++.h>
using namespace std;

//this is the predicate function 
bool withinDaysLimit(vector<int> weights, int cap, int daysLimit){
    int load = 0;
    int daysTaken = 1;

    for(int idx = 0; idx < weights.size(); idx += 1){
        if(load + weights[idx] > cap){
            daysTaken += 1;
            load = weights[idx];
        } else {
            load += weights[idx];
        }
    }

    if(daysTaken <= daysLimit) return true;
    else return false;
}


//Logic: iterate through (bs)[minCap, sumCap] and find day
//Time complexity: O(log(max Weight - sum weight + 1) * total Weight)
//Space complexity: O(1)
int shipWitinDays(vector<int> weights, int daysLimit){
    int minCap = -1;
    int maxCap = 0;

    for(auto currWeight: weights) minCap = max(minCap, currWeight);

    //maxCap = sum of weights
    for(auto currWeight: weights) maxCap += currWeight;

    int low = minCap;
    int high = maxCap;
    int leastCap = -1;

    while(low <= high){
        int mid = (low + high) / 2;

        if(withinDaysLimit(weights, mid, daysLimit)){
            high = mid - 1;
            leastCap = mid;
        } else {
            low = mid + 1;
        }
    }

    return leastCap;
}

// Logic: iterate through [minCap, sumCap] and find day
// Time complexity: O((max Weight - sum weight + 1) * total Weight)
// Space complexity: O(1)
int bruteFindLeastCap(vector<int> &weights, int daysLimit){

    int minCap = -1;
    int maxCap = 0;

    //we need to find the minimum capacity
    for(auto currWeight: weights) minCap = max(minCap, currWeight);
    for(auto currWeight: weights) maxCap += currWeight;

    //iterate [minCap] -> [sumCap]
    for(int cap = minCap; cap <= maxCap; cap += 1){
        if(withinDaysLimit(weights, cap, daysLimit)){
            return cap;
        }
    }

    return -1;
}

int main(){
    int totalWeights, daysLimit;
    cin >> totalWeights >> daysLimit;

    vector<int> weights(totalWeights);

    //inorder to enter all the available weights
    for(auto &value: weights) cin >> value;

    // int leastCap = bruteFindLeastCap(weights, daysLimit);
    int leastCap = shipWitinDays(weights, daysLimit);

    cout << leastCap << '\n';
}