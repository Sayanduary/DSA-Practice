#include <iostream>
using namespace std;
struct Node
{
  int data;
  Node *right;
  Node *left;
};
struct Node *createNode(int data)
{
  Node *newNode = (Node *)malloc(sizeof(Node));
  newNode->data = data;
  newNode->right = NULL;
  newNode->left = NULL;
  return newNode;
}
void inOrderTraversal(Node *root)
{
  if (root == NULL)
  {
    return;
  }
  inOrderTraversal(root->left);
  cout << " " << root->data;
  inOrderTraversal(root->right);
}

int isProperBinaryTree(Node *root)
{
  if (root == NULL)
  {
    return 1;
  }
  if (root->left == NULL && root->right == NULL)
  {
    return 1;
  }
  if (root->left != NULL && root->right != NULL)
  {
    return isProperBinaryTree(root->left) && isProperBinaryTree(root->right);
  }
  return 0;
}

int main()
{
  struct Node *root = createNode(1);
  root->left = createNode(2);
  root->right = createNode(3);
  root->left->left = createNode(1);
  root->left->right = createNode(4);
  root->right->left = createNode(1);
  root->right->right = createNode(5);
  inOrderTraversal(root);
  if (isProperBinaryTree(root))
  {
    cout << "Yes";
  }
  else
  {
    cout << "No";
  }
  return 0;
}