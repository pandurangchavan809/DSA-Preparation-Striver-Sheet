#include<bits/stdc++.h>
using namespace std;

// Sliding Window Maximum :

class Solution {
public:
    // Function to return the max of each sliding window of size k
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        // Deque to store indices of useful elements in the current window
        deque<int> dq;

        // Result vector to store the maximums
        vector<int> result;

        // Loop through each element in the array
        for (int i = 0; i < nums.size(); i++) {
            // Remove elements from the front if they are out of this window's range
            if (!dq.empty() && dq.front() <= i - k) {
                dq.pop_front();
            }

            // Remove all elements from the back that are smaller than current element
            while (!dq.empty() && nums[dq.back()] < nums[i]) {
                dq.pop_back();
            }

            // Add the current index to the deque
            dq.push_back(i);

            // Once the first window is completed, add front element to result
            if (i >= k - 1) {
                result.push_back(nums[dq.front()]);
            }
        }

        // Return the final result
        return result;
    }
};

// Time Complexity: O(n) Each element is pushed and popped from the deque at most once, so overall traversal is linear.

// Space Complexity: O(k) Deque stores at most k elements at any time, one for each index in the window.
