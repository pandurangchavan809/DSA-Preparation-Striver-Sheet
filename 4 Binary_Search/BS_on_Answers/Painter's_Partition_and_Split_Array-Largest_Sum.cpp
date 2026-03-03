#include<bits/stdc++.h>
using namespace std;

// Both are same logic for split array and painter sum 

// Painter's Partition and Split Array - Largest Sum

// Split Array - Largest Sum :

// Problem Statement: Given an integer array ‘A’ of size ‘N’ and an integer ‘K'. Split the array ‘A’ into ‘K’ non-empty subarrays such that the largest sum of any subarray is minimized. Your task is to return the minimized largest sum of the split. A subarray is a contiguous part of the array.

// Examples
// Example 1:
// Input Format: N = 5, a[] = {1,2,3,4,5}, k = 3
// Result: 6
// Explanation: There are many ways to split the array a[] into k consecutive subarrays. The best way to do this is to split the array a[] into [1, 2, 3], [4], and [5], where the largest sum among the three subarrays is only 6.

// Example 2:
// Input Format: N = 3, a[] = {3,5,1}, k = 3
// Result: 5
// Explanation: There is only one way to split the array a[] into 3 subarrays, i.e., [3], [5], and [1]. The largest sum among these subarrays is 5.

// Time Complexity: O(N * log(sum(arr[])-max(arr[])+1)), where N = size of the array, sum(arr[]) = sum of all array elements, max(arr[]) = maximum of all array elements.


// Function to count how many subarrays are formed
// if the maximum allowed subarray sum is maxAllowedSum
int countSubarrays(vector<int>& nums, int maxAllowedSum) {
    int subarrays = 1;  
    long long currentSum = 0;

    for(int i = 0; i < nums.size(); i++) {
        if(currentSum + nums[i] <= maxAllowedSum) {
            currentSum += nums[i];
        } 
        else {
            subarrays++;
            currentSum = nums[i];
        }
    }
    return subarrays;
}

// Function to minimize the largest sum among K subarrays
int splitArrayLargestSum(vector<int>& nums, int n, int k) {
    if(k > n) return -1;

    int low = *max_element(nums.begin(), nums.end());
    int high = accumulate(nums.begin(), nums.end(), 0);

    while(low <= high) {
        int mid = low + (high - low) / 2;

        int requiredSubarrays = countSubarrays(nums, mid);

        if(requiredSubarrays > k) {
            low = mid + 1;
        } 
        else {
            high = mid - 1;
        }
    }
    return low;
}