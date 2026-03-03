#include<bits/stdc++.h>
using namespace std;

// Merge Sorted Arrays Without Extra Space

// Input : nums1 = [-5, -2, 4, 5, 0, 0, 0], nums2 = [-3, 1, 8]
// Output : [-5, -3, -2, 1, 4, 5, 8]
// Explanation : The merged array is: [-5, -3, -2, 1, 4, 5, 8], where [-5, -2, 4, 5] are from nums1 and [-3, 1, 8] are from nums2

/*
Algorithm :

- To efficiently insert elements at the end, we will use three pointers.
- Initialize three pointers: One points at the last valid index (excluding zeros) of nums1, one points at the last valid index of nums2 andd the last pointer points to last index of nums1.
- Compare the elements pointed by the first two pointers and whichever is larger, place it at the third pointer's index.
- Move the respective pointer one step back and also move the third pointer one step back.
- If there are any remaining elements in nums2, then copy them in nums1. If any elements remain in nums1, they’re already in place
- The result is a fully merged and sorted array stored in nums1 itself.
*/

// O(m + n) time
// O(1) extra space

void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
    int i = m - 1;        // last valid element in nums1
    int j = n - 1;        // last element in nums2
    int k = m + n - 1;    // last index of nums1

    while (i >= 0 && j >= 0) {
        if (nums1[i] > nums2[j])
            nums1[k--] = nums1[i--];
        else
            nums1[k--] = nums2[j--];
    }

    while (j >= 0) {
        nums1[k--] = nums2[j--];
    }
}





// for two sort arrays and merge them :-  Not fit for the 

void merge(long long arr1[], long long arr2[], int n, int m){
    int left = n-1;
    int right = 0;
    while(left >= 0 && right < m){
        if(arr1[left] > arr2[right]){
            swap(arr1[left], arr2[right]);   // O(min(n,m))
            left--, right++;
        }else{
            break;
        }
    }
    sort(arr1, arr1 + n);   // O(nlogn)
    sort(arr2, arr2 + m);   // O(mlogm)
}