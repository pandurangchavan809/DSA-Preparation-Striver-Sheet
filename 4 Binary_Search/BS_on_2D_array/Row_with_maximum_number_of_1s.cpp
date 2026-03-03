#include<bits/stdc++.h>
using namespace std;

// Row with maximum number of 1s

// Problem Statement: You have been given a non-empty grid ‘mat’ with 'n' rows and 'm' columns consisting of only 0s and 1s. All the rows are sorted in ascending order. Your task is to find the index of the row with the maximum number of ones. Note: If two rows have the same number of ones, consider the one with a smaller index. If there's no row with at least 1 zero, return -1

// Examples
// Example 1:
// Input Format: n = 3, m = 3, 
// mat[] = 
// 1 1 1
// 0 0 1
// 0 0 0
// Result: 0
// Explanation: The row with the maximum number of ones is 0 (0 - indexed).

// Time Complexity:O(n X logm), where n = given row number, m = given column number. We are using a loop running for n times to traverse the rows. Then we are applying binary search on each row with m columns.



class Solution {
public:
    // Binary search to find the first index where value >= x
    int lowerBound(vector<int> &arr, int n, int x) {
        int low = 0, high = n - 1;
        int ans = n;  // Default if x not found

        while (low <= high) {
            int mid = (low + high) / 2;
            if (arr[mid] >= x) {
                ans = mid;       // Possible answer
                high = mid - 1;  // Look for smaller index
            } else {
                low = mid + 1;   // Search right half
            }
        }
        return ans;
    }

    // Find row with max number of 1s
    int rowWithMax1s(vector<vector<int>> &matrix, int n, int m) {
        int cnt_max = 0;
        int index = -1;

        for (int i = 0; i < n; i++) {
            int cnt_ones = m - lowerBound(matrix[i], m, 1);  // 1s = total - index of first 1
            if (cnt_ones > cnt_max) {
                cnt_max = cnt_ones;
                index = i;
            }
        }
        return index;
    }
};



