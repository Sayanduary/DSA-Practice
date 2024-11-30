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
Node *inOrderPredecessor(Node *root)
{
  root = root->left;
  while (root->right != NULL)
  {
    root = root->right;
  }
  return root;
}
struct Node *deleteNode(Node *root, int val)
{
  struct Node *iPre;
  if (root == NULL)
  {
    return NULL;
  }
  if (root->left == NULL && root->right == NULL)
  {
    free(root);
    return NULL;
  }
  // search for the node to deleted
  if (val < root->data)
  {
    root->left = deleteNode(root->left, val);
  }
  else if (val > root->data)
  {
    root->right = deleteNode(root->right, val);
  }
  // Deletion strategy when the node is found
  else
  {
    if (root->left != NULL)
    {
      iPre = inOrderPredecessor(root);
      root->data = iPre->data;
      root->left = deleteNode(root->left, iPre->data);
    }
    else if (root->right != NULL)
    {
     iPre = inOrderPredecessor(root);
      root->data = iPre->data;
      root->right = deleteNode(root->right, iPre->data);
    }
  }
  return root;
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
  deleteNode(rootNode, 60);
  inorderTraversal(rootNode);
  
  return 0;
}