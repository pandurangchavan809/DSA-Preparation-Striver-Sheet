// Hashing | Maps | Time Complexity | Collisions | Division Rule of Hashing | Strivers A2Z DSA Course

// Hashing : prestoring and fetching when required
// in int main function we can't declare the array size above 10^6 as after that a segmentation error.
// but if it is declared globally 10^7 later that we have another methods to use.  Maps --> hash map, undefined map


#include<iostream>
using namespace std;

int main(){
    int n;
    cin>>n;
    int arr[n];
    for (int i=0;i<n;i++){
        cin>>arr[i];
    }

    // precompute
    int hash[13]={0};
    for(int i=0;i<n;i++){
        hash[arr[i]] += 1;
    }

    int q;
    cin>>q;
    while(q--){
        int number;
        cin>>number;
        //fetch
        cout<<hash[number]<<endl;
    }
    return 0;
}



// for string :

// to get index we use ASCII values as a=97 and z=122....to store index = 'a'-'f' = 5 as [a] = 'a' - 'a' = 0, b=1, same on.... for Upper Case use 'A'.
int main(){
    string s;
    cin>>s;

    // pre compute
    int hash[26] = {0};
    for(int i=0; i<s.size();i++){
        hash[s[i] - 'a']++;
    }

    int q;
    cin>>q;
    while(q--){
        char c;
        cin>> c;
        // fetch
        cout<< hash[c-'a']<<endl;
    }
    return 0;
}


// Map :  map<int, int>mpp; ... map<long, long>mbb; depending on the length we use int, long, long long.
// unordered_map<int, int>mpp;

// map stored all valued in the sorted order 
// unordered map stored without any order



// Q.1 - Counting Frequencies of each element in the array :

#include <bits/stdc++.h>

// Function to count frequency of each element in the array using unordered_map
void Frequency(int arr[], int n) {
    // Create an unordered_map to store frequency of each element
    unordered_map<int, int> map;

    // Traverse the array and count frequencies
    for (int i = 0; i < n; i++) {
        map[arr[i]]++;
    }

    // Traverse through the unordered_map and print frequencies
    for (auto x : map) {
        cout << x.first << " " << x.second << endl;
    }
}


// Q. Find the highest/lowest frequency element


// Class to count frequencies using unordered_map (hash table)
class FrequencyCounter {
public:
    void Frequency(int arr[], int n)
    {
        unordered_map<int, int> map; // Stores frequency of each element

        // Count frequencies of all elements
        for (int i = 0; i < n; i++)
            map[arr[i]]++;

        int maxFreq = 0, minFreq = n;
        int maxEle = 0, minEle = 0;

        // Traverse the map to find elements with max and min frequencies
        for (auto it : map) {
            int element = it.first;
            int count = it.second;

            // Update max frequency element
            if (count > maxFreq) {
                maxFreq = count;
                maxEle = element;
            }

            // Update min frequency element
            if (count < minFreq) {
                minFreq = count;
                minEle = element;
            }
        }

        // Print results
        cout << "The highest frequency element is: " << maxEle << "\n";
        cout << "The lowest frequency element is: " << minEle << "\n";
    }
};





int main(){

}

// Collisions and Division rule of hasing :

