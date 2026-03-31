#include<bits/stdc++.h>
using namespace std;

// Combination Sum - 2 :

class Solution {
public:
    void findCombination(int ind, int target, vector<int>& arr,
                         vector<vector<int>>& ans, vector<int>& ds) {
        
        // Base case
        if (target == 0) {
            ans.push_back(ds);
            return;
        }

        for (int i = ind; i < arr.size(); i++) {

            // Skip duplicates
            if (i > ind && arr[i] == arr[i - 1]) continue;

            // If element exceeds target → stop further exploration
            if (arr[i] > target) break;

            // Pick element
            ds.push_back(arr[i]);

            // Move to next index (i+1 → cannot reuse same element)
            findCombination(i + 1, target - arr[i], arr, ans, ds);

            // Backtrack
            ds.pop_back();
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> ds;

        // Important: sort to handle duplicates
        sort(candidates.begin(), candidates.end());

        findCombination(0, target, candidates, ans, ds);
        return ans;
    }
};