#include<bits/stdc++.h>
using namespace std;

// Recursive Reverse a LinkedList :

struct ListNode {
   int val;
   ListNode *next;
   ListNode() : val(0), next(nullptr) {}
   ListNode(int x) : val(x), next(nullptr) {}
   ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if (!head || !head->next) return head;

        ListNode* newHead = reverseList(head->next);
        head->next->next = head;
        head->next = nullptr;

        return newHead;
    }
};


// Time Complexity: O(n).....Each node is visited exactly once during the recursive call, and we do constant-time work for each node (like flipping pointers).

// Space Complexity: O(n).....The recursion stack goes up to n levels deep (one for each node), which uses extra space on the call stack.