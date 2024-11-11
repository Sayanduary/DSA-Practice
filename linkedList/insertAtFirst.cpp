#include <iostream>
#include <limits.h>
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

bool isSorted(Node *&head_ref)
{
  if (!head_ref || !head_ref->next)
  {
    // If the list is empty or has only one node, it's considered sorted.
    return true;
  }

  Node *currenetNode = head_ref;
  while (currenetNode->next != NULL)
  {
    if (currenetNode->data > currenetNode->next->data)
    {
      return false;
    }

    currenetNode = currenetNode->next;
  }
  return true;
}
void deleteNode(Node *&head_ref, int index)
{
  // If the list is empty
  if (head_ref == NULL)
  {
    cout << "Nothing to Delete" << endl;
    return;
  }

  // Case 1: Deleting the head node (index 0)
  if (index == 0)
  {
    Node *tempNode = head_ref; // Store the current head
    head_ref = tempNode->next; // Move head to the next node
    delete tempNode;           // Delete the old head
    return;
  }

  // Case 2: Deleting node at any other index
  Node *tempNode = head_ref;
  int currentIndex = 0;

  // Traverse the list to find the node just before the one to delete
  while (tempNode != NULL && currentIndex < index - 1)
  {
    tempNode = tempNode->next;
    currentIndex++;
  }

  // If we reach the end of the list or the next node is NULL, index is out of range
  if (tempNode == NULL || tempNode->next == NULL)
  {
    cout << "Out of Bounds" << endl;
    return;
  }

  // Node to be deleted is tempNode->next
  Node *nodeToDelete = tempNode->next;
  tempNode->next = tempNode->next->next; // Skip the nodeToDelete
  delete nodeToDelete;                   // Free the memory of the deleted node
}
void duplicateNodeData(Node *head_ref)
{
  if (!head_ref)
  {
    return;
  }
  Node *currentNode = head_ref;

  while (currentNode != NULL && currentNode->next != NULL)
  {
    if (currentNode->data == currentNode->next->data)
    {
      Node *duplicateNode = currentNode->next;
      currentNode->next = duplicateNode->next;
      delete duplicateNode;
    }
    else
    {
      currentNode = currentNode->next;
    }
  }
}
void reverseList(Node *&head_ref)
{
  Node *prev = NULL;
  Node *currentNode = head_ref;
  Node *next = NULL;

  while (currentNode != NULL)
  {
    next = currentNode->next;
    currentNode->next = prev;
    prev = currentNode;
    currentNode = next;
  }
  head_ref = prev;
}
int main()
{
  insertAtSortedList(head, 20);
  insertAtSortedList(head, 10);
  insertAtFirst(head, 10);
  insertAtSortedList(head, 6);
  insertAtSortedList(head, 6);

  if (isSorted(head))
  {
    cout << "List is Sorted " << endl;
  }
  else
  {
    cout << "List is not sorted" << endl;
  }

  reverseList(head);
  displayNode(head);

  return 0;
}