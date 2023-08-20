#include <bits/stdc++.h>
using namespace std;

//optimal approach to solve the problem
vector<int> twoPointer(vector<int> numsOne, vector<int> numsTwo){
    int one = 0;
    int two = 0;

    //in order to find the union of both the arrays
    vector<int> unionAns;
    int element = -1;

    while(one < numsOne.size() && two < numsTwo.size()){
        if(unionAns.size() > 0)
            element = unionAns.back();

        if(numsOne[one] <= numsTwo[two]){
            if(unionAns.size() == 0 || element != numsOne[one]) unionAns.push_back(numsOne[one]);
            one += 1;
        } else {
            if(unionAns.size() == 0 || element != numsTwo[two]) unionAns.push_back(numsTwo[two]);
            two += 1;
        }
    }

    for(int idx = one; idx < numsOne.size(); idx += 1){
        int element = unionAns.back();
        if(element != numsOne[idx])
            unionAns.push_back(numsOne[idx]);
    }

    //in order to add the elements to the second array
    for(int idx = two; idx < numsTwo.size(); idx += 1){
        // cout << "second array: " << numsTwo[idx];
        int element = unionAns.back();
        if(element != numsTwo[idx])
            unionAns.push_back(numsTwo[idx]);
    }

    return unionAns;
}

//in order to find the union of the elements
//O(Nlog(N)) TC //O(N) where N = n1 + n2
vector<int> bruteSortedArray(vector<int> &numsOne, vector<int> &numsTwo){
    set<int> ans;
    vector<int> finalAnswer;
    //we have to add the elements from the first array
    for(auto value: numsOne){
        ans.insert(value);
    }

    //we have to add the elements from the second array
    for(auto value: numsTwo){
        ans.insert(value);
    }

    for(auto element: ans){
        finalAnswer.push_back(element);
    }

    return finalAnswer;
}

int main(){
    int alen, blen;
    cin >> alen >> blen;

    vector<int> numsOne(alen);
    vector<int> numsTwo(blen);
    
    //in order to answer the array from the first array
    for(auto &value: numsOne){
        cin >> value;
    }

    //in order to answer the array from the second array
    for(auto &value: numsTwo){
        cin >> value;
    }

    vector<int> ans = twoPointer(numsOne, numsTwo);

    for(auto value: ans){
        cout << value << ' ';
    }
}