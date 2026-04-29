#include<bits/stdc++.h>
using namespace std;

// Count number of nice subarrays

// Problem Statement: Given an array nums and an integer k. An array is called nice if and only if it contains k odd numbers. Find the number of nice subarrays in the given array nums. A subarray is continuous part of the array.
/*
Input :nums = [1, 1, 2, 1, 1] , k = 3
Output :2
Explanation :The subarrays with three odd numbers are [1, 1, 2, 1] [1, 2, 1, 1]

Input : nums = [4, 8, 2] , k = 1
Output :0
Explanation :The array does not contain any odd number.
*/

class Solution {
public:
    // function to count subarrays with at most k odd numbers
    int countAtMost(vector<int>& nums, int k) {
        // Initialize variables
        int left = 0, res = 0;

        // Traverse through the array
        for (int right = 0; right < nums.size(); right++) {
            // If current number is odd, reduce k
            if (nums[right] % 2 != 0)
                k--;

            // Shrink the window until k is valid
            while (k < 0) {
                if (nums[left] % 2 != 0)
                    k++;
                left++;
            }

            // Add valid subarrays ending at right
            res += (right - left + 1);
        }

        // Return the count of valid subarrays
        return res;
    }

    // Main function to get number of subarrays with exactly k odd numbers
    int numberOfSubarrays(vector<int>& nums, int k) {
        return countAtMost(nums, k) - countAtMost(nums, k - 1);
    }
};

/*
Time Complexity:O(n) ,We scan the array two times using the sliding window helper. Each scan processes every element at most once, making it linear in size of input.

Space Complexity:O(1) ,No additional space is used except a few integer variables for tracking window bounds and counts. So, constant space.
*/