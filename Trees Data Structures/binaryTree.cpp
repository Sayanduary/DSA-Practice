#include <iostream>
using namespace std;
struct Node
{
  int data;
  Node *left;
  Node *right;

  Node(int val)
  {
    data = val;
    left = right = nullptr;
  }
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

void postOdrder(Node *root)
{
  if (root != NULL)
  {
    postOdrder(root->left);
    postOdrder(root->right);
    cout << root->data;
  }
}
void inOrder(Node *root)
{
  if (root != NULL)
  {
    inOrder(root->left);
    cout << root->data;
    inOrder(root->right);
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
int isBST(Node *root)
{
  static Node *prevNode = NULL;
  if (root != NULL)
  {
    if (!isBST(root->left))
    {
      return 0;
    }
    if (prevNode != NULL && root->data <= prevNode->data)
    {
      return 0;
    }
    prevNode = root;
    return isBST(root->right);
  }
  else
  {
    return 1;
  }
}
int main()
{
  Node *rootNode = createNode(9);
  Node *p = createNode(4);
  Node *p1 = createNode(2);
  Node *p2 = createNode(7);
  Node *p3 = createNode(5);
  Node *p4 = createNode(8);
  Node *p5 = createNode(11);
  Node *p6 = createNode(15);
  Node *p7 = createNode(14);
  rootNode->left = p;
  rootNode->right = p5;
  p->left = p1;
  p->right = p2;
  p2->left = p3;
  p2->right = p4;
  p5->right = p6;
  p6->left = p7;
  // preOrder(rootNode);
  // cout << endl;
  // postOdrder(rootNode);
  // cout << endl;
  // inOrder(rootNode);

  cout << (isBST(rootNode));

  return 0;
}