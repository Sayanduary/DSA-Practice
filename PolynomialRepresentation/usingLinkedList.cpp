#include <iostream>
using namespace std;
struct Node
{
  float coefficient;
  int exponent;
  Node *next;
};
Node *createNode(float coeff, int exp)
{
  Node *newNode = (Node *)malloc(sizeof(Node));
  newNode->coefficient = coeff;
  newNode->exponent = exp;
  newNode->next = NULL;
  return newNode;
}

void insertAtBegin(Node **head, float coeff, int exp)
{
  Node *newNode = createNode(coeff, exp);
  newNode->next = *head;
  *head = newNode;
}

void displayPloynomial(Node *head)
{
  Node *currentNode = head;
  while (currentNode != NULL)
  {
    cout << currentNode->coefficient << "x^" << currentNode->exponent;
    currentNode = currentNode->next;
    if (currentNode != NULL)
    {
      cout << " + ";
    }
  }
  cout << endl;
}

int main()
{
  Node *head = NULL;
  insertAtBegin(&head, 5, 3);
  insertAtBegin(&head, 2, 2);
  insertAtBegin(&head, 1, 1);
  insertAtBegin(&head, 9, 0);
  displayPloynomial(head);
  return 0;
}