#include<bits/stdc++.h>
using namespace std;

// Remove duplicates from Sorted Array
// optimal approach : TC- O(n) SC- O(1) .... because we are not using any extra space
int removeDuplicates(vector<int> &arr, int n){
    int i = 0;
    for(int j =i; j<n; j++){
        if(arr[i] != arr[j]){
            arr[i+1] = arr[j];
            i++;
        }       
    }
}