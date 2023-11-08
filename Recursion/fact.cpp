#include <bits/stdc++.h>
using namespace std;

//in order to find the factorial of a number
int findFactorial(int number){
    //base case
    if(number == 1) return 1;

    //high level thinking portion
    int nm1Fact = findFactorial(number - 1);
    int ans = number * nm1Fact;
    return ans;
}

int main(){
    int number;
    cin >> number;

    cout << findFactorial(number);
}