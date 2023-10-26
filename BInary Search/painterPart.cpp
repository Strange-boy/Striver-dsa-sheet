#include <bits/stdc++.h>
using namespace std;

//predicate function to count the number of painters
int countPainters(vector<int> boardLength, int maxTime){
    int cntPainter = 1;
    int currLength = 0;

    for(int length: boardLength){
        if(currLength + length > maxTime){
            cntPainter += 1;
            currLength = length;
        } else {
            currLength += length;
        }
    }

    return cntPainter;
}

// Optimal: binary search through range[max(length), sum(length)], find time
// Time complexity: O(log(sum - max + 1)) * O(Boards)
int minTimeTaken(vector<int> &boardLength, int painters){
    //painter == boards
    int low = *max_element(boardLength.begin(), boardLength.end());
    //single painter to paint the entire board
    int high = accumulate(boardLength.begin(), boardLength.end(), 0);

    while(low <= high){
        int time = (low + high) / 2;

        int cntPainter = countPainters(boardLength, time);
        if(cntPainter > painters){
            low = time + 1;
        } else {
            high = time - 1;
        }
    }

    return low;
}

// Brute: find range[max(length), sum(length)], find time
// Time complexity: O(sum - max + 1) * O(Boards)
int bruteMinTimeTaken(vector<int> &boardLength, int painters){
    //painter == boards
    int minPossibleTime = *max_element(boardLength.begin(), boardLength.end());
    //single painter to paint the entire board
    int maxPossibleTime = accumulate(boardLength.begin(), boardLength.end(), 0);

    //iterate through the answer to find the minimal time to finish the job
    for(int time = minPossibleTime; time <= maxPossibleTime; time += 1){
        int painterReq = countPainters(boardLength, time);
        if(painterReq == painters) return time;
    }

    //sake of completion
    return -1;
}

int main(){
    int boards, painters;
    cin >> boards >> painters;

    vector<int> boardLength(boards);

    //input the length
    for(auto &length: boardLength) cin >> length;

    // int minTime = bruteMinTimeTaken(boardLength, painters);
    int minTime = minTimeTaken(boardLength, painters);

    cout << minTime << '\n';
}