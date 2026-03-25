#include<bits/stdc++.h>
using namespace std;

struct ListNode {
   int val;
   ListNode *next;
   ListNode() : val(0), next(nullptr) {}
   ListNode(int x) : val(x), next(nullptr) {}
   ListNode(int x, ListNode *next) : val(x), next(next) {}
};


// Find the intersection point of Y LinkedList :

ListNode* getIntersectionNode(ListNode* firstHead, ListNode* secondHead){
   if(firstHead == NULL || secondHead == NULL) return NULL;
   ListNode* temp1 = firstHead;
   ListNode* temp2 = secondHead;
   while(temp1 != temp2){
      temp1 = temp1->next;
      temp2= temp2->next;
      if(temp1 == temp2) return temp1;

      if(temp1 == NULL )temp1 = secondHead;
      if(temp2 == NULL)temp2 = firstHead;
   }
   return temp1;
}

// Time Complexity: O(2 × max(length of list1, length of list2)), Uses the same concept of difference of lengths of two lists.

// Space Complexity: O(1), No extra data structure is used.


