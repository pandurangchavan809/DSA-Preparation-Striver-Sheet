#include<bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode* prev;   

    ListNode(int x) {
        val = x;
        next = NULL;
        prev = NULL;
    }
};


// Delete all occurrences of a Key in DLL :

ListNode*deleteAllOccurances(ListNode* head, int k){
    ListNode* temp = head;
    while(temp != NULL){
        if(temp->val == k){
            // if this is the head of ll
            // then post deletion the head will updated
            if(temp == head){
                head = temp->next;
            }

            ListNode* nextNode = temp->next;
            ListNode* prevNode = temp->prev;
            if(nextNode != NULL) nextNode->prev =prevNode;
            if(prevNode != NULL) prevNode->next = nextNode;

            free(temp);
            temp = nextNode;
        }else{
            temp = temp->next;
        }
        return head;
    }
}


// Time complexity :- O(N)  & Sc - O(1)