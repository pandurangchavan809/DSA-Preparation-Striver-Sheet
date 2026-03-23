#include<bits/stdc++.h>
using namespace std;

// Detect a loop or cycle in LinkedList


// Time Complexity: O(N), we traverse the entire linked list once
//  O(1) , constant amount of extra space is used detect a cycle using Floyd's Cycle Detection Algorithm.

struct ListNode {
   int val;
   ListNode *next;
   ListNode() : val(0), next(nullptr) {}
   ListNode(int x) : val(x), next(nullptr) {}
   ListNode(int x, ListNode *next) : val(x), next(next) {}
};

bool detectCycle(ListNode *head){
    ListNode* slow=head;
    ListNode* fast = head;
    while(fast!=NULL && fast->next != NULL){
        slow=slow->next;
        fast=fast->next->next;
        if(slow==fast)return true;
    }
    return false;
}