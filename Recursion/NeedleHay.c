#include <stdio.h>
#include <stdlib.h>

// LinkedList and Recursion

typedef struct ListNode {
  int val;
  struct ListNode* next;
} Node;

/**
 * Recursive function to search a linkedlist for value
 * Needle in the haystack
 * 
 * Param: Node* head, haystack linkedlist
 * Param: int n, needle that we want to find
*/
int findNeedle(Node *head, int n) {
  if (!head) {
    return 0;   // The end of the list has been reached, not true.
  } else if (head->val == n) {
    return 1;   // The current node has the same value, true.
  } else {
    return findNeedle(head->next, n);   // Go to next node.
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

  // Print the reordered list
  int toFind = 4;
  printf("Does element %d exist in the list?: %d\n", toFind, findNeedle(head->next, toFind));

  return 0;
}