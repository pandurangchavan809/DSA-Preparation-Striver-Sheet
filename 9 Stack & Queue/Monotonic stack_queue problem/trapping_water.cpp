#include<bits/stdc++.h>
using namespace std;

// Trapping RainWater :

int trap(vector<int> &trap){

    // size of trap array
    int n = trap.size();
    int lmax=0, rmax=0, total=0;
    int left=0, right=n-1;
    
    while(left < right) {
        if(trap[left] <= trap[right]){
            if(lmax > trap[left]){
                total += lmax - trap[left];
            } 
            else lmax = trap[left];
            left++;
        } else {
            if ( rmax > trap[right]){
                total += rmax - trap[right];
            } 
            else rmax = trap[right];
            right--;
        }
    } 
    return total;  
}

// O(N)  & O(N)
