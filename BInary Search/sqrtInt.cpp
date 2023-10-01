#include <iostream>
using namespace std;

//Idea:Binary search on answer(number -> search space)
//Time complexity: O(log(N))
int findSqrt(int number){
    int low = 0;
    int high = number;

    while(low <= high){
        long long int mid = low + (high - low) / 2;
        long long int value = mid * mid;
        if(value <= number){
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }

    return high;
}

//Idea:linear search to find whether the number is sqrt of given number or not
//Time complexity: O(N)
int bruteFindSqrt(int number){
    int sqrtValue = 0;

    for(int num = 1;num <= number; num += 1){
        if(num * num <= number) sqrtValue = num;
        else break;
    }

    return sqrtValue;
}

int main(){
    int number;
    cin >> number;

    // int sqrtValue = bruteFindSqrt(number);
    int sqrtValue = findSqrt(number);

    cout << sqrtValue << '\n';
}