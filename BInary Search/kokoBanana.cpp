#include <bits/stdc++.h>
using namespace std;

//logic to find whether the current speed is feasible 
bool possibleSpeed(int currSpeed, vector<int> &banana, int guard){
    int timeTaken = 0;

    for(int pile = 0; pile < banana.size(); pile += 1){
        timeTaken += (banana[pile] + currSpeed - 1) / currSpeed;
    }

    if(timeTaken <= guard) return true;
    else return false;
}


//Optimal: Binary search on maxSpeed
//Time complexity: O(log(maxSpeed) * piles)
int minEatingSpeed(vector<int> &banana, int guard){
    int maxSpeed = -1;

    //first we need to find the max speed
    for(auto value: banana) maxSpeed = max(maxSpeed, value);

    int low = 1;
    int high = maxSpeed;

    while(low <= high){
        int mid = (low + high) / 2;

        if(possibleSpeed(mid, banana, guard)){
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }

    //we need to return the min speed
    return low;
}

//Brute: linear search for answer (1 -> maxBanana's in piles) 
//Time complexity: O(maxSpeed * piles)
int bruteMinEatingSpeed(vector<int> &banana,int guard){
    int maxSpeed = -1;

    //first we need to find the max speed
    for(auto value: banana) maxSpeed = max(maxSpeed, value);

    //now we need to iterate between the min speed and max speed to find the answer
    for(int currSpeed = 1; currSpeed <= maxSpeed; currSpeed += 1){
        if(possibleSpeed(currSpeed, banana, guard)) return currSpeed;
    }

    return -1;
}

int main(){
    int piles, guard;
    cin >> piles >> guard;

    vector<int> banana(piles);

    //enter the number of banana's in piles
    for(auto &value: banana) cin >> value;

    // int eatingSpeed = bruteMinEatingSpeed(banana, guard);
    int eatingSpeed = minEatingSpeed(banana, guard);

    cout << eatingSpeed << '\n';
}