#include<bits/stdc++.h>
using namespace std;

// Problem Statement: Given the head of a singly linked list representing a positive integer number. Each node of the linked list represents a digit of the number, with the 1st node containing the leftmost digit of the number and so on. The task is to add one to the value represented by the linked list and return the head of a linked list containing the final value.

struct ListNode {
   int val;
   ListNode *next;
   ListNode() : val(0), next(nullptr) {}
   ListNode(int x) : val(x), next(nullptr) {}
   ListNode(int x, ListNode *next) : val(x), next(next) {}
};

// Input: 4->5->6

// Output: 4->5->7
// Explanation: 456 + 1 = 457
// Input: 9->9->9

// Output: 1->0->0->0
// Explanation: 999 + 1 = 1000


// Add 1 to a number represented by LL :

//Two ways :-  1.iteration (Tc-3N) &&  2. recursive (optimal)



// recursive method

int addHelper(ListNode* temp){
    if(temp == NULL){
        return 1;
    }
    int carry = addHelper(temp->next);
    temp->val += carry;
    if(temp->val <10) return 0;
    temp->val = 0;
    return 1;
}

ListNode* addONe(ListNode* head){
    int carry = addHelper(head);
    if(carry == 1){
        ListNode* newNode = new ListNode(1);
        newNode->next = head;
        head = newNode;
    }
    return head;
}


// Time Complexity: O(n), One pass for addition.

// Space Complexity: O(n), Auxiliary stack space.



// Iterative methods :

ListNode* reverse(ListNode* head){
    ListNode* prev = NULL;
    while(head){
        ListNode* next = head->next;
        head->next = prev;
        prev = head;
        head = next;
    }
    return prev;
}

ListNode* addOne(ListNode* head){
    head = reverse(head);

    ListNode* temp = head;
    int carry = 1;

    while(temp){
        temp->val += carry;
        if(temp->val < 10){
            carry = 0;
            break;
        }
        temp->val = 0;
        carry = 1;

        if(temp->next == NULL && carry == 1){
            temp->next = new ListNode(1);
            carry = 0;
            break;
        }
        temp = temp->next;
    }

    return reverse(head);
}