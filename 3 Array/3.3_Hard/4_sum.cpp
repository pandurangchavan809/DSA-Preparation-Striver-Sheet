#include<bits/stdc++.h>
using namespace std;

// 3 sum : O(n^3)   and   O(quadralent)
/*
Algorithm

- Sort the array first.
- Use the first loop to pick the first number. Skip it if it is the same as the previous one to avoid duplicates.
- Inside it, use the second loop to pick the second number. Also skip it if it repeats the previous one.
- Set two pointers: one just after the second number (left pointer) and one at the end of the array (right pointer).
- While the left pointer is before the right pointer, calculate the total of the four chosen numbers.
- If the total equals the target, save the quadruplet, then move both pointers while skipping duplicate numbers.
- If the total is less than the target, move the left pointer one step forward to increase the total.
- If the total is greater than the target, move the right pointer one step backward to reduce the total.
- After all loops finish, return the list of unique groups of four numbers.
*/

class Solution {

public:
    // Function to find all unique quadruplets
    vector<vector<int>> fourSum(vector<int>& arr, int target) {
        int n = arr.size();
        vector<vector<int>> ans;

        // Step 1: Sort array
        sort(arr.begin(), arr.end());

        // Step 2: First loop for first number
        for (int i = 0; i < n; i++) {
            // Skip duplicates for first number
            if (i > 0 && arr[i] == arr[i - 1]) continue;

            // Step 3: Second loop for second number
            for (int j = i + 1; j < n; j++) {
                // Skip duplicates for second number
                if (j > i + 1 && arr[j] == arr[j - 1]) continue;

                // Step 4: Two pointers for remaining two numbers
                int left = j + 1, right = n - 1;
                while (left < right) {
                    long long sum = (long long)arr[i] + arr[j] + arr[left] + arr[right];

                    if (sum == target) {
                        ans.push_back({arr[i], arr[j], arr[left], arr[right]});
                        left++;
                        right--;

                        // Move left pointer skipping duplicates
                        while (left < right && arr[left] == arr[left - 1])
                            left++;
                        // Move right pointer skipping duplicates
                        while (left < right && arr[right] == arr[right + 1])
                            right--;
                    }
                    else if (sum < target) left++;
                    else right--;
                }
            }
        }
        return ans;
    }
};
