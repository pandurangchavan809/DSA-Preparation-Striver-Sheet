#include<bits/stdc++.h>
using namespace std;

// Quick Sort : It is a divide and conquer algorithm. It works by selecting a 'pivot' element from the array and partitioning the other elements into two sub-arrays according to whether they are less than or greater than the pivot. The sub-arrays are then sorted recursively.

// Time Complexity: O(n log n) on average, O(n^2) in the worst case.
// Space Complexity: O(log n) due to recursive stack space.

// Algorithm :

// Select a pivot element from the array (commonly the last element, but can be first, middle, or random).
// Rearrange the elements in the array such that all elements smaller than the pivot are placed before it and all greater elements are placed after it (this step is called partitioning).
// After partitioning, the pivot is in its correct sorted position.
// Recursively apply the same process to the subarrays on the left and right of the pivot.
// Base condition for recursion is when the subarray has zero or one element, as it's already sorted.
// Combine the results of the recursive calls to obtain the fully sorted array.


class Solution {
public:
    // Function to perform quicksort
    void quickSort(vector<int>& arr, int low, int high) {
        // Base case: if low is not less than high
        if (low < high) {
            // Find pivot index after partitioning
            int pivotIndex = partition(arr, low, high);

            // Recursively sort elements before pivot
            quickSort(arr, low, pivotIndex - 1);

            // Recursively sort elements after pivot
            quickSort(arr, pivotIndex + 1, high);
        }
    }

    // Function to partition the array
    int partition(vector<int>& arr, int low, int high) {
        // Choose the last element as pivot
        int pivot = arr[high];

        // Initialize i to place smaller elements
        int i = low - 1;

        // Traverse the array
        for (int j = low; j < high; j++) {
            // If element is smaller than or equal to pivot
            if (arr[j] <= pivot) {
                // Increment i and swap with j
                i++;
                swap(arr[i], arr[j]);
            }
        }

        // Place pivot in correct position
        swap(arr[i + 1], arr[high]);

        // Return pivot index
        return i + 1;
    }
};

int main() {
    // Sample array
    vector<int> arr = {10, 7, 8, 9, 1, 5};

    // Create solution object
    Solution sol;

    // Apply quicksort
    sol.quickSort(arr, 0, arr.size() - 1);

    // Print sorted array
    for (int num : arr)
        cout << num << " ";
    
    return 0;
}
