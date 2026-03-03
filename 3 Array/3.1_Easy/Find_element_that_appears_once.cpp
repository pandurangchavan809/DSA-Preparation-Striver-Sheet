#include<bits/stdc++.h>
using namespace std;

// Find element that appears once

int getSingleElement(vector<int> &arr){
    int xarr = 0;
    for(int i=0; i<arr.size(); i++){
        xarr ^= arr[i];
    }
    return xarr;
}