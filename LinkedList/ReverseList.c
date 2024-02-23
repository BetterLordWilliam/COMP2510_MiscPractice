#include <stdio.h>
#include <stdlib.h>

typedef struct ListNode {
  int val;
  struct ListNode* next;
} Node;

/**
 * Reverses a list given the head of the list.
 * 
 * Param:   Node* head the head of the list we are going to reverse
*/
void reverseList(Node** head) {
  Node* itr = (*head)->next;
  Node* prev = NULL;

  // T --> O(N) && M --> O(1)
  while (itr != NULL) {
    Node* temp = itr->next;   // Save the next list node
    itr->next = prev;   // make this node point to the previous
    prev = itr;   // Save the previous
    itr = temp;   // go to next (saved earlier)
  }

  (*head)->next = prev;
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
  
  // Reverse the List
  reverseList(&head);

  // Print the reordered list
  printList(head);

  return 0;
}