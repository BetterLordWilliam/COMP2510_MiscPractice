#include <stdio.h>
#include <stdlib.h>

// Epic Linked List
typedef struct ListNode {
  int val;
  struct ListNode* next;
} Node;

// LinkedList Methods
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
  Node* itr = head;
  while(itr != NULL) {
    printf("%d ", itr->val);
    itr = itr->next;
  }
  printf("\n");
}

/**
 * Method to reverse the contents of a LinkedList
 * Done recursively
 * 
 * Param:     Node* head, the head of the node
 * Return:    Node*, the new head of the reversed LinkedList
*/
Node* rList(Node* head) {
  if (head == NULL || head->next == NULL) {
    return head;
  } else {
    Node* temp = rList(head->next);   // Reverse the rest of the list
    head->next->next = head;          // The next nodes next will be the current node
    head->next = NULL;                // Next of head becomes NULL, make the new end of list
    return temp;
  }
}

// CHUFFED CHUFFED CHUFFED, SOLUTION WORKED!

int main() {
  Node* head = createNode(1);
  Node* itr = head;

  // Create a LinkedList with some numbers
  for (int n = 2; n <= 4; n++) {
    Node* nNode = createNode(n);
    itr->next = nNode;
    itr = nNode;
  }

  // Print the OG List
  printList(head);

  // Call Reverse list method
  Node* nHead = rList(head);

  // Print Reversed List
  printList(nHead);

  return 0;
}