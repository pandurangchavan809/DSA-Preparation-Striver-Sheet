#include <vector>
#include <queue>
using namespace std;

// Kth largest element :

// Kth largest/smallest element in an array :
/*
Problem Statement: Given an array nums, return the kth largest element in the array.
Input:
 nums = [1, 2, 3, 4, 5], k = 2  
Output:
 4  
Explanation:
 The 2nd largest number in the list [1, 2, 3, 4, 5] is 4.
*/


class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int, vector<int>, greater<int>> minHeap;

        for (int num : nums) {
            minHeap.push(num);

            if (minHeap.size() > k) {
                minHeap.pop();
            }
        }

        return minHeap.top();
    }
};

/*
⏱️ Complexity
Time: O(n log k)
Space: O(k)
*/