#include<bits/stdc++.h>
using namespace std;

/*
nums = [0, 3, 7, 2, 5, 8, 4, 6, 0, 1]  
Output: 9  
Explanation:
The longest sequence of consecutive elements in the
array is [0, 1, 2, 3, 4, 5, 6, 7, 8], which has a length
of 9.
*/

// better approach   : o(nlogn) and space - O(1)
/*
- Begin by sorting the entire array in ascending order. This step helps group consecutive numbers together, simplifying the sequence detection process.
- Use a loop to iterate through each element of the sorted array.
- Track consecutive sequences by comparing each element arr[i] with the lastSmaller variable. If arr[i] - 1 == lastSmaller, increment the length of the current sequence (cnt) and update lastSmaller to arr[i].
- Skip the current element if arr[i] equals lastSmaller, as it's already part of a sequence.
- If arr[i] is greater than lastSmaller + 1, start a new sequence from arr[i] by updating lastSmaller to arr[i] and reset cnt to 1.
- Throughout the iteration, compare cnt with longest and update longest to store the maximum sequence length encountered.
- Note: Here, we are distorting the given array by sorting it.
*/

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();

        // Return 0 if array is empty
        if (n == 0) return 0; 

        sort(nums.begin(), nums.end()); 

        // Track last smaller element
        int lastSmaller = INT_MIN; 
        // Count current sequence length
        int cnt = 0; 
        // Track longest sequence length
        int longest = 1; 

        for (int i = 0; i < n; i++) {
            // If consecutive number exists
            if (nums[i] - 1 == lastSmaller) {
                // Increment sequence count
                cnt += 1; 
                // Update last smaller element
                lastSmaller = nums[i]; 
            } 
            // If consecutive number doesn't exits
            else if (nums[i] != lastSmaller) {
                // Reset count for new sequence
                cnt = 1; 
                // Update last smaller element
                lastSmaller = nums[i]; 
            }
            // Update longest if needed
            longest = max(longest, cnt); 
        }
        return longest;
    }
};



// Optimal solution : This solution is optimal in some constraints
// Time Complexity : O(n)         Space Complexity : O(n)

/*
- We will use two variables: cnt to store the length of the current sequence and longest to store the maximum length found.
- First, place all the array elements into a set data structure to allow efficient lookups for consecutive numbers.
- For each element x that can start a sequence (i.e., x - 1 does not exist in the set), we follow these steps:
- Initialize cnt to 1, indicating the starting element of a new sequence.
-Use the set to search for consecutive elements such as x + 1, x + 2, and so on, to determine the maximum possible length of the current sequence. Update cnt accordingly.
- Compare cnt with longest and update longest to hold the maximum value: longest = max(longest, cnt).
- Finally, longest will contain the length of the longest consecutive sequence found in the array.
*/

int longestSuccessiveElement(vector<int>&a){
    int n = a.size();
    if(n==0) return 0;
    int longest = 1;
    unordered_set<int> st;
    for(int i=0; i<n; i++){
        st.insert(a[i]);
    }

    for(auto it: st){
        if(st.find(it-1) == st.end()){
            int cnt=1;
            int x= it;
            while(st.find(x+1) != st.end()){
                x = x + 1;
                cnt = cnt + 1;
            }
            longest = max(longest, cnt);
        }
    }
    return longest;
}