#include<bits/stdc++.h>
using namespace std;

// Count Subarray sum Equals K

/*
Input: N = 3, array[] = {1,2,3}, k = 3
Output: 2
Explanation: The subarrays that sum up to 3 are [1, 2], and [3].
*/
// better solution is by two pointer approach with two loops only.
// we use hash map for optimal approach :

//First, we will declare a map to store the prefix sums and their counts.
// Then, we will set the value of 0 as 1 on the map.
// Then we will run a loop(say i) from index 0 to n-1(n = size of the array).
// For each index i, we will do the following:
// We will add the current element i.e. arr[i] to the prefix sum.
// We will calculate the prefix sum i.e. x-k, for which we need the occurrence.
// We will add the occurrence of the prefix sum x-k i.e. mpp[x-k] to our answer.
// Then we will store the current prefix sum in the map increasing its occurrence by 1.

// O(n) and space - O(n)

int findAllSubarraysWithGivenSum(vector<int> &arr, int k){
    unordered_map<int, int>mpp;
    mpp[0]=1;
    int presum=0, cnt=0;
    for(int i=0; i<arr.size();i++){
        presum += arr[i];
        int remove = presum - k;
        cnt += mpp[remove];
        mpp[presum] += 1;    // mpp[presum]++
    }
    return cnt;
}