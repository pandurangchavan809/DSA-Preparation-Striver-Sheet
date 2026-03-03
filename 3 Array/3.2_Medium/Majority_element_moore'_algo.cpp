#include<bits/stdc++.h>
using namespace std;

// Function to find the majority element using Moore's Voting Algorithm.
int MajorityElement(vector<int>& v){
    int cnt = 0;
    int el;
    for(int i=0; i<v.size(); i++){
        if(cnt == 0){
            el = v[i];
            cnt = 1;
        }
        else if(v[i] == el){
            cnt++;
        }else{
            cnt--;
        }
    }
    // Checking if the stored element is the majority element 
    int cnt1 = 0;
    for(int i=0; i<v.size();i++){
        if(v[i] == el) cnt1++;
    }
    // return element if it is a majority element
    if(cnt1 > (v.size()/2)){
        return el;
    }
    // return -1 if no such element found
    return -1;

}
