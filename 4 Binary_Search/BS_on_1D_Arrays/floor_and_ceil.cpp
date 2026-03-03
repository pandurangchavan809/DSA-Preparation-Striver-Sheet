#include<bits/stdc++.h>
using namespace std;

// Floor and Seil

// floor : largest no in array <= x
// ceil : smallest no in an array >= x

// Example 1:
// Input Format: n = 6, arr[] ={3, 4, 4, 7, 8, 10}, x= 5
// Result: 4 7
// Explanation: The floor of 5 in the array is 4, and the ceiling of 5 in the array is 7.

// Example 2:
// Input Format: n = 6, arr[] ={3, 4, 4, 7, 8, 10}, x= 8
// Result: 8 8
// Explanation: The floor of 8 in the array is 8, and the ceiling of 8 in the array is also 8.

// Ceil :

int findCeil(vector<int> arr, int n, int x){
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


// Floor :

int Floor(vector<int> arr, int n, int x){
    int low = 0, high = n-1;
    int ans = -1;             // ans = n acts as a safe default answer when no lower bound is found.
    while(low <= high){
        int mid = (low + high) / 2;
        // maybe an answer
        if(arr[mid] >= x){
            ans = mid;
            // look for more small index on left
            low = mid + 1;

        }else{
            high = mid - 1;   // look for right
        }
    }
    return ans;
}