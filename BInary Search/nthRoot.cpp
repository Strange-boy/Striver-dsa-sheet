#include <bits/stdc++.h>
using namespace std;

//return 1 -> if answer found
//return 0 -> if answer is low
//return 2 -> value is greater
int possibleAnswer(int nthRoot,int number, int mid){
    long long ans = 1;
    for(int root = 1; root <= nthRoot; root += 1){
        ans = ans * mid;

        if(ans > number) return 2;
    }

    if(ans == number) return 1;
    return 0;
}


//optimal: binary search on answer and handle overflow
int findNthRoot(int nthRoot, int number){
    int low = 1;
    int high = number;

    while(low <= high){
        int mid = (low + high) / 2;
        int ansFound = possibleAnswer(nthRoot, number, mid);
        
        if(ansFound == 1){
            return mid;
        } else if(ansFound == 0){
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }

    return -1;
}

int main(){
    int nthRoot, number;
    cin >> nthRoot >> number;

    int rootValue = findNthRoot(nthRoot, number);
    cout << rootValue << '\n';
}