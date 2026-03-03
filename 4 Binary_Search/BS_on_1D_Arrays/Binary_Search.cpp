#include<bits/stdc++.h>
using namespace std;

// Binary Search :


int bs(vector<int> &nums, int low, int high, int target){
    if(low > high) return -1;
    int mid = (low + high)/2;
    if(nums[mid]==target) return mid;
    else if(target > nums[mid]) return bs(nums, mid+1, high, target );
    return bs(nums, low, high - 1, target);
}

// Recursive implementation:

// Approach:
// Assume, the recursive function will look like this: binarySearch(nums, low, high). It basically takes 3 parameters i.e. the array, the low pointer, and the high pointer. In each recursive call, we will change the value of low and high pointers to trim down the search space. Except for this, the rest of the steps will be the same.

// The steps are as follows:

// Divide the search space into 2 halves:
// In order to divide the search space, we need to find the middle point of it. So, we will take a ‘mid’ pointer and do the following:
// mid = (low+high) // 2 ( ‘//’ refers to integer division)
// Compare the middle element with the target and trim down the search space:
// In this step, we can observe 3 different cases:
// If arr[mid] == target: We have found the target. From this step, we can return the index of the target, and the recursion will end.
// If target > arr[mid]: This case signifies our target is located on the right half of the array. So, the next recursion call will be binarySearch(nums, mid+1, high).
// If target < arr[mid]: This case signifies our target is located on the left half of the array. So, the next recursion call will be binarySearch(nums, low, mid-1).
// Base case: The base case of the recursion will be low > high. If (low > high), the search space becomes invalid which means the target is not present in the array.

class Solution {
public:
    int binarySearch(vector<int>& nums, int low, int high, int target) {
        if (low > high) return -1;

        int mid = low + (high - low) / 2;

        if (nums[mid] == target)
            return mid;
        else if (target > nums[mid])
            return binarySearch(nums, mid + 1, high, target);
        else
            return binarySearch(nums, low, mid - 1, target);
    }

    int search(vector<int>& nums, int target) {
        return binarySearch(nums, 0, nums.size() - 1, target);
    }
};


// Interative Implementation :

// Initially, the pointers low and high will be 0 and n-1(where n = size of the given array) respectively.
// Now inside a loop, we will perform the 3 steps discussed above in the algorithm section.
// The loop will run until either we fount the target or any of the pointers crosses the other.

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int low = 0, high = nums.size() - 1;

        while (low <= high) {
            int mid = low + (high - low) / 2;

            if (nums[mid] == target)
                return mid;
            else if (nums[mid] < target)
                low = mid + 1;
            else
                high = mid - 1;
        }
        return -1;
    }
};


