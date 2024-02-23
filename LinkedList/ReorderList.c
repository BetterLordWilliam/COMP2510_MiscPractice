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
Node* reorderList(Node* head) {
  Node* oFirst = head->next;
  Node* oSecond;
  Node* oLast;
  Node* oSecondLast;
  Node* temp;
  int size = 0;

  while(oFirst != NULL) {
    // Get the last element
    if (size == 1)
      oSecond = oFirst;     // Save the second element
    if (oFirst->next == NULL) {
      oLast = oFirst;       // Save the last element
      oSecondLast = temp;   // Save the second to last (new last)
    }
    // save the previous
    temp = oFirst;
    oFirst = oFirst->next;
    size++;
  }

  // Reorder the list
  head->next->next = oLast;   // Set the second value to be the old last one.
  oLast->next = oSecond;      // set the old last value to be the first.
  oSecondLast->next = NULL;   // Set the old second to last be NULL (make it the end).

  return head;
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
  for (int n = 1; n <= 5; n++) {
    Node* nNode = createNode(n);
    itr->next = nNode;
    itr = nNode;
  }

  // Print the OG List
  printList(head);

  Node* reorderedList = reorderList(head);

  // Print the reordered list
  printList(reorderedList);

  return 0;
}