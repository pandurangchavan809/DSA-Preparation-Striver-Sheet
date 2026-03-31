#include<bits/stdc++.h>
using namespace std;

// Check if there exists a subsequence with sum K

class Solution {
private:
    // This method recursively checks for the subsequence with the given sum
    bool func(int ind, int sum, std::vector<int> &nums) {
        // Base case: if all elements are processed, check if sum is 0
        if (ind == nums.size()) {
            return sum == 0;
        }
        // Recursive call: include the current element in the subsequence
        // or exclude the current element from the subsequence
        return func(ind + 1, sum - nums[ind], nums) | func(ind + 1, sum, nums);
    }

public:
    // This method initiates the recursive process
    bool checkSubsequenceSum(std::vector<int>& nums, int target) {
        return func(0, target, nums); // Start the recursive process
    }
};


/*
Time Complexity: O(2^n), where n is the number of elements in the input array. This is because each element can either be included or excluded from the subsequence, leading to 2^n possible combinations.

Space Complexity: O(n), where n is the depth of the recursion stack. In the worst case, the recursion can go as deep as n levels, leading to a space complexity of O(n) due to the call stack.
*/
