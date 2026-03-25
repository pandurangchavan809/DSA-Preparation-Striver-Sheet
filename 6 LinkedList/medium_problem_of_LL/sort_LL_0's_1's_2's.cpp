#include <bits/stdc++.h>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};


// Sort a LinkedList of 0's, 1's and 2's :

 
ListNode* sortlist(ListNode* head){
    if(!head || !head->next) return head;

    ListNode* zeroHead = new ListNode(-1);
    ListNode* oneHead = new ListNode(-1);
    ListNode* twoHead = new ListNode(-1);

    ListNode* zero = zeroHead;
    ListNode* one = oneHead;
    ListNode* two = twoHead;
    ListNode* temp = head;


    while(temp){
        if(temp->val==0){
            zero->next=temp;
            zero=zero->next;
        }else if(temp->val==1){
            one->next=temp;
            one = one->next;
        }else{
            two->next=temp;
            two=two->next;
        }
        temp = temp->next;
    }

    zero->next = (oneHead->next)?(oneHead->next):(twoHead->next);
    one->next = twoHead->next;
    two->next = NULL;

    ListNode* newHead = zeroHead->next;

    delete zeroHead;
    delete oneHead;
    delete twoHead;
    
    return newHead;
}



// Time Complexity: O(n), We traverse the entire list once.

// Space Complexity: O(1), Only dummy nodes and pointers are used (constant space).
