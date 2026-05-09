#include<bits/stdc++.h>
using namespace std;

// Shortest Job First (or SJF) CPU Scheduling :


// Class that implements Shortest Job First (SJF) scheduling
class ShortestJobFirst {
public:
    // Function to calculate average waiting time
    float calculateAverageWaitTime(vector<int>& jobs) {
        // Sort jobs in ascending order (Shortest Job First)
        sort(jobs.begin(), jobs.end());

        float waitTime = 0;  // Stores cumulative waiting time
        int totalTime = 0;   // Tracks elapsed execution time
        int n = jobs.size(); // Number of jobs

        // Iterate through each job to calculate waiting time
        for (int i = 0; i < n; i++) {
            waitTime += totalTime;  // Add current total time to waiting time
            totalTime += jobs[i];   // Execute current job
        }

        // Return the average waiting time
        return waitTime / n;
    }
};


/*
Time Complexity: O(N logN + N) where N is the length of the jobs array. We sort the jobs array giving complexity O(N log N) and to calculate the waiting time we iterate through the sorted array taking O(N) complexity.

Space Complexity: O(1) as the algorithm uses only a constant amount of extra space regardless of the size of the input array. It does not require any additional data structures that scale with the input size.
*/