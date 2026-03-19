#include<bits/stdc++.h>
using namespace std;

// Define a Node class for doubly linked list
class Node {
public:
    int data;   // Data stored in the node
    Node* next; // Pointer to the next node in the list (forward direction)
    Node* back; // Pointer to the previous node in the list (backward direction)

    // Constructor for a Node with both data, next, and back references
    Node(int data1, Node* next1, Node* back1) {
        data = data1;
        next = next1;
        back = back1;
    }

    // Constructor for a Node with only data, no next or back references (end of the list)
    Node(int data1) {
        data = data1;
        next = nullptr;
        back = nullptr;
    }
};


Node* insertBeforeHead(Node* head,int val){
    Node* newHead = new Node(val, head, nullptr);
    head->back = newHead;

    return newHead;
}


Node* insertBeforeTail(Node* head, int val){
    if(head->next == NULL){
        return insertBeforeHead(head, val);
    }
    //find the tail by moving from head to last node
    Node* tail = head;
    while(tail->next != NULL){
        tail = tail->next;
    }
    // insert before the tail of the linked list
    Node* prev = tail->back;
    Node* newNode = new Node(val, tail, prev);
    prev->next = newNode;
    tail->back = newNode;
    return head;
}

// insert before the kth element of the linked list

Node* insertBeforeKthElement(Node* head, int k, int val){
    if(k==1){
        return insertBeforeHead(head, val);
    }
    Node* temp = head;
    int cnt = 0;
    while(temp != NULL){
        cnt++;
        if(cnt == k) break;
        temp = temp-> next;
    }

    Node* prev = temp->back;
    Node* newNode = new Node(val,temp, prev);
    prev->next = newNode;
    temp->back = newNode;
    return head;
}


//  insert before the given node...it is guaranty that not insert before head as head change and the question never not asking that or provide head changes or not.

void insertBeforeNode(Node* node, int val){
    Node* prev = node->back;
    Node* newNode= new Node(val, node, prev);
    prev->next = newNode;
    node->back = newNode;
}


