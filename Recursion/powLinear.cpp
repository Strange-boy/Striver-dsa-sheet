#include <bits/stdc++.h>
using namespace std;

//Logic: recursion on way up + down
//Time complexity: O(N)
//Space complexity: O(N)
int power(int base, int pow){
    if(pow == 0) return 1;

    int pownm1 = power(base, pow - 1);
    int ans = base * pownm1;
    return ans;
}

int main(){
    int base, pow;
    cin >> base >> pow;

    int finalAns = power(base, pow);
    cout << finalAns << '\n';
}