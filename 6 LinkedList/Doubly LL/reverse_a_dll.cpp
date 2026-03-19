#include<bits/stdc++.h>
using namespace std;

// Reverse a DLL 

// brute force :- use stack to store data as ietrating to list one by one until temp != NULL
// after again ietrate through list and put temp->data = st.top() and pop() it and then continue until temp != NULL
// Tc - O(2n) && Sc - O(n).. as stack use 



// Optimal solution
// Tc - O(n) && Sc - O(1)

Node* reverseDLL(Node* head){
    if(head == NULL || head -> next == NULL){
        return head;
    }
    Node* prev = NULL;
    Node* current = head;
    while(current != NULL){
        prev = current->prev;
        current->prev = current->next;
        current->next = prev;

        current = current->prev;
    }
    return prev->prev;
}