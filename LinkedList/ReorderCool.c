#include <stdio.h>
#include <stdlib.h>

typedef struct ListNode {
  int val;
  struct ListNode* next;
} Node;

/**
 * Reorders a list as specified by leetcode 143.
 * 
 * Return:  the head of the reordered list. 
 * Param:   Node* head the head of the list.
*/
void reorderList(Node* head) {
  // Find the middle
  Node* slow = head->next;  // slow pointer, move one node at a time
  Node* fast = slow->next;  // fast pointer, move two nodes at a time

  while (fast && fast->next) {
    slow = slow->next;
    fast = fast->next->next;
  }

  // Reverse the second half
  Node* second = slow->next;
  Node* prev = slow->next = NULL;
  
  while (second) {
    Node* temp = second->next;
    second->next = prev;
    prev = second;
    second = temp;
  }

  // Merge the two halves
  second = prev;
  Node* first = head->next;

  while (second) {
    Node* temp1 = first->next;
    Node* temp2 = second->next;

    first->next = second;
    second->next = temp1;   // insert in between (merge)
    first = temp1;
    second = temp2;
  }
}

/**
 * Creates a new list node with specified value.
 * 
 * Return:    Node* nNode new node for the list.
 * Param:     int v the value for the node. 
*/
Node* createNode(int v) {
  Node* nNode = (Node*) malloc(sizeof(struct ListNode));
  nNode->val = v;
  nNode->next = NULL;
  return nNode;
}

/**
 * Prints a LinkedList given the head.
 * 
 * Param:   Node* head the head of the list
*/
void printList(Node* head) {
  Node* itr = head->next;
  while(itr != NULL) {
    printf("%d ", itr->val);
    itr = itr->next;
  }
  printf("\n");
}

int main() {
  Node* head = createNode(-1);
  Node* itr = head;

  // Create a LinkedList with some numbers
  for (int n = 1; n <= 4; n++) {
    Node* nNode = createNode(n);
    itr->next = nNode;
    itr = nNode;
  }

  // Print the OG List
  printList(head);
  
  // Reorder the list
  reorderList(head);

  // Print the reordered list
  printList(head);

  return 0;
}