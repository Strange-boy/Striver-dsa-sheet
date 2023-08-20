#include <bits/stdc++.h>
using namespace std;
#define int long long int

void generateRow(int row){
    int ans = 1;

    //time complexity : O(row)
    for(int idx = 0; idx < row; idx += 1){
        if(idx == 0 or idx == row - 1){
            cout << 1 << ' ';
        } else {
            ans = ans * (row - idx);
            ans = ans / (idx);

            cout << ans << ' ';
        }
    }
}

//we have to input the row number
int32_t main(){
    int row;
    cin >> row;

    generateRow(row);
}