#include<bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode *child;

    ListNode(int x) {
        val = x;
        next = NULL;
        child = NULL;
    }
};

// Flattening a LinkedList :

ListNode* merge(ListNode* list1, ListNode* list2){
    ListNode* dummyNode = new ListNode(-1);
    ListNode* res = dummyNode;

    while(list1 != NULL && list2 != NULL){
        if(list1->val < list2->val){
            res->child = list1;
            res = list1;
            list1 = list1->child;
        }
        else{
            res->child = list2;
            res = list2;
            list2 = list2->child;
        }
        res->next = NULL; // important
    }

    if(list1) res->child = list1;
    else res->child = list2;

    return dummyNode->child;
}


// Time Complexity: O(N + M) → we traverse both lists once

// Space Complexity: O(1) → no extra space, only pointers used