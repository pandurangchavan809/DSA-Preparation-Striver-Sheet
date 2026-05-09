#include <vector>
#include <queue>
using namespace std;

// Kth Smallest Element :

class Solution {
public:
    int kthSmallest(vector<int>& nums, int k) {
        priority_queue<int> maxHeap;

        for (int num : nums) {
            maxHeap.push(num);

            if (maxHeap.size() > k) {
                maxHeap.pop();
            }
        }

        return maxHeap.top();
    }
};

/*
⏱️ Complexity
Time: O(n log k)
Space: O(k)
*/