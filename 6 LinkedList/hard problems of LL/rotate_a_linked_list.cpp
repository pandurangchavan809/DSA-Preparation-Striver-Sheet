#include<bits/stdc++.h>
using namespace std;

struct ListNode {
   int val;
   ListNode *next;
   ListNode() : val(0), next(nullptr) {}
   ListNode(int x) : val(x), next(nullptr) {}
   ListNode(int x, ListNode *next) : val(x), next(next) {}
};


// Rotate a LinkedList :

ListNode* findNthNode(ListNode* temp, int k){
    int cnt = 1;
    while(temp != NULL){
        if(cnt == k) return temp;
        cnt++;
        temp = temp->next;
    }
    return temp;
}

ListNode* rotate(ListNode* head, int k){
    if(head == NULL || k==0) return head;
    ListNode* tail = head;
    int len = 1;
    while(tail->next != NULL){
        tail = tail->next;
        len += 1;
    }

    if(k % len == 0) return head;
    k= k%len;

    //attach the tail to the head
    tail->next = head;
    ListNode* newLastNode = findNthNode(head, len - k);

    head = newLastNode->next;
    newLastNode->next = NULL;

    return head;
}


// Time Complexity: O(N), We perform a single traversal to calculate the length, another to find the new tail, and one for final breaking all linear operations....O(2N) near about.

// Space Complexity: O(1),No extra space is used; we just adjust pointers in place.