#include<bits/stdc++.h>
using namespace std;

// Longest Subarray with sum K :
// Given an array containing positive and negative integers, find the length of the longest subarray whose sum equals K.

// TC - O(2N)
// SC - O(1)

int longestSubarrayWithSumK(vector<int> &a, long long k) {
    int left = 0;
    int right = 0;
    long long sum = 0;
    int maxLen = 0;
    int n = a.size();
    while(right < n){
        while(left <= right && sum > k){
            sum -= a[left];
            left++;
        }
        if(sum == k){
            maxLen = max(maxLen, right - left + 1);
        }
        right++;
        if(right < n){
            sum += a[right];
        }
    }
    return maxLen;
}


