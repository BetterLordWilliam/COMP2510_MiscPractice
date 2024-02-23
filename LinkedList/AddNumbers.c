#include <stdio.h>
#include <stdlib.h>

typedef struct ListNode {
  int val;
  struct ListNode* next;
} Node;

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
 * Function to add two linkedlist numbers together.
 * Will return the result of the addition as a pointer to the result linked
 * 
 * Param:   Node** numberOne first number linkedlist
 * Param:   Node** numberTwo second number linkedlist
 * Return:  Node* new linkedlist result number
*/
Node* add(Node** numberOne, Node** numberTwo) {
  int carry = 0;
  Node* oHead = (*numberOne)->next;
  Node* tHead = (*numberTwo)->next;

  // Result setup
  Node* nHead = createNode(-1);
  Node* prev = nHead;   // Previous stage (so we can link)

  // While either of the nodes are valid
  while (oHead || tHead) {
    int p1, p2;
    
    if (oHead == NULL)
      p1 = 0;
    else {
      p1 = oHead->val;
      oHead = oHead->next;
    }
    
    if (tHead == NULL)
      p2 = 0;
    else {
      p2 = tHead->val;
      tHead = tHead->next;
    }
  
    int rVal = (p1 + p2 + carry) % 10;          // Value of new node
    carry = (p1 + p2 + carry >= 10) ? 1 : 0;    // Determine the value of carry
    Node* nNode = createNode(rVal);
    prev->next = nNode;
    prev = nNode;
  }

  return nHead;
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
  Node* numberOne = createNode(-1);
  Node* numberTwo = createNode(-1);

  // number one
  numberOne->next = createNode(2);
  numberOne->next->next = createNode(4);
  numberOne->next->next->next = createNode(3);
  
  // number two
  numberTwo->next = createNode(5);
  numberTwo->next->next = createNode(6);
  numberTwo->next->next->next = createNode(4);
  numberTwo->next->next->next->next = createNode(5);
  numberTwo->next->next->next->next->next = createNode(1);
  

  // Print the initial numbers
  printList(numberOne);
  printList(numberTwo);

  // Perform the addition
  Node* result = add(&numberOne, &numberTwo);

  // Show result
  printList(result);

  return 0;
}