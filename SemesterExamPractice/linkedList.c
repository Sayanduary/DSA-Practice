#include <stdio.h>
#include <stdlib.h>

struct Node
{
  int data;
  struct Node *next;
};

struct Node *createNode(int val)
{
  struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
  newNode->data = val;
  newNode->next = NULL;
  return newNode;
}

void insertAtBegining(struct Node **head, int val)
{
  struct Node *newNode = createNode(val);
  newNode->next = *head;
  *head = newNode;
}

void insertAtEnd(struct Node **head, int val)
{
  struct Node *newNode = createNode(val);
  if (*head == NULL)
  {
    *head = newNode;
    return;
  }
  struct Node *temp = *head;
  while (temp->next != NULL)
  {
    temp = temp->next;
  }
  temp->next = newNode;
}

void deleteNode(struct Node **head, int val)
{
  struct Node *temp = *head;
  struct Node *prev = NULL;

  if (temp != NULL && temp->data == val)
  {
    *head = temp->next;
    free(temp);
    return;
  }
  while (temp != NULL && temp->data != val)
  {
    prev = temp;
    temp = temp->next;
  }
  if (temp == NULL)
  {
    printf("Value not Found \n");
    return;
  }
  prev->next = temp->next;
  free(temp);
}

void displayList(struct Node *head)
{
  struct Node *temp = head;
  while (temp != NULL)
  {
    printf("%d", temp->data);
    if (temp->next != NULL)
    {
      printf(" -> ");
    }
    temp = temp->next;
  }
  printf("\n");
}

int count(struct Node *head)
{
  if (head == NULL)
  {
    return 0;
  }
  return 1 + count(head->next);
}

void freeList(struct Node **head)
{
  struct Node *temp = *head;
  while (temp != NULL)
  {
    struct Node *next = temp->next;
    free(temp);
    temp = next;
  }
  *head = NULL;
}

int add(struct Node **head)
{
  int sum = 0;
  struct Node *temp = *head;
  while (temp != NULL)
  {
    sum += temp->data;
    temp = temp->next;
  }
  return sum;
}

int max(struct Node **head)
{
  int max = INT_MIN;
  struct Node *temp = *head;
  while (temp != NULL)
  {
    if (temp->data > max)
    {
      max = temp->data;
    }
    temp = temp->next;
  }
  return max;
}

void deleteDuplicates(struct Node **head)
{
  if (*head == NULL || (*head)->next == NULL)
  {
    return; // No duplicates possible in an empty or single-node list
  }

  struct Node *temp = *head;

  while (temp != NULL && temp->next != NULL)
  {
    if (temp->data == temp->next->data)
    {
      struct Node *duplicate = temp->next; // Pointer to the duplicate node
      temp->next = temp->next->next;       // Skip the duplicate node
      free(duplicate);                     // Free memory of the duplicate
    }
    else
    {
      temp = temp->next; // Move to the next node
    }
  }
}

int main()
{
  struct Node *head = NULL;

  insertAtBegining(&head, 10);
  insertAtBegining(&head, 20);
  insertAtBegining(&head, 20);
  insertAtBegining(&head, 40);
  insertAtBegining(&head, 1000);
  insertAtBegining(&head, 1000);
  insertAtBegining(&head, 1000);
  insertAtBegining(&head, 1000);
  insertAtBegining(&head, 330);

  printf("Count of nodes: %d\n", count(head));

  printf("Sum of Nodes: %d\n", add(&head));
  printf("Maximum Element: %d\n", max(&head));
  deleteDuplicates(&head);
  displayList(head);
  freeList(&head);
  return 0;
}
