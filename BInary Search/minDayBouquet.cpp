#include <bits/stdc++.h>
using namespace std;

//predicate function to check if it is possible to form the bouquets
bool possibleToFormBouquet(vector<int> &bloomDay, int day, int bouquets, int adjFlower){
    int cntFlowers = 0;
    int bouquetsFormed = 0;

    for(auto bDay: bloomDay){
        if(bDay <= day){
            cntFlowers += 1;
        } else {
            bouquetsFormed += (cntFlowers / adjFlower);
            cntFlowers = 0;
        }
    }

    if(cntFlowers > 0){
        bouquetsFormed += (cntFlowers / adjFlower);
        cntFlowers = 0;
    }

    if(bouquetsFormed >= bouquets) return true;
    else return false;
}

//Crux: iterate through the range of blooming,check if it is possible
//Time complexity: O(log(MaxDay - minDay) * totalFlower)
int findMinDays(vector<int> &bloomDay, int bouquets, int adjFlower){

    //first we would handle the edge case => results in runtime error
    long long value = bouquets * 1LL * adjFlower * 1LL;
    if(bloomDay.size() < value) return -1;

    //min and max blooming days
    int firstBloom = 1e9;
    int lastBloom = -1;

    for(auto bDay: bloomDay){
        firstBloom = min(bDay, firstBloom);
        lastBloom = max(bDay, lastBloom);
    }

    int low = firstBloom;
    int high = lastBloom;

    int minDays = -1;

    while(low <= high){
        int mid = (low + high) / 2;

        if(possibleToFormBouquet(bloomDay, mid, bouquets, adjFlower)){
            minDays = mid;
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }

    return minDays;
}



//Crux: iterate through the min and max day of blooming,check if it is possible
//Time complexity: O((MaxDay - minDay) * totalFlower)
int bruteFindMinDays(vector<int> &bloomDay, int bouquets, int adjFlower){

    //here the blooming lies between the min day and max day
    int firstBloom = 1e9;
    int lastBloom = -1;

    //in order to find the first blooming day and last blooming day
    for(int value: bloomDay){
        lastBloom = max(value, lastBloom);
        firstBloom = min(value, firstBloom);
    }

    for(int day = firstBloom; day <= lastBloom; day += 1){
        if(possibleToFormBouquet(bloomDay, day, bouquets, adjFlower)){
            return day;
        }
    }

    //if not possible to form the required bouquets
    return -1;
}

int main(){
    int totalFlowers, bouquets, adjFlower;
    cin >> totalFlowers >> bouquets >> adjFlower;

    vector<int> bloomDay(totalFlowers);

    for(auto &value: bloomDay) cin >> value;

    // int minDays = bruteFindMinDays(bloomDay, bouquets, adjFlower);
    int minDays = findMinDays(bloomDay, bouquets, adjFlower);

    cout << minDays << '\n';
}