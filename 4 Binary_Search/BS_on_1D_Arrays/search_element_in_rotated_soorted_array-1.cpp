#include<bits/stdc++.h>
using namespace std;

// Search Element in a Rotated Sorted Array

// Problem Statement: Given an integer array nums, sorted in ascending order (with distinct values) and a target value k. The array is rotated at some pivot point that is unknown. Find the index at which k is present and if k is not present return -1.

// Examples
// Input:nums = [4, 5, 6, 7, 0, 1, 2], k = 0
// Output :4
// Explanation : Here, the target is 0. We can see that 0 is present in the given rotated sorted array, nums. Thus, we get output as 4, which is the index at which 0 is present in the array.

// Input: nums = [4, 5, 6, 7, 0, 1, 2], k = 3
// Output :-1
// Explanation :Here, the target is 3. Since 3 is not present in the given rotated sorted array. Thus, we get the output as -1.


class Solution {
public:
    // Function to search for target using binary search in rotated sorted array
    int search(vector<int>& nums, int target) {

        // Set the search space to entire array
        int low = 0;
        int high = nums.size() - 1;

        // Continue until the search space becomes invalid
        while (low <= high) {

            // Find the middle index
            int mid = (low + high) / 2;

            // If the target is found at mid, return mid
            if (nums[mid] == target)
                return mid;

            // Check if the left half is sorted
            if (nums[low] <= nums[mid]) {

                // If target lies in the sorted left half, search there
                if (nums[low] <= target && target < nums[mid]) {
                    high = mid - 1;
                }
                // Else search in the right half
                else {
                    low = mid + 1;
                }
            }

            // Otherwise, right half is sorted
            else {

                // If target lies in the sorted right half, search there
                if (nums[mid] < target && target <= nums[high]) {
                    low = mid + 1;
                }
                // Else search in the left half
                else {
                    high = mid - 1;
                }
            }
        }

        // If not found, return -1
        return -1;
    }
};
