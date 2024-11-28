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
    left = right = NULL;
  }
};
Node *createNode(int data)
{
  return new Node(data);
}
Node *searchBST(Node *root, int key)
{
  if (root == NULL)
  {
    return NULL;
  }
  if (root->data == key)
  {
    return root;
  }
  else if (key > root->data)
  {
    return searchBST(root->right, key);
  }
  else
  {
    return searchBST(root->left, key);
  }
}
Node *searchBSTiter(Node *root, int key)
{
  if (root == NULL)
  {
    return NULL;
  }
  while (root != NULL)
  {
    if (key == root->data)
    {
      return root;
    }
    else if (key < root->data)
    {
      root = root->left;
    }
    else
    {
      root = root->right;
    }
  }
  return NULL;
}

void insertNode(Node *root, int key)
{
  Node *prevNode = NULL;
  Node *currentNode = root;
  while (currentNode != NULL)
  {
    prevNode = currentNode;
    if (currentNode->data == key)
    {
      return;
    }
    else if (key < currentNode->data)
    {
      currentNode = currentNode->left;
    }
    else
    {
      currentNode = currentNode->right;
    }
  }
  Node *newNode = createNode(key);
  if (prevNode == NULL)
  {
    root = newNode;
  }
  else if (key < prevNode->data)
  {
    prevNode->left = newNode;
  }
  else
  {
    prevNode->right = newNode;
  }
}
void inorderTraversal(Node *root)
{
  if (root != NULL)
  {
    inorderTraversal(root->left);
    cout << root->data << " ";
    inorderTraversal(root->right);
  }
}
int main()
{
  Node *rootNode = createNode(50);
  Node *p1 = createNode(60);
  Node *p2 = createNode(40);
  Node *p3 = createNode(45);
  Node *p4 = createNode(20);
  Node *p5 = createNode(55);
  Node *p6 = createNode(70);

  rootNode->left = p2;
  rootNode->right = p1;
  p2->left = p4;
  p2->right = p3;
  p1->left = p5;
  p1->right = p6;

  Node *result = searchBST(rootNode, 50);
  Node *resultIter = searchBSTiter(rootNode, 50);
  if (resultIter)
  {
    cout << "Found " << resultIter->data << endl;
  }
  else
  {
    cout << "Not Found " << endl;
  }
  insertNode(rootNode, 71);
  inorderTraversal(rootNode);
  return 0;
}