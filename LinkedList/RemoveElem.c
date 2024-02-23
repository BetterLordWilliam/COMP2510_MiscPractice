#include <stdio.h>
#include <stdlib.h>

typedef struct ListNode {
  int val;
  struct ListNode* next;
} Node;

/**
 * Function to remove all elements who's value matches parameter.
 * 
 * Param:   Node** head the head of the list
 * Param:   int v the value we want to exterminate
*/
void removeV(Node** head, int v) {
  Node* itr = (*head)->next;
  Node* prev = (*head);

  while (itr) {
    // If the values match
    if (itr->val == v) {
      Node* temp = itr->next;   // Save the next list node
      free(itr);                // Destroy the cringe, bad value memory.
      itr = temp;               // Set the itr to be equal to the next node
      prev->next = itr;         // Set the next of the previous node to be the new current node
    } else {  
      prev = itr;               // Update previous to be the current
      itr = itr->next;          // Update the current to be the next
    }
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

  // Manually create cringe list 
  head->next = createNode(1);
  head->next->next = createNode(2); 
  head->next->next->next = createNode(6);
  head->next->next->next->next = createNode(3);
  head->next->next->next->next->next = createNode(4);
  head->next->next->next->next->next->next = createNode(5);
  head->next->next->next->next->next->next->next = createNode(6);

  // Print the OG List
  printList(head);

  // Print the reordered list
  removeV(&head, 6);

  printList(head);

  return 0;
}