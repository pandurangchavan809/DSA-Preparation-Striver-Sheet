#include<bits/stdc++.h>
using namespace std;

// Top k frequent elements :

/*
// Given an integer array nums and an integer k, return the k most frequent elements. You may return the answer in any order.

// Input: nums = [1,1,1,2,2,3], k = 2
// Output: [1,2]
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        
        // Step 1: Frequency map
        unordered_map<int, int> freq;
        for(int num : nums) {
            freq[num]++;
        }

        // Step 2: Min heap (pair: {frequency, element})
        priority_queue<
            pair<int,int>, 
            vector<pair<int,int>>, 
            greater<pair<int,int>>
        > pq;

        // Step 3: Push into heap
        for(auto &it : freq) {
            pq.push({it.second, it.first});
            
            if(pq.size() > k) {
                pq.pop(); // remove least frequent
            }
        }

        // Step 4: Extract results
        vector<int> result;
        while(!pq.empty()) {
            result.push_back(pq.top().second);
            pq.pop();
        }

        return result;
    }
};

/*
⚡ Time Complexity
Frequency map: O(n)
Heap operations: O(n log k)
Overall: O(n log k)
*/
// sc - O(N)