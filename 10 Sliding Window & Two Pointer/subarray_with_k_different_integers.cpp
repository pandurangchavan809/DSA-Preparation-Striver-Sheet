#include<bits/stdc++.h>
using namespace std;

// Subarray with k different integers  :

class Solution {
public:
    // Helper: count subarrays with at most K distinct elements
    int atMostK(vector<int>& nums, int K) {
        unordered_map<int, int> freq;
        int left = 0, count = 0, distinct = 0;

        for (int right = 0; right < nums.size(); right++) {
            // If new element, increase distinct count
            if (freq[nums[right]] == 0) distinct++;
            freq[nums[right]]++;

            // Shrink window if distinct elements exceed K
            while (distinct > K) {
                freq[nums[left]]--;
                if (freq[nums[left]] == 0) distinct--; // remove distinct
                left++;
            }

            // Count valid subarrays ending at right
            count += (right - left + 1);
        }
        return count;
    }

    int subarraysWithKDistinct(vector<int>& nums, int k) {
        // Exactly K = atMostK(k) - atMostK(k-1)
        return atMostK(nums, k) - atMostK(nums, k - 1);
    }
};

// O(N)   && O(K)