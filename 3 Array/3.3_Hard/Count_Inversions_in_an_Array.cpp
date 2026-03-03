#include<bits/stdc++.h>
using namespace std;

// Count Inversions in an Array

// Algorithms : https://takeuforward.org/data-structure/count-inversions-in-an-array

// Complexity Analysis

// Time Complexity: O(N log N), since it is based on merge sort.

// Space Complexity: O(N), for the temporary array used during merging.

class Solution {
public:
    // Merge two sorted halves and count inversions
    int merge(vector<int>& arr, int low, int mid, int high) {
        vector<int> temp;              // Temporary array for merging
        int left = low;                // Pointer for left half
        int right = mid + 1;           // Pointer for right half
        int cnt = 0;                   // Inversion count

        // Merge while counting inversions
        while (left <= mid && right <= high) {
            if (arr[left] <= arr[right]) {
                temp.push_back(arr[left++]);
            } else {
                temp.push_back(arr[right++]);
                cnt += (mid - left + 1);   // Count inversions
            }
        }

        // Copy remaining elements from left half
        while (left <= mid) {
            temp.push_back(arr[left++]);
        }

        // Copy remaining elements from right half
        while (right <= high) {
            temp.push_back(arr[right++]);
        }

        // Copy merged result back to original array
        for (int i = low; i <= high; i++) {
            arr[i] = temp[i - low];
        }

        return cnt;
    }

    // Recursive merge sort that returns inversion count
    int mergeSort(vector<int>& arr, int low, int high) {
        if (low >= high) return 0;      // Base case

        int mid = (low + high) / 2;
        int cnt = 0;

        cnt += mergeSort(arr, low, mid);        // Left inversions
        cnt += mergeSort(arr, mid + 1, high);   // Right inversions
        cnt += merge(arr, low, mid, high);      // Cross inversions

        return cnt;
    }

    // Function called by LeetCode
    int numberOfInversions(vector<int>& nums) {
        return mergeSort(nums, 0, nums.size() - 1);
    }
};
