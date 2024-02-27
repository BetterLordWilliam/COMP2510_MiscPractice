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
 * Function to retrieve the last node of a LinkedList.
 * Also says that the second to last is now the last...
 * 
 * Param:   Node* head, start of the list
 * Return:  Node*, basically the end of the list
*/
Node* getLastLol(Node** head) {
    Node* t = *head;
    Node* prev = NULL;
    while (t->next != NULL) {
        prev = t;
        t = t->next;
    }
    prev->next = NULL;
    return t;
}

/**
 * Function to reorder a linkedlist recursively
 * 
 * Param:   Node* head so basically the starts
*/
void reorderList(Node* head) {
    if (head->next == NULL || head->next->next == NULL) {
        return;
    } else {
        Node* temp = head->next;
        Node* nEnd = getLastLol(&head);
        nEnd->next = temp;
        reorderList(temp);
        head->next = nEnd;
    }
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

  // Is this question fucked...
  reorderList(head);

  // Print the new epic reordered list
  printList(head);

  return 0;
}