#include <bits/stdc++.h>
using namespace std;

// Search Element in Rotated Sorted Array II  [duplicates]

// Problem Statement: Given an integer array arr of size N, sorted in ascending order (may contain duplicate values) and a target value k. Now the array is rotated at some pivot point unknown to you. Return True if k is present and otherwise, return False.

// Examples
// Example 1:
// Input Format: arr = [7, 8, 1, 2, 3, 3, 3, 4, 5, 6], k = 3
// Result: True
// Explanation: The element 3 is present in the array. So, the answer is True.

// Example 2:
// Input Format: arr =[7, 8, 1, 2, 3, 3, 3, 4, 5, 6],  k=10
// Result: False
// Explanation: The element 10 is not present in the array. So, the answer is False.

// we have to just add arr[low]==arr[mid]==arr[high]....we shrink the low and high by +1 and -1 so that condition not occure.
// remaining same
// Time Complexity: O(logN) for the best and average case. O(N/2) for the worst case. Here, N = size of the given array.

class Solution
{
public:
    // Function to search for target using binary search in rotated sorted array
    int search(vector<int> &nums, int target)
    {

        // Set the search space to entire array
        int low = 0;
        int high = nums.size() - 1;

        // Continue until the search space becomes invalid
        while (low <= high)
        {

            // Find the middle index
            int mid = (low + high) / 2;

            // If the target is found at mid, return mid
            if (nums[mid] == target)
                return mid;

            // Edge case: all three are equal, we cannot determine which side is sorted
            if (nums[low] == nums[mid] && nums[mid] == nums[high])
            {
                low++;
                high--;
                continue;
            }

            // Check if the left half is sorted
            if (nums[low] <= nums[mid])
            {

                // If target lies in the sorted left half, search there
                if (nums[low] <= target && target < nums[mid])
                {
                    high = mid - 1;
                }
                // Else search in the right half
                else
                {
                    low = mid + 1;
                }
            }

            // Otherwise, right half is sorted
            else
            {

                // If target lies in the sorted right half, search there
                if (nums[mid] < target && target <= nums[high])
                {
                    low = mid + 1;
                }
                // Else search in the left half
                else
                {
                    high = mid - 1;
                }
            }
        }

        // If not found, return -1
        return -1;
    }
};
