#include<bits/stdc++.h>
using namespace std;

// Jump Game 2 :

class Solution {
public:
    // Function to compute the minimum number of jumps to reach the last index
    int jump(vector<int>& nums) {
        // Initialize variables to keep track of range and jumps
        int jumps = 0, currentEnd = 0, farthest = 0;

        // Traverse through the array (excluding the last element)
        for (int i = 0; i < nums.size() - 1; ++i) {
            // Update the farthest index that can be reached so far
            farthest = max(farthest, i + nums[i]);

            // When we reach the end of the current jump range
            if (i == currentEnd) {
                // We need to make a jump
                jumps++;

                // Move the current end to the farthest index we can reach
                currentEnd = farthest;
            }
        }

        // Return the total jumps needed
        return jumps;
    }
};


/*
Time Complexity: O(N),We traverse the entire array once from start to end.

Space Complexity: O(1),No extra space is used apart from a few integer variables.
*/