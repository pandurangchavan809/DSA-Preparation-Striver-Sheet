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

// Delete the middle node of the LinkedList :

ListNode *deleteMiddle(ListNode *head){
    if (head == NULL || head->next == NULL) return NULL;

    ListNode *slow = head;
    ListNode *fast = head;
    fast = head->next->next;

    while (fast != NULL && fast->next != NULL){
        slow = slow->next;
        fast = fast->next->next;
    }

    slow->next = slow->next->next;
    return head;
}

// Time Complexity: O(N/2), we traverse the entire linked list using slow and fast pointers, effectively covering about half the list before reaching the midpoint.

// Space Complexity: O(1) , we have fixed number of pointers and variables to delete the Kth node.