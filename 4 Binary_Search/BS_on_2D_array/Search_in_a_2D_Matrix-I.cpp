#include<bits/stdc++.h>
using namespace std;

// Search in a 2D Matrix - I

// Problem Statement: You have been given a 2-D array 'mat' of size 'N x M' where 'N' and 'M' denote the number of rows and columns, respectively. The elements of each row are sorted in non-decreasing order. Moreover, the first element of a row is greater than the last element of the previous row (if it exists). You are given an integer ‘target’, and your task is to find if it exists in the given 'mat' or not.

// Examples

// Input :mat = [ [1, 2, 3, 4], [5, 6, 7, 8], [9, 10, 11, 12] ], target = 8
// Output :True.
// Explanation :The target = 8 exists in the 'mat' at index (1, 3).

// Input :mat = [ [1, 2, 4], [6, 7, 8], [9, 10, 34] ], target = 78
// Output :false.
// Explanation :The target = 78 does not exist in the 'mat'. Therefore in the output, we see 'false'.

// // Time Complexity: O(log(NxM)), where N = given row number, M = given column number.We are applying binary search on the imaginary 1D array of size NxM.


bool searchMatrix(vector<vector<int>>& mat, int target){
    int n = mat.size();
    int m = mat[0].size();
    int low =0, high=n*m-1;
    while(low <= high){
        int mid = (low + high)/2;
        int row = mid / m;
        int col = mid % m;
        if(mat[row][col] == target) return true;
        else if(mat[row][col] < target) low = mid + 1;
        else high = mid - 1;
    }
    return false;
}