#include <bits/stdc++.h>
using namespace std;

struct Node
{
  int data;
  struct Node *next;

  Node(int dataP) {
    data = dataP;
    next = NULL;
  }
};

void insertAtHead(Node** head, int data) {
  Node* newNode = new Node(data);
  newNode->next = (*head);
  (*head) = newNode;
}

void traverse(Node* head) {

  while(head != NULL) {
    printf("%d ", head->data);
    head = head->next;
  }
}

void insertAfterPos(Node* head, int pos, int data) {

  int i = 1;
  Node* tmp = NULL;

  while (i<=pos) {
    tmp = head;
    head = head->next;
    ++i;
  }

  Node* newNode = new Node(data);
  newNode->next = tmp->next;
  tmp->next = newNode;

}

void deletePos(Node** head, int pos) {

  int i = 1;
  Node* tmp = (*head);

  if (pos == 1) {
    (*head) = tmp->next;
    return;

  }

  while (i < pos-1 && tmp != NULL) {
    tmp = tmp->next;
    ++i;
  }

  tmp->next = tmp->next->next;

}

void insertAtTail(Node* head, int data) {

  while(head->next != NULL) {
    head = head->next;
  }

  
  Node* newNode = new Node(data);
  newNode->next = NULL;
  head->next = newNode;

}

int main()
{
  struct Node* head = NULL;
  insertAtHead(&head, 5);
  insertAtHead(&head, 6);
  insertAfterPos(head, 1, 4);
  insertAtTail(head, 7);
  insertAtHead(&head, 12);
  insertAtHead(&head, 63);
  insertAfterPos(head, 1, 43);
  insertAtTail(head, 71);
  traverse(head);
  printf("\n");
  deletePos(&head, 1);
  traverse(head);
  return 0;
}