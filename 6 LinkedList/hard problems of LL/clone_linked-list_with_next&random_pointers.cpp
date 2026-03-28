#include<bits/stdc++.h>
using namespace std;

// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};

class Solution {
public:
    
void insertCopyInBetween(Node* head){
    Node* temp = head;
    while(temp != NULL){
        Node* nextElement = temp->next;
        Node* copy = new Node(temp->val);
        copy->next = nextElement;
        temp->next = copy;

        temp = nextElement; // FIX
    }
}

void connectRandomPointers(Node* head){
    Node* temp = head;
    while(temp != NULL){
        Node* copyNode = temp->next;

        if(temp->random){
            copyNode->random = temp->random->next;
        }else{
            copyNode->random = nullptr;
        }
        temp = temp->next->next;
    }
}

Node* getDeepCopyList(Node* head){
    Node* temp = head;
    Node* dummyNode = new Node(-1);
    Node* res = dummyNode;

    while(temp != NULL){
        res->next = temp->next;
        res = res->next;

        temp->next = temp->next->next;
        temp = temp->next;
    }
    return dummyNode->next;
}

Node* copyRandomList(Node* head){
    if(head == NULL) return NULL;

    insertCopyInBetween(head);
    connectRandomPointers(head);
    return getDeepCopyList(head);
}
};


// Time Complexity: O(3N), where N is the number of nodes in the linked list. The algorithm makes three traversals of the linked list, once to create copies and insert them between original nodes, then to set the random pointers of the copied nodes to their appropriate copied nodes and then to separate the copied and original nodes.

// Space Complexity : O(N), where N is the number of nodes in the linked list as the only extra additional space allocated it to create the copied list without creating any other additional data structures.