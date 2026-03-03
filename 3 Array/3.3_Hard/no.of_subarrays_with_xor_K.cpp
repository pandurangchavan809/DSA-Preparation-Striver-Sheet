#include<bits/stdc++.h>
using namespace std;

// Problem Statement: Given an array of integers A and an integer B. Find the total number of subarrays having bitwise XOR of all elements equal to k.

// Input: A = [4, 2, 2, 6, 4] , k = 6
// Output: 4
// Explanation: The subarrays having XOR of their elements as 6 are  [4, 2], [4, 2, 2, 6, 4], [2, 2, 6], [6]

// Algorithm :
/*
- Initialize a hashmap to store how many times each prefix XOR has appeared.
- Keep a variable to store the current prefix XOR as we move through the array.
- Keep another variable to count the total number of subarrays with XOR equal to k.
- For each element in the array, update the prefix XOR by combining it with the current element.
- If the prefix XOR itself is equal to k, increase the count by one.
- Check if there exists a prefix XOR seen before that can make the subarray XOR equal to k, and if yes, add its frequency from the hashmap to the count.
- Store or update the frequency of the current prefix XOR in the hashmap.
- After processing all elements, the count will be the total number of subarrays with XOR equal to k.
*/


// Time Complexity : O(n) or Nlog(N)  and S--> O(n)

int subarraysWithSumK(vector<int> a, int k){
    int xr = 0;
    map<int, int> mpp;
    mpp[xr]++;
    int cnt = 0;
    for(int i=0; i<a.size(); i++){
        xr = xr ^ a[i];
        // k
        int x = xr ^ k;
        cnt += mpp[x];
        mpp[xr]++;
    }
    return cnt;
}