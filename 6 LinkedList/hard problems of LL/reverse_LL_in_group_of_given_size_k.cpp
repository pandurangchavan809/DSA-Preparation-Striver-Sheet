#include<bits/stdc++.h>
using namespace std;

struct ListNode {
   int val;
   ListNode *next;
   ListNode() : val(0), next(nullptr) {}
   ListNode(int x) : val(x), next(nullptr) {}
   ListNode(int x, ListNode *next) : val(x), next(next) {}
};

// Input :head -> 1 -> 2 -> 3 -> 4 -> 5, k = 3
// Output :head -> 3 -> 2 -> 1 -> 4 -> 5
// Explanation :The groups 1 -> 2 -> 3 were reversed as 3 -> 2 -> 1.
// Note that 4 -> 5 was not reversed.

// Reverse Nodes in K Group Size of LinkedList :

ListNode* reverseLinkedList(ListNode* head) {
    ListNode* prev = NULL;
    ListNode* curr = head;

    while (curr != NULL) {
        ListNode* nextNode = curr->next; // store next
        curr->next = prev;               // reverse link
        prev = curr;                    // move prev
        curr = nextNode;                // move curr
    }

    return prev; // new head of reversed list
}

ListNode* getKthNode(ListNode* temp, int k){
   k -= 1;
   while(temp != NULL && k>0){
      k--;
      temp = temp->next;
   }
   return temp;
}

ListNode* kReverse(ListNode* head, int k){
   ListNode* temp = head;
   ListNode* prevLast = NULL;
   while(temp != NULL){
      ListNode* kThNode = getKthNode(temp, k);
      if(kThNode == NULL){
         if(prevLast) prevLast->next = temp;
         break;
      }

      ListNode* nextNode = kThNode->next;
      kThNode->next = NULL;
      reverseLinkedList(temp);
      if(temp == head){
         head = kThNode;

      }else{
         prevLast->next = kThNode;
      }

      prevLast = temp;
      temp = nextNode;
   }
   return head;

}













// Time Complexity: O(N),We visit each node exactly once during reversal and during group detection (getKthNode). So the total operations are linear with respect to the number of nodes in the list.

// Space Complexity: O(1),The algorithm uses a constant amount of extra memory for pointers and dummy node. No additional data structures like arrays or stacks are used.