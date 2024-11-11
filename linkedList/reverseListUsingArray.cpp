#include <iostream>
using namespace std;
struct Node
{
  int data;
  Node *next;
};
void appendNode(struct Node **head_ref, int newData)
{
  Node *newNode = (Node *)malloc(sizeof(Node));
  Node *last = *head_ref;
  newNode->data = newData;
  newNode->next = NULL;

  if (*head_ref == NULL)
  {
    *head_ref = newNode;
    return;
  }
  while (last->next != NULL)
  {
    last = last->next;
  }
  last->next = newNode;
}
void reverseList(Node **head_ref)
{
  if (*head_ref == NULL)
  {
    return;
  }
  Node *currentNode = *head_ref;
  int count = 0;
  while (currentNode != NULL)
  {
    count++;
    currentNode = currentNode->next;
  }
  int arr[count];
  currentNode = *head_ref;
  for (int i = 0; i < count; i++)
  {
    arr[i] = currentNode->data;
    currentNode = currentNode->next;
  }
  currentNode = *head_ref;
  for (int i = count - 1; i >= 0; i--)
  {
    currentNode->data = arr[i];
    currentNode = currentNode->next;
  }
}
void printList(struct Node *node)
{
  while (node != NULL)
  {
    printf("%d -> ", node->data);
    node = node->next;
  }
  printf("NULL\n");
}


int main()
{
  struct Node *head = NULL;

  // Example linked list creation
  appendNode(&head, 1);
  appendNode(&head, 2);
  appendNode(&head, 3);
  appendNode(&head, 4);

  printf("Original List:\n");
  printList(head);

  reverseList(&head);

  printf("Reversed List:\n");
  printList(head);

  return 0;
  return 0;
}