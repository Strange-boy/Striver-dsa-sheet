#include <bits/stdc++.h>
using namespace std;

//in order to merge two arrays
vector<int> mergeTwoArray(vector<int> &nums1, vector<int> &nums2){

    int first = 0;
    int second = 0;

    vector<int> ans;

    while(first < nums1.size() and second < nums2.size()){
        if(nums1[first] <= nums2[second]){
            ans.push_back(nums1[first]);
            first += 1;
        } else {
            ans.push_back(nums2[second]);
            second += 1;
        }
    }

    //if the first array is still remaining
    while(first < nums1.size()){
        ans.push_back(nums1[first]);
        first += 1;
    }

    //if the second array is still remaining
    while(second < nums2.size()){
        ans.push_back(nums2[second]);
        second += 1;
    }

    return ans;
}

// Better: instead of storing all elements , we only take the required ones
// Time complexity: O(m + n)
// Space complexity: O(1)
double betterFindMedian(vector<int> &nums1, vector<int> &nums2){
    int length = nums1.size() + nums2.size();
    //in order to mark the median index
    int firstIdx = length / 2;
    int secondIdx = (length / 2) - 1;

    int firstElmnt = -1;
    int secondElmnt = -1;

    //in order to track the first and second array
    int left = 0;
    int right = 0;

    int cntIdx = 0;

    while(left < nums1.size() and right < nums2.size()){
        if(nums1[left] <= nums2[right]){
            if(cntIdx == firstIdx) firstElmnt = nums1[left];
            if(cntIdx == secondIdx) secondElmnt = nums1[left];
            cntIdx += 1;
            left += 1;
        } else {
            if(cntIdx == firstIdx) firstElmnt = nums2[right];
            if(cntIdx == secondIdx) secondElmnt = nums2[right];
            cntIdx += 1;
            right += 1;
        }
    }

    //if the first array is still remaining
    while(left < nums1.size()){
        if(cntIdx == firstIdx) firstElmnt = nums1[left];
        if(cntIdx == secondIdx) secondElmnt = nums1[left];
        cntIdx += 1;
        left += 1;
    }


    //if the second array is still remaining
    while(right < nums2.size()){
        if(cntIdx == firstIdx) firstElmnt = nums2[right];
        if(cntIdx == secondIdx) secondElmnt = nums2[right];
        cntIdx += 1;
        right += 1;
    }   

    double ans = 0;

    if(length & 1){
        ans = (double)(firstElmnt);
    } else {
        ans = (double)((double)(firstElmnt + secondElmnt) / 2.0);
    }

    return ans;
}

// Brute: by using two pointer to solve the problem
// Time complexity: O(m + n)
// Space complexity: O(m + n)
double bruteFindMedian(vector<int> &nums1, vector<int> &nums2){
    //since the array is sorted we would use the two pointer approach to merge the array
    vector<int> mergedArray = mergeTwoArray(nums1, nums2);
    double ans;

    int length = mergedArray.size();
    if(length % 2 != 0){
        ans = (double) mergedArray[length / 2];
    } else {
        ans = (double)((mergedArray[length / 2] + mergedArray[(length / 2) - 1]) / 2.00);
    }

    return ans;
}

int main(){
    int n, m;
    cin >> n >> m;

    vector<int> nums1(n);
    vector<int> nums2(m);

    //enter the input 
    for(auto &value: nums1) cin >> value;
    for(auto &value: nums2) cin >> value;

    double median = betterFindMedian(nums1, nums2);
    cout << median << '\n';
}