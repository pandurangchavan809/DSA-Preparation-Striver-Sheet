#include<bits/stdc++.h>
using namespace std;

// First and Last Occurance

// Problem Statement: Given a sorted array of N integers, write a program to find the index of the last occurrence of the target key. If the target is not found then return -1. Note: Consider 0 based indexing

// Example 1:
// Input:
//  N = 7, target = 13, array[] = {3, 4, 13, 13, 13, 20, 40}  
// Output:
//  4  
// Explanation:
//  The target value 13 appears for the first time at index number 2 in the array.  

// Example 2:
// Input:
//  N = 7, target = 60, array[] = {3, 4, 13, 13, 13, 20, 40}  
// Output:
//  -1  
// Explanation:
//  Target value 60 is not present in the array, so the output is -1.

// take first and last occurance as result

// TC -O(log N)   and SC- O(1)

// these also solved by lower bound and upper bound and also the standerd binary search

// By standerd Binary search

int firstOccurance(vector<int> &arr, int n, int k){
    int low = 0, high = n-1;
    int first = -1;
    while(low <= high){
        int mid = (low + high) / 2;
        if(arr[mid] == k){
            first = mid;
            high = mid - 1;
        }
        else if(arr[mid] < k) low = mid + 1;
        else high = mid-1;
    }
    return first;
}

int lastOccurance(vector<int>& arr, int n, int k){
    int low=0, high = n-1;
    int last = -1;
    while(low <= high){
        int mid = (low + high)/2;
        if(arr[mid]==k){
            last=mid;
            low=mid+1;
        }
        else if(arr[mid]<k)low=mid+1;
        else high = mid - 1;
    }
    return last;
}

pair<int, int> firstAndLastPosition(vector<int> &arr, int n, int k){
    int first = firstOccurance(arr, n, k);
    if(first==-1) return {-1, -1};
    int last = lastOccurance(arr, n, k);
    return {first, last};
}

