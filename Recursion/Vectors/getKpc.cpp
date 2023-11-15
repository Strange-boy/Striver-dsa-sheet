#include <bits/stdc++.h>
using namespace std;

//declare a string array globally 
string code[] = {".;", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tu", "vwx", "yz"};

//Logic: store the code globally and add those values by iterating in each recursive call
vector<string> getKPC(string str){
    //base case
    if(str.size() == 0){
        vector<string> base;
        base.push_back("");
        return base;
    }

    char ch = str[0]; //number that we need (5)
    string ros = str.substr(1); //remaining sub string (78)

    vector<string> remResult = getKPC(ros);
    vector<string> currResult;

    int idx = ch - '0';
    string codeForChar = code[idx];

    for(auto charCode: codeForChar){
        //after taking each character , we have to add the character to beginning
        for(auto value: remResult){
            currResult.push_back(charCode + value);
        }
    }

    return currResult;
}

int main(){
    string str;
    cin >> str;

    vector<string> result = getKPC(str);

    //we need to print all the results
    for(auto str: result){
        cout << str << '\n';
    }
}