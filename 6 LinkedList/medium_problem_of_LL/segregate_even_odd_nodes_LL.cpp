#include <bits/stdc++.h>
using namespace std;

// Segregate even and odd nodes in LinkedList :

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution
{
public:
    ListNode *oddEvenList(ListNode *head)
    {
        // edge case
        if (head == NULL || head->next == NULL)
            return head;
        // Initialized
        ListNode *odd = head;
        ListNode *even = head->next;
        ListNode *evenHead = even;

        // Traverse and rearrange
        while (even != NULL && even->next != NULL)
        {
            odd->next = even->next;
            even->next = even->next->next;

            odd = odd->next;
            even = even->next;
        }

        // attach even list after odd list
        odd->next = evenHead;
        return head;
    }
}

// Time Complexity: O(n), We traverse the entire linked list only once to rearrange the nodes. Each node is visited exactly once. No nested traversal or re-traversal occurs. Hence, linear time in terms of the number of nodes n.

// Space Complexity: O(1), We do not use any extra data structures