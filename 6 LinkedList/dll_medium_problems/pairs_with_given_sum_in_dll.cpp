#include<bits/stdc++.h>
using namespace std;

// it is given that it is sorted :-

// Find all Pairs with given Sum in DLL :-
// concept left and right point at head and tail respectively

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

// Find tail
ListNode* findTail(ListNode* head){
    ListNode* tail = head;
    while(tail->next != NULL) tail = tail->next;
    return tail;
}
vector<pair<int, int>>findpairs(ListNode* head, int k){
    vector<pair<int, int>> ans;
    ListNode* left = head;
    ListNode* right = findTail(head);
    while(left->val < right->val){
        if(left->val + right->val == k){
            ans.push_back({left->val, right->val});
            left = left->next;
            right= right->prev;
        }
        else if(left->val + right->val < k){
            left = left->next;
        }
        else right = right->prev;
    }
    return ans;
}


// Time complexity - O(2N)
// Sc - O(1)
