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

int main()
{
  struct Node* head = NULL;
  struct Node* second = NULL;
  struct Node* third = NULL;

  head = new Node(5);
  second = new Node(6);
  third = new Node(7);

  head->next = second;
  second->next = third;
  third->next = NULL;

  while(head != NULL) {
    printf("%d ", head->data);
    head = head->next;
  }

  return 0;
}