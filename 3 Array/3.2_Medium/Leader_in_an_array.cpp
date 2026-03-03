#include<bits/stdc++.h>
using namespace std;

// Leaders in an Array :

/*
 arr = [10, 22, 12, 3, 0, 6]  
Output:
 22 12 6  
Explanation:
 6 is a leader because there are no elements after it.  
12 is greater than all the elements to its right (3, 0, 6), and 22 is greater than 12, 3, 0, 6, making them leaders as well.
*/
// Time complexity : O()

vector<int> superiorElements(vector<int>&a){
    vector<int> ans;
    int maxi = INT_MIN;
    int n = a.size();

    for(int i=n-1; i>=0; i--){
        if(a[i]>maxi){
            ans.push_back(a[i]);
        }
        // keep track of right max
        maxi = max(maxi, a[i]);
    }
    sort(ans.begin(), ans.end());
    return ans;
}