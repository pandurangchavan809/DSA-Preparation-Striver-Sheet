#include<bits/stdc++.h>
using namespace std;

// Remove Nth Node from the end of the LinkedList

struct ListNode {
   int val;
   ListNode *next;
   ListNode() : val(0), next(nullptr) {}
   ListNode(int x) : val(x), next(nullptr) {}
   ListNode(int x, ListNode *next) : val(x), next(next) {}
};



ListNode* removeKthNode(ListNode* head, int k) {
    ListNode* fast = head;
    ListNode* slow = head;

    for (int i = 0; i < k; i++) {
        if (fast == NULL) return head; // safety
        fast = fast->next;
    }

    // If deleting head
    if (fast == NULL) {
        ListNode* temp = head;
        head = head->next;
        delete temp;
        return head;
    }

    while (fast->next != NULL) {
        fast = fast->next;
        slow = slow->next;
    }

    ListNode* delNode = slow->next;
    slow->next = slow->next->next;
    delete delNode;

    return head;
}


// Time Complexity: O(N), since the fast pointer will traverse the entire linked list, where N is the length of the linked list.

// Space Complexity: O(1), constant additional space is used to check unique elements.