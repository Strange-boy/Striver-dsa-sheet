#include <bits/stdc++.h>
using namespace std;

//in order to input the char codes
string code[] = {".;", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tu", "vwx", "yz"};

void printKPC(string str, string asf){
    //base case
    if(str.size() == 0){
        cout << asf << "\n";
        return;
    }

    //high level thinking
    char currCode = str[0];
    string roc = str.substr(1);

    int idx = currCode - '0';

    //require code for the number code
    string charInCode = code[idx];

    for(auto eachChar: charInCode){
        printKPC(roc, asf + eachChar);
    }
}

int main(){
    string str;
    cin >> str;

    printKPC(str, "");
}