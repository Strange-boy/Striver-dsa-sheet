#include <bits/stdc++.h>
using namespace std;

//Logic: by using the concept of odd - even 
//Time complexity: O(log(n))
//Space complexity: O(log(n))

int power(int x, int n){
    //base case of the problem
    if(n == 0) return 1;

    // low level + high level thinking
    int xnb2 = power(x , n / 2);
    int xn = power(x, n / 2);

    if(n % 2){
        xn = xn * x;
    }

    return x;
}

int main(){
    int x, n;
    cin >> x >> n;

    int xn = power(x, n);
    cout << xn << '\n';
}