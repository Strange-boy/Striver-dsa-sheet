#include <bits/stdc++.h>
using namespace std;

//Logic : we would use recursion on way up
void printSubs(string str, string ssf){
    //base case of the problem 
    if(str.size() == 0){
        cout << ssf << '\n';
        return;
    }

    //high level thinking
    char ch = str[0];
    string ros = str.substr(1);

    //there are two cases => add the char and not add the char
    printSubs(ros, ssf + ch);
    printSubs(ros, ssf + "");
}

int main(){
    string str;
    cin >> str;

    //in order to print the subsequence
    printSubs(str, "");
}