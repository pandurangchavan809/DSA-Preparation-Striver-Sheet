#include<bits/stdc++.h>
using namespace std;

// Search Insert Position :

// Example 1:
// Input Format: arr[] = {1,2,4,7}, x = 6
// Result: 3
// Explanation: 6 is not present in the array. So, if we will insert 6 in the 3rd index(0-based indexing), the array will still be sorted. {1,2,4,6,7}.

// Example 2:
// Input Format: arr[] = {1,2,4,7}, x = 2
// Result: 1
// Explanation: 2 is present in the array and so we will return its index i.e. 1.

// same as lower bound :

int searchInsert(vector<int>&arr, int x){
    int n = arr.size();
    int low = 0, high = n - 1;
    int ans = n;
    while(low <= high){
        int mid = (low + high)/2;
        //maybe an answer
        if(arr[mid] >= x){
            ans = mid;
            //look for more small index on left
            high = mid - 1;
        }else{
            low = mid + 1;    // look for right
        }
    }
    return ans;
}

