#include<bits/stdc++.h>
using namespace std;

// Minimum number of platforms required for a railway:

int countPlatform(int n, int arr[], int dep[]){
    //sort arrival and departure times
    sort(arr, arr + n);
    sort(dep, dep + n);

    // Initial pointers and counters
    int platforms = 1;
    int result = 1;
    int i=1, j=0;   // i=0 instead we use 1 becz arrival always then only departure happend

    // Traverse both arrays
    while(i < n && j < n){
        // if next train arrives before current one departs
        if(arr[i] <= dep[j]){
            // one more platform needed
            platforms++;
            i++;
        }else{
            // one train departs, platform freed
            platforms--;
            j++;
        }
        result=max(result, platforms);
    }
    return result;
}

/*
Time Complexity: 2 O(N*logN + N) ~= O(N*logN), we sort both the arrival and departure arrays.
Space Complexity: O(1), constant additional space is used.
*/