#include <bits/stdc++.h>
using namespace std;

// Minimum days to make M bouquets

// Problem Statement: You are given 'N’ roses and you are also given an array 'arr' where 'arr[i]' denotes that the 'ith' rose will bloom on the 'arr[i]th' day. You can only pick already bloomed roses that are adjacent to make a bouquet. You are also told that you require exactly 'k' adjacent bloomed roses to make a single bouquet. Find the minimum number of days required to make at least ‘m' bouquets each containing 'k' roses. Return -1 if it is not possible.

// Examples
// Example 1:
// Input Format: N = 8, arr[] = {7, 7, 7, 7, 13, 11, 12, 7}, m = 2, k = 3
// Result: 12
// Explanation: On the 12th the first 4 flowers and the last 3 flowers would have already bloomed. So, we can easily make 2 bouquets, one with the first 3 and another with the last 3 flowers.

// Example 2:
// Input Format: N = 5, arr[] = {1, 10, 3, 10, 2}, m = 3, k = 2
// Result: -1
// Explanation: If we want to make 3 bouquets of 2 flowers each, we need at least 6 flowers. But we are given only 5 flowers, so, we cannot make the bouquets.

class Solution {
public:
    bool possible(vector<int>& bloomDay, int day, int m, int k) {
        int bouquets = 0;
        int flowers = 0;
        
        for (int i = 0; i < bloomDay.size(); i++) {
            if (bloomDay[i] <= day) {
                flowers++;
                if (flowers == k) {
                    bouquets++;
                    flowers = 0;
                }
            } else {
                flowers = 0;
            }
        }
        
        return bouquets >= m;
    }

    int minDays(vector<int>& bloomDay, int m, int k) {
        long long required = 1LL * m * k;
        
        // Prevent runtime error (overflow & impossible case)
        if (required > bloomDay.size()) return -1;
        
        int low = *min_element(bloomDay.begin(), bloomDay.end());
        int high = *max_element(bloomDay.begin(), bloomDay.end());
        
        while (low <= high) {
            int mid = low + (high - low) / 2;  // Safe mid calculation
            
            if (possible(bloomDay, mid, m, k)) {
                high = mid - 1;  // Try earlier day
            } else {
                low = mid + 1;   // Try later day
            }
        }
        
        return low;
    }
};
