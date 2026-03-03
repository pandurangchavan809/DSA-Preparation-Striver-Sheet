#include<bits/stdc++.h>
using namespace std;


// Union of two sorted arrays :
// Time Complexity: O(n1 + n2)
// Space Complexity: O(n1 + n2) in worst case

vector <int> sortedArray(vector<int> a, vector<int> b){
    int n1 = a.size();
    int n2 = b.size();
    int i=0;
    int j=0;
    vector<int> unionArr;
    while(i<n1 && j<n2){
        if(a[i]<= b[j]){
            if(unionArr.size()==0 || unionArr.back() != a[i]){
                unionArr.push_back(a[i]);
            }
            i++;
        }
        else{
            if(unionArr.size()==0 || unionArr.back() != b[j]){
                unionArr.push_back(b[j]);
            }
            j++;
        }
    }
    while(j<n2){
        if(unionArr.size()==0||unionArr.back() != b[j]){
            unionArr.push_back(b[j]);
        }
        j++;
    }

    while(i<n1){
        if(unionArr.size()==0 || unionArr.back() != a[i]){
            unionArr.push_back(a[i]);
        }
        i++;
    }

    return unionArr;
}


// Intersection of two sorted arrays :
// Time Complexity: O(n1 + n2)
// Space Complexity: O(1)

vector<int> findArrayInteresection(vector<int>&A, int n, vector<int>&B, int m){
    int i=0;
    int j=0;
    vector<int> ans;
    while(i<n && j<m){
        if(A[i]<B[j]){
            i++;
        }
        else if(A[i]>B[j]){
            j++;
        }
        else{
            ans.push_back(A[i]);
            i++;
            j++;
        }
    }
    return ans;
}