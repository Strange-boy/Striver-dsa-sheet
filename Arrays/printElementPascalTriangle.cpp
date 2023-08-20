#include <bits/stdc++.h>
using namespace std;
#define int long long int

//in order to print the element at the specific row and column
int nCr(int n, int r){
    int res = 1;

    for(int idx = 0; idx < r; idx += 1){
        res = res * (n - idx);
        res = res / (idx + 1);
    }

    return res;
}

int32_t main(){
    int row, col;
    cin >> row >> col;

    int ans = nCr(row - 1, col - 1);

    cout << ans << '\n';
}