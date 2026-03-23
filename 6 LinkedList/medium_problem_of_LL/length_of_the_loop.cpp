#include<bits/stdc++.h>
using namespace std;

// Find the length of the Loop in LinkedList

// default written in leetcode platform :
struct ListNode {
   int val;
   ListNode *next;
   ListNode() : val(0), next(nullptr) {}
   ListNode(int x) : val(x), next(nullptr) {}
   ListNode(int x, ListNode *next) : val(x), next(next) {}
};


int findLength(ListNode* slow, ListNode* fast){
    int cnt = 1;
    fast = fast->next;
    while(slow != fast){
        cnt++;
        fast=fast->next;
    }
    return cnt;
}

int lengthOfLoop(ListNode* head){
    ListNode* slow = head;
    ListNode* fast = head;

    while(fast != NULL && fast->next != NULL){
        slow = slow->next;
        fast=fast->next->next;
        if(slow == fast){
            return findLength(slow, fast);
        }
    }
}


// Time Complexity :- Time Complexity: O(N), we traverse the entire linked list atleast once to find the length of the loop.

// Space Complexity :- O(1) constant extra space. No additional data structures are used, only two pointers.