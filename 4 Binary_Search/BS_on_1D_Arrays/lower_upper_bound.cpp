#include<bits/stdc++.h>
using namespace std;

// Problem Statement: Given a sorted array of N integers and an integer x, write a program to find the lower bound of x.

// What is lower bound?
// The lower bound algorithm finds the first or the smallest index in a sorted array where the value at that index is greater than or equal to a given key i.e. x.

// The lower bound is the smallest index, ind, where arr[ind] >= x. But if any such index is not found, the lower bound algorithm returns n i.e. size of the given array.

// Example 2:
// Input Format: N = 5, arr[] = {3,5,8,15,19}, x = 9
// Result: 3
// Explanation: Index 3 is the smallest index such that arr[3] >= x.

int lowerBound(vector<int> arr, int n, int x){
    int low = 0, high = n-1;
    int ans = n;             // ans = n acts as a safe default answer when no lower bound is found.
    while(low <= high){
        int mid = (low + high) / 2;
        // maybe an answer
        if(arr[mid] >= x){
            ans = mid;
            // look for more small index on left
            high = mid - 1;

        }else{
            low = mid + 1;   // look for right
        }
    }
    return ans;
}


// Another way we use iterator :
// int lb = lower_bound(arr.begin(), arr.end(), n) - arr.begin();



// Upper Bound :

// Problem Statement: Given a sorted array of N integers and an integer x, write a program to find the upper bound of x.
// What is Upper Bound?
// The upper bound algorithm finds the first or the smallest index in a sorted array where the value at that index is greater than the given key i.e. x.

// Example 2:
// Input Format: N = 6, arr[] = {3,5,8,9,15,19}, x = 9
// Result: 4
// Explanation: Index 4 is the smallest index such that arr[4] > x.

int UpperBound(vector<int> arr, int n, int x){
    int low = 0, high = n-1;
    int ans = n;             // ans = n acts as a safe default answer when no lower bound is found.
    while(low <= high){
        int mid = (low + high) / 2;
        // maybe an answer
        if(arr[mid] > x){     // only > 
            ans = mid;
            // look for more small index on left
            high = mid - 1;

        }else{
            low = mid + 1;   // look for right
        }
    }
    return ans;
}

