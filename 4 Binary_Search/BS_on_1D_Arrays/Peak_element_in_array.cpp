#include<bits/stdc++.h>
using namespace std;

// Peak element in Array

// Problem Statement: Given an array of length N, peak element is defined as the element greater than both of its neighbors. Formally, if arr[i] is the peak element, arr[i - 1] < arr[i] and arr[i + 1] < arr[i]. Find the index(0-based) of a peak element in the array. If there are multiple peak numbers, return the index of any peak number.

// Examples
// Input: arr[] = {1,2,3,4,5,6,7,8,5,1}
// Output: 7
// Explanation: There is only 1 peak element, 8,  that is at index 7.
// Input: arr[] = {1,2,1,3,5,6,4} 
// Output: 1 
// Explanation : There are 2 peak numbers that are at indices 1 and 5. We can return any of them.


int findPeakElement(vector<int> &arr){
    int n=arr.size();
    if(n == 1) return 0;
    if(arr[0] > arr[1]) return 0;
    if(arr[n-1] > arr[n-2]) return n-1;

    int low = 1, high = n-2;
    while(low <= high){
        int mid = (low + high)/2;
        if(arr[mid] > arr[mid-1] && arr[mid]>arr[mid+1]){
            return mid;
        }else if(arr[mid] > arr[mid-1]){
            low = mid + 1;
        }else{
            high = mid - 1;
        }
    }
    return -1;
}