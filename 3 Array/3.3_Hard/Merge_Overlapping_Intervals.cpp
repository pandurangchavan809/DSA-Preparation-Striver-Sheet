#include<bits/stdc++.h>
using namespace std;

// Input : intervals=[[1,3],[2,6],[8,10],[15,18]]
// Output : [[1,6],[8,10],[15,18]]
// Explanation : Since intervals [1,3] and [2,6] are overlapping we can merge them to form [1,6] intervals.

// Time Complexity: O(N*logN) + O(N)   and Space :- O(N)

/*
- Sort the intervals based on their starting points. This ensures overlapping intervals come together.
- Initialize an empty list to store the final merged intervals.
- If the list is empty or the current interval starts after the last one ends, it means there is no overlap, so just add it to the list.
- If the current interval starts before or exactly at the end of the last one, it means there is overlap. So, combine both by extending the end of the last one to the further end of the two.
- Keep doing this until all intervals have been checked. The final list will now contain only non-overlapping, merged intervals.
*/

vector<vector<int>> mergeOverlappingIntervals(vector<vector<int>> &arr){
    int n = arr.size();
    sort(arr.begin(), arr.end());
    vector<vector<int>> ans;
    for(int i=0; i<n; i++){
        if(ans.empty() || arr[i][0] > ans.back()[1]){
            ans.push_back(arr[i]);
        }else{
            ans.back()[i] = max(ans.back()[i], arr[i][1]);
        }
    }
    return ans;
}