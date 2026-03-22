#include<bits/stdc++.h>
using namespace std;

// Reverse a LinkedList :

// Optimizes  (not recursive method in these question as at end taken)...uses iterative method


struct ListNode {
   int val;
   ListNode *next;
   ListNode() : val(0), next(nullptr) {}
   ListNode(int x) : val(x), next(nullptr) {}
   ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* temp = head;
        ListNode* prev = NULL;
        while(temp != NULL){
            ListNode* front = temp -> next;
            temp->next = prev;
            prev = temp;
            temp = front;
        }
        return prev;
    }
};