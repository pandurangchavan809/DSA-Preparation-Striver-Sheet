#include <bits/stdc++.h>
using namespace std;

// 3 Sum :    O(NlogN)+O(N2)  and  Space - O(no. of quadruplets)

/*
Approach
- Sort the array first.
- Fix the first number using a loop from the beginning to the end of the array.
- Skip the number if it is the same as the previous one (to avoid duplicates).

Use two pointers:
- Left: starts right after the fixed number.
- Right: starts from the last element of the array.
While the left pointer is before the right pointer:
  - If the total is greater than 0 → move the right pointer one step left.
  - If the total is less than 0 → move the left pointer one step right.
  - If the total equals 0 → store the triplet, then move both pointers while skipping duplicates.
*/

// Function to find triplets with sum zero
vector<vector<int>> threeSum(vector<int> &arr, int n)
{
    // Sort the array
    sort(arr.begin(), arr.end());
    // Store final result
    vector<vector<int>> ans;

    // First loop for first element
    for (int i = 0; i < n; i++)
    {
        // Skip duplicates for first element
        if (i > 0 && arr[i] == arr[i - 1])
            continue;

        // Two pointers
        int left = i + 1, right = n - 1;

        // Find pairs for current arr[i]
        while (left < right)
        {
            int sum = arr[i] + arr[left] + arr[right];

            if (sum == 0)
            {
                ans.push_back({arr[i], arr[left], arr[right]});
                left++, right--;

                // Skip duplicates for left
                while (left < right && arr[left] == arr[left - 1])
                    left++;
                // Skip duplicates for right
                while (left < right && arr[right] == arr[right + 1])
                    right--;
            }
            else if (sum < 0)
                left++;
            else
                right--;
        }
    }
    return ans;
}
