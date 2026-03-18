#include<bits/stdc++.h>
using namespace std;

// tc - O(N) and Sc- O(1)
// delete the node in the linked list 

// class Solution {
// public:
//     void deleteNode(ListNode* node) {
//         node->val = node->next->val;     // copy next node value
//         node->next = node->next->next;   // skip next node
//     }
// };