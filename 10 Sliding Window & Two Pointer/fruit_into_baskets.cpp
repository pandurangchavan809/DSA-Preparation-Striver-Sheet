#include<bits/stdc++.h>
using namespace std;

//  Fruit into baskets :
// There are two baskets available, and each basket can only contain one kind of fruit. The quantity of fruit each basket can contain is unlimited.
/*
Input : fruits = [1, 2, 3, 2, 2]
Output : 4
Explanation : we will start from second tree.
The first basket contains fruits from second , fourth and fifth.
The second basket will contain fruit from third tree.
Hence we collected total of 4 fruits.
*/


class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int l=0, r=0, maxlen=0, k=2;
        int n = fruits.size();
        map<int, int>mpp;

        while(r < n){
            mpp[fruits[r]]++;
            if(mpp.size() > k){
                mpp[fruits[l]]--;
                if(mpp[fruits[l]] == 0) mpp.erase(fruits[l]);
                l++;
            }

            if(mpp.size() <= k) maxlen=max(maxlen, r-l+1);
            r++;
        }
        return maxlen;
    }
};


// O(N)  && O(3) ~= O(1)