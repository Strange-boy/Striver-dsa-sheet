#include <bits/stdc++.h>
using namespace std;

//predicate function to check if we can place the cows
bool canWePlaceCows(vector<int> stalls, int cows, int minDist){
    int cntCows = 1;
    int lastCow = stalls[0];

    for(int idx = 2; idx < stalls.size(); idx += 1){
        if(stalls[idx] - lastCow >= minDist){
            cntCows += 1;
            lastCow = stalls[idx];
        }
    }

    if(cntCows >= cows) return true;
    else return false;
}

// Logic: binary search through [1, max-min] , find max dist away
// Time complexity:O(log(max - min) * (stalls))+ O(Nlog(N))
int aggresiveCows(vector<int> stalls, int cows){
    sort(stalls.begin(), stalls.end());

    int minDist = stalls[0];
    int maxDist = stalls[stalls.size() - 1];

    int low = 1;
    int high = maxDist - minDist;

    while(low <= high){
        int mid = (low + high) / 2;

        if(canWePlaceCows(stalls, cows, mid)){
            minDist = mid;
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }

    return minDist;
}


// Logic: iterate through [1, max-min] , find max dist away
// Time complexity:O(max - min) * O(stalls) + O(Nlog(N))
int bruteAggresiveCows(vector<int> stalls, int cows){
    //first we need to sort the array
    sort(stalls.begin(), stalls.end());

    //answer will lie in range [1,max - min]
    int maxDist = -1;
    int minDist = 1e9;

    for(int coordinates: stalls){
        maxDist = max(maxDist, coordinates);
        minDist = min(minDist, coordinates);
    }

    for(int dist = 1; dist <= maxDist - minDist; dist += 1){
        if(!canWePlaceCows(stalls, cows, dist)){
            return dist - 1;
        }
    }

    return maxDist - minDist;
}

int main(){
    int totalStalls, cows;
    cin >> totalStalls >> cows;

    //now we have to place the cows in the stall
    vector<int> stalls(totalStalls);

    //input
    for(auto &coordinates: stalls) cin >> coordinates;

    // int minDist = bruteAggresiveCows(stalls, cows);
    int minDist = aggresiveCows(stalls, cows);

    cout << minDist << '\n';
}