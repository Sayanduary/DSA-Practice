#include <iostream>

using namespace std;
struct Node
{
  int data;
  Node *next;
};
void printNodes(Node **root)
{
  Node *current = *root;
  while (current != NULL)
  {
    cout << " " << current->data;
    current = current->next;
  }
}
void sortedInsert(Node **root, int data)
{
  Node *newNode, *current = *root;
  newNode = (Node *)malloc(sizeof(Node));
  newNode->data = data;
  newNode->next = NULL;

  // If the list is empty or the new node should be the first node

  if (*root == NULL || (*root)->data >= data)
  {
    newNode->next = *root;
    *root = newNode;
    return;
  }
  else
  {
    while (current->next != NULL && current->next->data < data)
    {

      current = current->next;
    }
    newNode->next = current->next;
    current->next = newNode;
  }
}
int hashFn(int key)
{
  return key % 10;
}
void insertAtHashTable(Node *H[], int key)
{
  int index = hashFn(key);
  sortedInsert(&H[index], key);
}

void printHAshTable(Node *H[], int size)
{
  for (int i = 0; i < 10; i++)
  {
    cout << "H[" << i << "]";
    Node *current = H[i];
    while (current)
    {
      cout << " -> " << current->data;
      current = current->next;
    }
    cout << "- > NULL" << endl;
  }
}
int main()
{
  struct Node *HT[10];
  int i;
  for (i = 0; i < 10; i++)
  {
    HT[i] = NULL;
  }
  insertAtHashTable(HT, 12);
  insertAtHashTable(HT, 6);
  insertAtHashTable(HT, 2);
  insertAtHashTable(HT, 3);
  insertAtHashTable(HT, 42);
  printHAshTable(HT, 10);
  return 0;
}