#include<bits/stdc++.h>
using namespace std;

// Largest Subarray with Zero Sum | Amazon | MMT

/*
Input:
 N = 6, array[] = {9, -3, 3, -1, 6, -5}  
Result:
 5  
Explanation:
 The following subarrays sum to zero:
- {-3, 3}
- {-1, 6, -5}
- {-3, 3, -1, 6, -5}
The length of the longest subarray with sum zero is 5.
*/

/*  Time complexity - O(n)  and space - O(1)

Algorithm :
- Initialize a variable sum = 0, which stores the sum of elements traversed so far, and another variable max = 0, which stores the length of the longest subarray with sum zero.
- Declare a HashMap<Integer, Integer> to store the prefix sum of every element as a key and its index as a value.
- Traverse the array and add the array element to the sum.
- If sum = 0, update max with the maximum value between max and current_index + 1, as the subarray from the start to the current index has a sum of 0.
- If sum is not equal to zero, check the HashMap to see if we've encountered this sum before.
- If the HashMap contains the sum, this indicates that a subarray with the same sum exists, so update max accordingly.
- If the sum is not found in the HashMap, insert (sum, current_index) into the HashMap to store the prefix sum until the current index.
- After traversing the entire array, the max variable will hold the length of the longest subarray with a sum equal to zero. Return max.

*/

int maxLen(int A[], int n){
    unordered_map<int, int> mpp;
    int maxi = 0;
    int sum = 0;

    for(int i=0; i<n;i++){
        sum += A[i];
        if(sum == 0){
            maxi = i + 1;
        }
        else{
            if(mpp.find(sum) != mpp.end()){
                maxi = max(maxi, i-mpp[sum]);
            }else{
                mpp[sum] = i;
            }
        }
    }
    return maxi;
}