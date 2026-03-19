#include<bits/stdc++.h>
using namespace std;

// Find middle element in a Linked List

// Problem Statement: Given the head of a linked list of integers, determine the middle node of the linked list. However, if the linked list has an even number of nodes, return the second middle node.

//  time complexity linear, or O(N/2) ~ O(N).  Sc- O(1)

// Definition for singly-linked list.
struct ListNode {
   int val;
   ListNode *next;
   ListNode() : val(0), next(nullptr) {}
   ListNode(int x) : val(x), next(nullptr) {}
   ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        // Initialize the slow pointer to the head.
    ListNode* slow = head; 
    
     // Initialize the fast pointer to the head.
    ListNode *fast = head;
        
        while (fast != NULL && fast->next != NULL) {
        // Move slow one step.
           slow = slow->next; 
         // Move fast two steps.
           fast = fast->next->next; 
        }
    
    
     // Return the slow pointer,
     // which is now at the middle node.
        return slow; 
    }
};




