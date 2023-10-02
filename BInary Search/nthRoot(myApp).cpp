#include <bits/stdc++.h>
using namespace std;
#define int long long int

bool possibleNthRoot(int nRoot, int number, int num){
    int currNum = 1;

    for(int root = 1; root <= nRoot; root += 1){
        currNum *= num;
    }

    if(currNum <= number) return true;
    else return false;
}

//Optimal: binary search on answer(search space -> number)
//Time complexity: O(nthRoot * log(number)) + O(nthRoot)
int findNthRoot(int nRoot, int number){
    int low = 1;
    int high = number;
    int rootValue = -1;

    while(low <= high){
        int mid = (low + high) / 2;
        if(possibleNthRoot(nRoot, number, mid)){
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    
    int currValue = 1;

    //finally we have to check whether the given value gives the answer
    for(int root = 1; root <= nRoot; root += 1){
        currValue *= high;
    }

    if(currValue == number) rootValue = high;

    return rootValue;
}

//Brute: linear search and find the nth root
//Time complexity:O(number * nthRoot)
int bruteFindNthRoot(int nRoot, int number){
    int rootValue = -1;

    for(int num = 1; num <= number; num += 1){
        int currNum = 1;

        for(int root = 1; root <= nRoot; root += 1){
            currNum *= num;
        }

        if(currNum == number){
            rootValue = num;
            break;
        } 
    }

    return rootValue;
}

int32_t main(){
    int nRoot, number;
    cin >> nRoot >> number;

    // int rootValue = bruteFindNthRoot(nRoot, number);
    int rootValue = findNthRoot(nRoot, number);
    cout << rootValue << '\n';
}