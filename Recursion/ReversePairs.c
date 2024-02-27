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
 * Function to swap the pairs of a LinkedList.
 * Based recursion moment
 * 
 * @Param:    Node* head, head of LinkedList
 * @Return:   Node* returns new pointer to epic LinkedList
*/
Node* swapPairs(Node* head) {
  Node* epicTemp;
  if (head == NULL || head->next == NULL) {
    return head;
  } else {
    Node* temp = swapPairs(head->next->next);
    epicTemp = head->next;
    head->next = temp;
    epicTemp->next = head;
  }
  return epicTemp;
}

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

  // Swap the pairs in the list recursively
  Node* hehe = swapPairs(head);

  // Print new list
  printList(hehe);

  return 0;
}