#include <bits/stdc++.h>
using namespace std;

// Min-Heap to Max-Heap :

class Solution {
public:
    vector<int> convertMinToMaxHeap(vector<int>& nums) {
        // Build max heap using STL
        make_heap(nums.begin(), nums.end());  // default = max heap
        return nums;
    }
};

// O(N)
/*
💡 Explanation
make_heap(begin, end) → builds a max heap
Time complexity: O(n)
Works regardless of initial heap type (min or max)
🔁 If You Started With Explicit Min Heap
make_heap(heap.begin(), heap.end(), greater<int>()); // min heap

// Convert to max heap
make_heap(heap.begin(), heap.end()); // max heap
*/

// if (largest != i)  // 1 != 0 → TRUE

class Solution {
public:
    
    void maxHeapify(vector<int>& nums, int n, int i) {
        int largest = i;
        int left = 2 * i + 1;
        int right = 2 * i + 2;

        if (left < n && nums[left] > nums[largest])
            largest = left;

        if (right < n && nums[right] > nums[largest])
            largest = right;

        if (largest != i) {
            swap(nums[i], nums[largest]);
            maxHeapify(nums, n, largest);
        }
    }

    vector<int> convertMinToMaxHeap(vector<int>& nums) {
        int n = nums.size();

        // Start from last non-leaf node
        for (int i = n / 2 - 1; i >= 0; i--) {
            maxHeapify(nums, n, i);
        }

        return nums;
    }
};