#include<bits/stdc++.h>
using namespace std;

struct ListNode {
   int val;
   ListNode *next;
   ListNode() : val(0), next(nullptr) {}
   ListNode(int x) : val(x), next(nullptr) {}
   ListNode(int x, ListNode *next) : val(x), next(next) {}
};


// Check if a LinkedList is Palindrome or Not  :

// Brute force:- take an stack put all values of list by tranversing using temp=head to last then again start transver and compare with stack top values if match pop and check for next one until stack if empty....if palimdrome all values equally matches

// Optimal Solution :


ListNode* reverseLinkedList(ListNode* head){
    if(head == NULL || head->next == NULL) return head;
    ListNode* newHead = reverseLinkedList(head->next);
    ListNode* front = head->next;
    front->next = head;
    head->next=NULL;
    return newHead;
}



bool isPalindrome(ListNode* head){
    if(head==NULL || head->next == NULL)return true;
    ListNode* slow = head;
    ListNode* fast = head;

    while(fast -> next != NULL && fast->next->next != NULL){
        slow=slow->next;
        fast=fast->next->next;
    }

    ListNode* newHead = reverseLinkedList(slow->next);
    ListNode* first = head;
    ListNode* second = newHead;
    while(second != NULL){
        if(first->val != second->val){
            reverseLinkedList(newHead);
            return false;
        }
        first = first->next;
        second = second->next;
    }
    reverseLinkedList(newHead);
    return true;
}

// Time Complexity: O(N), we traverse the list twice, once to reverse half of it and once to compare, each taking O(N/2), which simplifies to O(N).

// Space Complexity: O(1), no extra space is used apart from a few pointers; operations are done in-place.

