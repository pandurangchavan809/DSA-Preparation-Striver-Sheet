#include<bits/stdc++.h>
using namespace std;

// Max Consecutive Ones III :
// Given a binary array nums and an integer k, return the maximum number of consecutive 1's in the array if you can flip at most k 0's.

class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int l=0, r=0, zeros=0, maxlen=0;
        int len;
        while(r<nums.size()){
            if(nums[r]==0)zeros++;
            if(zeros > k){
                if(nums[l]==0) zeros--;
                l++;
            }
            if(zeros <= k) len=r-l+1, maxlen=max(maxlen, len);
            r++;
        }
        return maxlen;
    }
};

// time complexity = ~O(2N) == O(N)
// space complexity = O(1)