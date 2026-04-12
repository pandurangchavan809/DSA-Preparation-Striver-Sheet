#include<bits/stdc++.h>
using namespace std;

// Minimum bits flips to convert number :

int minBitsFlip(int start, int goal){
    /* variable to store bits that are different in both numbers*/
    int num = start ^ goal;

    // variant to store bits  that are different in both numbers
    int count = 0;

    for(int i=0; i < 32; i++){
        // update count if the rightmost bit is set
        count += (num & 1);

        // shift the number every time by 1 place
        num = num >> 1;
    }
    return count;
}