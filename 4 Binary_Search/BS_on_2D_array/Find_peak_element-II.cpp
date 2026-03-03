#include <bits/stdc++.h>
using namespace std;

// Find Peak Element (2D Matrix)

// Problem Statement: Given a 0-indexed n x m matrix mat where no two adjacent cells are equal, find any peak element mat[i][j] and return the array [i, j]. A peak element in a 2D grid is an element that is strictly greater than all of its adjacent neighbours to the left, right, top, and bottom.
// Assume that the entire matrix is surrounded by an outer perimeter with the value -1 in each cell.

// Note: As there can be many peak values, 1 is given as output if the returned index is a peak number, otherwise 0.

// all the outer parts are -1 .. help to check for first row / outer part

// Examples
// Example 1:
// Input:
//  mat = [[5, 10, 8], [4, 25, 7], [3, 9, 6]]
// Output:
//  [1, 1]
// Explanation:
//  The value at index [1, 1] is 25, which is a peak because all its neighbors (10, 7, 4, 9) are smaller.

// Example 2:
// Input:
//  mat = [[1, 2, 3], [6, 5, 4], [7, 8, 9]]
// Output:
//  [2, 2]
// Explanation:
//  The value at index [2, 2] is 9, which is a peak as it is greater than its neighbors (8, 4).

// Time Complexity: O(N * logM), where N is the number of rows in the matrix, M is the number of columns in each row. The complexity arises because binary search is performed on the columns, and for each mid column, a linear search through the rows is executed to find the maximum element.

class Solution
{
public:
    // Function to find the index of the row
    // with the maximum element in a given column
    int maxElement(vector<vector<int>> &arr, int col)
    {
        int n = arr.size();
        int max_val = INT_MIN;
        int index = -1;

        // Iterate through each row to find the maximum element
        // in the particular column
        for (int i = 0; i < n; i++)
        {
            if (arr[i][col] > max_val)
            {
                max_val = arr[i][col];
                index = i;
            }
        }
        return index;
    }

    // Function to find a peak element in the 2D matrix
    // using binary search
    vector<int> findPeakGrid(vector<vector<int>> &arr)
    {
        int n = arr.size();
        int m = arr[0].size();

        // Initialize the lower and upper bounds for binary search
        int low = 0;
        int high = m - 1;

        // Perform binary search on columns
        while (low <= high)
        {
            int mid = (low + high) / 2;

            // Find the index of the row with the maximum element
            // in the middle column
            int row = maxElement(arr, mid);

            // Determine the elements to the left and right of
            // the middle element in the found row
            int left = mid - 1 >= 0 ? arr[row][mid - 1] : INT_MIN;
            int right = mid + 1 < m ? arr[row][mid + 1] : INT_MIN;

            // Check if the middle element is greater than its neighbors
            if (arr[row][mid] > left && arr[row][mid] > right)
            {
                return {row, mid};
            }
            else if (left > arr[row][mid])
            {
                high = mid - 1;
            }
            else
            {
                low = mid + 1;
            }
        }

        // Return {-1, -1} if no peak element is found
        return {-1, -1};
    }
};
