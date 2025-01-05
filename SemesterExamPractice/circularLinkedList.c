#include <stdio.h>
#include <stdlib.h>

// Structure for a node in the circular linked list
struct Node
{
  int data;          // Data part of the node
  struct Node *next; // Pointer to the next node
};

// Function to create a new node
struct Node *createNode(int value)
{
  struct Node *newNode = (struct Node *)malloc(sizeof(struct Node)); // Allocate memory
  newNode->data = value;
  newNode->next = newNode; // In circular linked list, the next of the new node points to itself initially
  return newNode;
}

// Function to insert a node at the beginning of the circular linked list
void insertAtBeginning(struct Node **head, int value)
{
  struct Node *newNode = createNode(value);

  if (*head == NULL)
  { // If the list is empty
    *head = newNode;
  }
  else
  {
    struct Node *temp = *head;
    // Traverse the list to find the last node
    while (temp->next != *head)
    {
      temp = temp->next;
    }
    temp->next = newNode;  // Last node points to the new node
    newNode->next = *head; // New node points to the head node
    *head = newNode;       // The head now points to the new node
  }
}

// Function to insert a node at the end of the circular linked list
void insertAtEnd(struct Node **head, int value)
{
  struct Node *newNode = createNode(value);

  if (*head == NULL)
  { // If the list is empty
    *head = newNode;
  }
  else
  {
    struct Node *temp = *head;
    // Traverse the list to find the last node
    while (temp->next != *head)
    {
      temp = temp->next;
    }
    temp->next = newNode;  // Last node points to the new node
    newNode->next = *head; // New node points to the head node
  }
}

// Function to delete a node from the circular linked list
void deleteNode(struct Node **head, int value)
{
  if (*head == NULL)
  {
    printf("List is empty.\n");
    return;
  }

  struct Node *temp = *head;
  struct Node *prev = NULL;

  // If the node to be deleted is the head node
  if (temp->data == value)
  {
    if (temp->next == *head)
    { // If there's only one node
      free(temp);
      *head = NULL;
    }
    else
    {
      prev = *head;
      while (prev->next != *head)
      {
        prev = prev->next;
      }
      prev->next = temp->next; // Previous node points to the next of the current node
      *head = temp->next;      // The head is updated to the next node
      free(temp);              // Free the memory of the deleted node
    }
    return;
  }

  // Search for the node to delete
  prev = temp;
  temp = temp->next;
  while (temp != *head && temp->data != value)
  {
    prev = temp;
    temp = temp->next;
  }

  // If the value is not found
  if (temp == *head)
  {
    printf("Node with value %d not found.\n", value);
    return;
  }

  // Delete the node
  prev->next = temp->next; // Unlink the node
  free(temp);              // Free the memory of the node
}

// Function to print the circular linked list
void printList(struct Node *head)
{
  if (head == NULL)
  {
    printf("List is empty.\n");
    return;
  }
  int count = 0;
  struct Node *temp = head;
  do
  {
    printf("%d -> ", temp->data);
    count++;
    temp = temp->next;
  } while (temp != head); // Loop until we reach the head again
  printf("(head) %d \n",count);
}

int main()
{
  struct Node *head = NULL; // Initialize an empty list

  // Inserting nodes at the beginning
  insertAtBeginning(&head, 10);
  insertAtBeginning(&head, 20);
  insertAtBeginning(&head, 30);

  printf("Circular Linked List after inserting at beginning: ");
  printList(head);

  // Inserting nodes at the end
  insertAtEnd(&head, 40);
  insertAtEnd(&head, 50);

  printf("Circular Linked List after inserting at end: ");
  printList(head);

  // Deleting a node with value 20
  deleteNode(&head, 20);
  printf("Circular Linked List after deleting node with value 20: ");
  printList(head);

  // Deleting a node that doesn't exist
  deleteNode(&head, 100);

  return 0;
}
