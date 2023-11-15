#include <bits/stdc++.h>
using namespace std;


//Logic: subsequece found using adding empty char + first char (2 recursive calls)
vector<string> getSub(string str){
    //low level thinking
    if(str.size() == 0){
        vector<string> base;
        base.push_back("");
        return base;
    }

    //high level thinking
    char ch = str[0];
    string ros = str.substr(1);

    vector<string> currSequence = getSub(ros);
    vector<string> sequence;

    //first we need to join with ""
    for(auto res: currSequence){
        sequence.push_back("" + res);
    }

    //then we need to join with char
    for(auto res: currSequence){
        sequence.push_back(ch + res);
    }

    return sequence;
}

int main(){
    string str;
    cin >> str;

    //we need to find the resultant substring
    vector<string> resSubstr = getSub(str);
    
    for(auto res: resSubstr){
        cout << res << '\n';
    }

    // cout << resSubstr.size();
}