/* Linked Reepresentaion of Binary Tree;*/

#include <iostream>
using namespace std;

struct Node
{
  int data; /* Root Node */
  Node *left;
  Node *right;
};
void inorderTraversal(Node *root)
{
  if (root != NULL)
  {
    inorderTraversal(root->left);  // Traverse left subtree
    cout << root->data << " ";     // Visit root node
    inorderTraversal(root->right); // Traverse right subtree
  }
}
struct Node *createNode(int data)
{
  struct Node *rootNode;
  rootNode = (Node *)malloc(sizeof(Node));
  rootNode->data = data;
  rootNode->left = NULL;
  rootNode->right = NULL;
  return rootNode;
}

int main()
{

  /*

  p = (Node *)malloc(sizeof(Node));
  p->data = 2;
  p->left = NULL;
  p->right = NULL;

  // constracting the second node

  struct Node *p1;
  p1 = (Node *)malloc(sizeof(Node));
  p1->data = 3;
  p1->left = NULL;
  p1->right = NULL;

  // constracting the third node

  struct Node *p2;
  p2->data = 4;
  p2 = (Node *)malloc(sizeof(Node));
  p2->left = NULL;
  p2->right = NULL;

  // linking the root node with the left and right child



  */

  // constracting the root node using function

  struct Node *p = createNode(2);
  Node *p1 = createNode(3);
  Node *p2 = createNode(4);

  p->left = p1;
  p->right = p2;
  inorderTraversal(p);
  return 0;
}