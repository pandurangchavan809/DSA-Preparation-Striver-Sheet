#include<bits/stdc++.h>
using namespace std;

// Count all subsequences with sum K :
// watch screenshot you will understand :

class Solution {
private:
    // Helper function to count subsequences
    // with the target sum
    int func(int ind, int sum, vector<int> &nums) {
        // Base case: if sum is 0, one valid
        // subsequence is found
        if (sum == 0) return 1;
        // Base case: if sum is negative or 
        // index exceeds array size
        if (sum < 0 || ind == nums.size()) return 0;
        // Recurse by including current number
        // or excluding it from the sum
        return func(ind + 1, sum - nums[ind], nums) + func(ind + 1, sum, nums);
    }

public:
    // Function to start counting subsequences
    int countSubsequenceWithTargetSum(vector<int>& nums, int target) {
        return func(0, target, nums);
    }
};


/*
Time Complexity: O(2^n), where n is the number of elements in the array. This is because each element can either be included or excluded from the subsequence, leading to 2^n possible combinations.

Space Complexity: O(n), where n is the depth of the recursion stack. In the worst case, the recursion can go as deep as the number of elements in the array.
*/