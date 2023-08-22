#include <bits/stdc++.h>
using namespace std;

//swap the greater element
void swapGreaterElement(vector<long long int> &first, vector<long long int> &second,int fIdx, int sIdx){
    if(first[fIdx] > second[sIdx]){
        swap(first[fIdx], second[sIdx]);
    }
}

//gap methodology approach to solve the problem
void optimalGapMergeTwoSortedArrays(vector<long long int> &first, vector<long long int> &second){
    int one = first.size();
    int two = second.size();
    int len = one + two;

    int gap = (len / 2) + (len % 2);

    while(gap > 0){
        int left = 0;
        int right = left + gap;

        while(right < len){
            // left -> first and right -> second
            if(left < one and right >= one){
                swapGreaterElement(first, second, left, right - one);
            } else if(left >= one){
            // left -> second and right -> second
                swapGreaterElement(second, second, left - one, right - one);
            } else {
            // left -> first and right -> first
                swapGreaterElement(first, first, left, right);
            }

            left += 1;
            right += 1;
        }

        if(gap == 1) {
            break;
        } else {
            gap = (gap / 2) + (gap % 2);
        }
    }
}

//awesome two pointer swapping approach 
//O(nlogn) TC
//O(1) space
void optimalXMergeTwoSortedArrays(vector<long long int> &first, vector<long long int> &second){
    //here we would use the simple idea of exchanging to solve the problem
    int left = first.size() - 1;
    int right = 0;

    int one = first.size();
    int two = second.size();

    while(left >= 0 and right < two){
        if(first[left] > second[right]){
            swap(first[left], second[right]);
            left -= 1;
            right += 1;
        } else {
            break;
        }
    }

    //now we need to sort both the vectors
    sort(first.begin(), first.end());
    sort(second.begin(), second.end());
}


void bruteMergeTwoSortedArrays(vector<long long int> &first, vector<long long int> &second){
    //Time complexity : O(one + two) + O(one + two)
    //Space complexity: O(one + two)
    int one = first.size();
    int two = second.size();

    long long int ans[one + two];

    int ansIdx = 0;
    int left = 0;
    int right = 0;

    while(left < one and right < two){
        if(first[left] <= second[right]){
            ans[ansIdx] = first[left];
            ansIdx += 1;
            left += 1;
        } else {
            ans[ansIdx] = second[right];
            ansIdx += 1;
            right += 1;
        }
    }

    //if the left array is remaining
    while(left < one){
        ans[ansIdx] = first[left];
        left += 1;
        ansIdx += 1;
    }

    //if the right array is one remaining
    while(right < two){
        ans[ansIdx] = second[right];
        ansIdx += 1;
        right += 1;
    }

    for(int idx = 0; idx < one + two; idx += 1){
        if(idx < one) first[idx] = ans[idx];
        else second[idx - one] = ans[idx];
    }
}

int main(){
    int n, m;
    cin >> n >> m;

    vector<long long int> first(n);

    for(auto &element: first){
        cin >> element;
    }

    vector<long long int> second(m);

    for(auto &element: second){
        cin >> element;
    }

    // bruteMergeTwoSortedArrays(first, second);
    // optimalXMergeTwoSortedArrays(first, second);
    optimalGapMergeTwoSortedArrays(first, second);

    //in order to print the first and the second array
    for(auto element: first) cout << element << ' ';
    for(auto element: second) cout << element << ' ';
}