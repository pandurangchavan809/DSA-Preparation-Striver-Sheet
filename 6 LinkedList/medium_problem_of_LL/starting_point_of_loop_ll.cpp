#include<bits/stdc++.h>
using namespace std;

// Find the starting point of the Loop/Cycle in LinkedList 

// Time Complexity: O(N) where N is the number of nodes in the linked list.
// Sc - O(1) constant extra space. No additional data structures are used, only two pointers.



struct ListNode {
   int val;
   ListNode *next;
   ListNode() : val(0), next(nullptr) {}
   ListNode(int x) : val(x), next(nullptr) {}
   ListNode(int x, ListNode *next) : val(x), next(next) {}
};

// as return node (starting node so function must be return type of ListNode)

ListNode* detectCycle(ListNode *head){
    ListNode* slow=head;
    ListNode* fast = head;
    while(fast!=NULL && fast->next != NULL){
        slow=slow->next;
        fast=fast->next->next;
        if(slow==fast){
            slow=head;
            while(slow != fast){
                slow = slow->next;
                fast=fast->next;

            }
            return slow;
        }
    }
    return NULL;
}