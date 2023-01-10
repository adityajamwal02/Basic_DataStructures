/*
Mirror a BST
Given a binary tree, convert it into its mirror form. A binary tree is said to be mirrored when left and right children of all non-leaf nodes are interchanged.
Input Format
In the function pointer to the root of the binary tree is passed.
Output Format
Return the pointer to the root of the mirrored tree.
*/


#include<bits/stdc++.h>
using namespace std;

class Node
{
  public:
   int key;
   Node *left;
   Node *right;

   Node(int key){
       this->key = key;
       left = right  = NULL;
   }
};

void helper(Node* node){
    if(!node) return;
    else{
        Node* temp;
        helper(node->left);
        helper(node->right);
        temp=node->left;
        node->left=node->right;
        node->right=temp;
    }
}

Node* mirrorBST(Node * root){
    helper(root);
return root;
}
