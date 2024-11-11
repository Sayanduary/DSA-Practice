#include <iostream>
using namespace std;
struct Node
{
  int data;
  struct Node *next;

} *head = NULL;
void insertAtFirst(struct Node *&head_ref, int data)
{
  Node *newNode = (Node *)malloc(sizeof(Node));
  newNode->data = data;
  newNode->next = head_ref;
  head_ref = newNode;
}
void displayNode(struct Node *head_ref)
{
  Node *temp = head_ref;
  while (temp != NULL)
  {
    cout << temp->data;
    if (temp->next != NULL)
    {
      cout << " -> ";
    }
    temp = temp->next;
  }
  cout << endl;
}
void insertAtLast(Node *&head_ref, int data)
{
  Node *newNode = (Node *)malloc(sizeof(Node));
  newNode->data = data;
  newNode->next = NULL;
  if (head_ref == NULL)
  {
    head_ref = newNode;
    return;
  }
  Node *temp = head_ref;
  while (temp->next != NULL)
  {

    temp = temp->next;
  }
  temp->next = newNode;
}
void insertAtPosition(Node *&head_ref, int index, int data)
{
  // Allocate memory for the new node
  Node *newNode = (Node *)malloc(sizeof(Node));
  newNode->data = data;
  newNode->next = NULL;

  // Case 1: If the list is empty and index is 0
  if (head_ref == NULL && index == 0)
  {
    head_ref = newNode; // Set head to the new node
    return;
  }

  // Case 2: Insert at the beginning (index 0)
  if (index == 0)
  {
    newNode->next = head_ref; // Point the new node to the current head
    head_ref = newNode;       // Update head to the new node
    return;
  }

  // Case 3: Insert at other positions
  Node *curreNode = head_ref;
  int currentIndex = 0;

  // Traverse the list to find the node at (index-1)
  while (curreNode != NULL && currentIndex < index - 1)
  {
    curreNode = curreNode->next;
    currentIndex++;
  }

  // If the currentIndex is less than (index-1), the index is out of bounds
  if (curreNode == NULL)
  {
    cout << "Index out of range." << endl;
    return;
  }

  // Insert the new node after the current node (curreNode)
  newNode->next = curreNode->next; // Make new node's next point to the next node
  curreNode->next = newNode;       // Make the current node's next point to the new node
}
void insertAtSortedList(Node *&head_ref, int data)
{
  Node *newNode = (struct Node *)malloc(sizeof(Node));
  newNode->data = data;
  newNode->next = NULL;
  if (head_ref == NULL)
  {
    head_ref = newNode;
    return;
  }
  if (head_ref->data >= data)
  {
    newNode->data = data;
    newNode->next = head_ref;
    head_ref = newNode;
    return;
  }
  Node *currentNode = head_ref;
  while (currentNode->next != NULL && currentNode->next->data < data)
  {
    currentNode = currentNode->next;
  }
  newNode->next = currentNode->next;
  currentNode->next = newNode;
}
int main()
{
  insertAtSortedList(head, 20);
  insertAtSortedList(head, 10);
  insertAtSortedList(head, 6);
  displayNode(head);
  return 0;
}