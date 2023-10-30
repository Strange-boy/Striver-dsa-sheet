#include <bits/stdc++.h>
using namespace std;

int countGasStations(vector<int> &gasStations, long double dist){
    int cntStations = 0;

    for(int idx = 0; idx < gasStation.size() - 1; idx += 1){
        long double diff = gasStation[idx + 1] - gasStation[idx]
        int stnBetween = diff / dist;
        if(diff == stnBetween * dist) stnBetween -= 1;

        cntStations += stnBetween;
    }

    return cntStations;
}

//Better: always try to find largest section(using bs-1e-6) with range [0, maxDiff]
//Time complexity: O(Nlog(N) + kLog(N))
double long minimiseMaxDistance(vector<int> &gasStations, int stations){
    int points = gasStations.size();

    long double low = 0;
    long double high = 0;

    for(int secIdx = 0; secIdx < points - 1; secIdx += 1){
        high = max(high, (long double)gasStations[secIdx + 1] - gasStations[secIdx]);
    }

    long double diff = 1e-6;
    while(high - low > diff){
        long double mid = (low + high) / 2.0;

        int cntStations = countGasStations(gasStations, mid);
        if(cntStations > stations){
            low = mid;
        } else {
            high = mid;
        }
    }

    return high;
}


//Better: always try to find largest section(using priority queue) and place station between it
//Time complexity: O(Nlog(N) + kLog(N))
//Space complexity: O(N - 1)
double long betterMinimiseMaxDistance(vector<int> &gasStations, int stations){
    int points = gasStations.size();
    vector<int> hasPlaced(points - 1, 0);

    priority_queue<pair<long double, int>> maxSection;
    
    for(int secIdx = 0; secIdx < points - 1; secIdx += 1){
        long double diff = gasStations[secIdx + 1] - gasStations[secIdx];
        maxSection.push({diff, secIdx});
    }

    //we have to place the extra stations
    for(int currStation = 1; currStation <= stations; currStation += 1){
        auto section = maxSection.top();
        maxSection.pop();

        int maxInd = section.second;
        hasPlaced[maxInd] += 1;

        long double initialDiff = gasStations[maxInd + 1] - gasStations[maxInd];
        long double currDiff = initialDiff / (long double)(hasPlaced[maxInd] + 1);

        //push the result into the priority queue
        maxSection.push({currDiff, maxInd});
    }

    long double dist = maxSection.top().first;
    return dist;
}

//Brute: always try to find largest section and place station between it
//Time complexity: O(N^2)
double long bruteMinimiseMaxDistance(vector<int> gasStations, int stations){
    int points = gasStations.size();
    vector<int> hasPlaced(points - 1, 0); //stations placed between coordinates

    for(int currStation = 1; currStation <= stations; currStation += 1){
        int maxInd = -1;
        long double maxSection = -1;

        for(int idx = 0; idx < points - 1; idx += 1){
            long double diff = gasStations[idx + 1] - gasStations[idx];
            long double sectionLen = diff / (long double)(hasPlaced[idx] + 1);

            if(maxSection < sectionLen){
                maxSection = sectionLen;
                maxInd = idx;
            }
        }

        //finally we have to increment the max sections
        hasPlaced[maxInd] += 1;
    }

    long double dist = 0;

    //now we have to find the max section length
    for(int idx = 0; idx < points - 1; idx += 1){
        long double diff = gasStations[idx + 1] - gasStations[idx];
        long double sectionLen = diff / (long double)(hasPlaced[idx] + 1);

        dist = max(dist, sectionLen);
    }

    return dist;
}

int main(){
    int points, stations;
    cin >> points >> stations;

    vector<int> gasStations(points);

    //enter the coordinates of the points
    for(auto &coordinates: gasStations) cin >> coordinates;

    long double minDist = minimiseMaxDistance(gasStations, stations);
    cout << minDist << '\n';
}