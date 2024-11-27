#include <iostream>
using namespace std;
struct Node
{
  int data;
  Node *left;
  Node *right;
};
void preOrder(Node *root)
{
  if (root != NULL)
  {
    cout << root->data;
    preOrder(root->left);
    preOrder(root->right);
  }
}
Node *createNode(int data)
{
  Node *rootNode = (Node *)malloc(sizeof(Node));
  rootNode->data = data;
  rootNode->left = NULL;
  rootNode->right = NULL;
  return rootNode;
}
int main()
{
  struct Node *rootNode = createNode(4);
  Node *p = createNode(1);
  Node *p1 = createNode(5);
  Node *p2 = createNode(2);
  Node *p3 = createNode(6);
  rootNode->left = p;
  rootNode->right = p3;
  p->left = p1;
  p->right = p2;
  preOrder(rootNode);
  return 0;
}