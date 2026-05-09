#include<bits/stdc++.h>
using namespace std;

// Job Sequencing Problem :

class Solution {
public:

    struct Job {
        int id, dead, profit;
    };

    static bool comp(Job &a, Job &b) {
        return a.profit > b.profit;
    }

    vector<int> JobScheduling(Job arr[], int n) {

        sort(arr, arr + n, comp);

        int maxDead = 0;
        for (int i = 0; i < n; i++)
            maxDead = max(maxDead, arr[i].dead);

        vector<int> hash(maxDead + 1, -1);

        int cnt = 0, profit = 0;

        for (int i = 0; i < n; i++) {

            for (int j = arr[i].dead; j > 0; j--) {

                if (hash[j] == -1) {

                    hash[j] = arr[i].id;

                    cnt++;
                    profit += arr[i].profit;

                    break;
                }
            }
        }

        return {cnt, profit};
    }
};

// Time Complexity: O(N log N) + O(N * M), O(N log N) for sorting the jobs in decreasing order of profit. 