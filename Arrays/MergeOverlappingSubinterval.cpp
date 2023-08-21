#include <bits/stdc++.h>
using namespace std;

//time complexity: O(Nlog(N)) + O(N) (Single pass solution)
//space complexity: O(N * 2)
vector<vector<int>> optimalMergeOverlappingIntervals(vector<vector<int>> &interval){
    int intervalSize = interval.size();

    //in order to store the final answer
    vector<vector<int>> mergedIntervals;

    //first we need to sort the vector
    sort(interval.begin(), interval.end());

    for(int idx = 0;idx < intervalSize; idx += 1){
        int currStart = interval[idx][0];
        int currEnd = interval[idx][1];
        int refEnd = 0;

        if(!mergedIntervals.empty()) refEnd = mergedIntervals.back()[1];

        //we have to check for two conditions
        if(mergedIntervals.empty() or refEnd < currStart){
            mergedIntervals.push_back({currStart, currEnd});
        } else {
            mergedIntervals.back()[1] = max(currEnd, refEnd);
        }
    }

    return mergedIntervals;
}


//time complexity: O(Nlog(N)) + O(2N)
//space complexity: O(N)
vector<vector<int>> bruteMergeOverlappingSubintervals(vector<vector<int>> &interval){
    int intervalSize = interval.size();

    vector<vector<int>> mergedIntervals;

    //first we have to sort the 2d vector
    sort(interval.begin(), interval.end());

    for(int first = 0; first < intervalSize; first += 1){
        int refStart = interval[first][0];
        int refEnd = interval[first][1];

        //if a particular interval is considered in merge interval then we have to skip the interval
        if(!mergedIntervals.empty() and refEnd <= mergedIntervals.back()[1]) {
            continue;
        }

        for(int second = first + 1; second < intervalSize; second += 1){
            int currStart = interval[second][0];
            int currEnd = interval[second][1];

            if(currStart <= refEnd){
                refEnd = max(refEnd, currEnd); 
            } else {
                break;
            }
        }

        mergedIntervals.push_back({refStart, refEnd});
    }


    return mergedIntervals;
}

int main(){
    int size;
    cin >> size;

    vector<vector<int>> intervals;

    for(int row = 1;row <= size; row += 1){
        vector<int> temp;
        for(int col = 0; col < 2; col += 1){
            int data;
            cin >> data;

            temp.push_back(data);
        }

        intervals.push_back(temp);
    }

    // vector<vector<int>> mergedIntervals = bruteMergeOverlappingSubintervals(intervals);
    vector<vector<int>> mergedIntervals = optimalMergeOverlappingIntervals(intervals);


    //in order to print the answer
    for(int row = 0; row < mergedIntervals.size(); row += 1){
        for(int col = 0; col < mergedIntervals[row].size(); col += 1){
            cout << mergedIntervals[row][col] << ' ';
        }
        cout << endl;
    }
}