#include <bits/stdc++.h>
using namespace std;

//here we would use a two pointer approach to solve the problem
//Time complexity: o(N)
//Space complexity: O(1)
int traffic(vector<int> &vehicle,int  bitsFlipped){
    int right = 0;
    //in order to find the maximum traffic
    int maxTraffic = 0;

    int totalVehicles = vehicle.size();
    int currBits = 0;

    for(int left = 0; left < vehicle.size(); left += 1){
        while(right < totalVehicles and currBits <= bitsFlipped){
            if(vehicle[right] == 0){
                currBits += 1;

                if(currBits > bitsFlipped){
                    currBits -= 1;
                    break;
                }
            }

            right += 1;
        }

        maxTraffic = max(maxTraffic, right - left);

        if(vehicle[left] == 0) currBits -= 1;
    }

    return maxTraffic;
}

int main(){
    int totalVehicles , bitsFlipped;
    cin >> totalVehicles >> bitsFlipped;

    vector<int> vehicle(totalVehicles);
    
    //in order to denote the vehicle at a point
    for(auto &present: vehicle){
        cin >> present;
    }

    int maxTraffic = traffic(vehicle, bitsFlipped);

    cout << maxTraffic;
}