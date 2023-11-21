#include <bits/stdc++.h>
using namespace std;

//Logic: form the correct substring (left part + right part)
//Time complexity: O(n!)

void printPermutation(string ques, string asf){
    //low level thinking
    if(ques.size() == 0){
        cout << asf << '\n';
        return;
    }


    //high order thinking
    for(int idx = 0; idx < ques.size(); idx += 1){
        char ch = ques[idx];
        string leftPart = ques.substr(0, idx);
        string rightPart = ques.substr(idx + 1);

        string roq = leftPart + rightPart;
        printPermutation(roq, asf + ch);
    }
}

int main(){
    string ques;
    cin >> ques;

    //in order to print all possible permutations
    printPermutation(ques, "");
}