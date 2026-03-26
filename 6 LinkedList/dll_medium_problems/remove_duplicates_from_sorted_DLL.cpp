#include<bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode* prev;   // required for DLL

    ListNode(int x) {
        val = x;
        next = NULL;
        prev = NULL;
    }
};


// Remove duplicates from sorted DLL :
// Dll is sorted so duplicates maintained continuity

ListNode* removeDuplicates(ListNode* head){
    ListNode* temp = head;
    while(temp != NULL && temp->next != NULL){
        ListNode* nextNode = temp->next;
        while(nextNode != NULL && nextNode->val == temp->val){
            ListNode* duplicates = nextNode;
            nextNode = nextNode->next;
            free(duplicates);
        }
        temp->next = nextNode;
        if(nextNode != NULL) nextNode->prev = temp;

        temp = temp->next;
    }
    return head;
}