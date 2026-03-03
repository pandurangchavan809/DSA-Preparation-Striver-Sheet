#include<bits/stdc++.h>
using namespace std;

// Aggressive Cows : Detailed Solution     & also same logic for 
// 1552. Magnetic Force Between Two Balls

// Problem Statement: You are given an array 'arr' of size 'n' which denotes the position of stalls. You are also given an integer 'k' which denotes the number of aggressive cows.
// You are given the task of assigning stalls to 'k' cows such that the minimum distance between any two of them is the maximum possible. Find the maximum possible minimum distance.

// Examples
// Example 1:
// Input Format:
//  N = 6, k = 4, arr[] = {0,3,4,7,10,9}
// Result:
//  3
// Explanation:
//  The maximum possible minimum distance between any two cows will be 3 when 4 cows are placed at positions {0, 3, 7, 10}. Here the distances between cows are 3, 4, and 3 respectively. We cannot make the minimum distance greater than 3 in any ways.



bool canwePlace(vector<int>&stalls, int dist, int cows){
    int cntCows = 1, last = stalls[0];
    for(int i=1; i<stalls.size();i++){
        if(stalls[i]-last >= dist){
            cntCows++;
            last = stalls[i];
        }
        if(cntCows >= cows) return true;
    }
    return false;
}

int aggressiveCows(vector<int> &stalls, int k){
    sort(stalls.begin(),stalls.end());
    int n=stalls.size();
    int low=1, high=stalls[n-1] - stalls[0];
    while(low <= high){
        int mid = (low + high)/2;
        if(canwePlace(stalls, mid, k)== true){
            low = mid + 1;
        }else{
            high = mid - 1;
        }
    }
    return high;
}