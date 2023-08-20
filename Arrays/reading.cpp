#include <bits/stdc++.h>
using namespace std;

//using the two pointer approach to solve the problem
string read(vector<int> &book, int target){
    //(NlogN + n) approach to solve the problem

    //first we need to sort the array
    sort(book.begin(), book.end());

    //then we would use the two pointer approach to solve the problem
    int left = 0;
    int right = book.size() - 1;
    
    string ans = "NO";
    
    while(left < right){
        if(book[left] + book[right] == target){
            ans = "YES";
            break;
        } else if(book[left] + book[right] > target){
            right -= 1;
        } else {
            left += 1;
        }
    }

    return ans;
}

int main(){
    int length, target;
    cin >> length >> target;

    vector<int> book(length);

    //in order to enter the elements into the array
    for(auto &pages: book){
        cin >> pages;
    }

    string ans = read(book, target);

    cout << ans << '\n';
}