#include <bits/stdc++.h>
using namespace std;

//Logic : we need to seperate the characters and print answer
//Time complexity: O(2^n)

void printEncoding(string str, string asf){
    //base case
    if(str.size() == 0){
        cout << asf << '\n';
        return;
    } else if(str.size() == 1){
        //here we need to consider the case when we get '0'
        if(str[0] == '0'){
            return;
        } else {
            int chValue = str[0] - '0';
            char code = (char)('a' + chValue - 1);

            asf = asf + code;
            cout << asf << '\n';
            return;
        }
    } else {
        //if the length of the string is greater than 2
        
        //sub problem => length 1 taken
        char ch = str[0];
        string roq = str.substr(1);

        if(ch == '0'){
            return;
        } else {
            int chValue = ch - '0';
            char code = (char)('a' + chValue - 1);

            printEncoding(roq, asf + code);
        }

        //sub problem => length 2 taken
        string ch12 = str.substr(0, 2);
        string roq12 = str.substr(2);

        int chValue12 = stoi(ch12);

        if(chValue12 <= 26){
            char code12 = (char)('a' + chValue12 - 1);
            printEncoding(roq12, asf + code12);
        }
    }
}

int main(){
    string str;
    cin >> str;

    printEncoding(str, "");
}