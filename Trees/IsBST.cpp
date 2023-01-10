/*
IsBST?
Given a Binary Tree, Check if the tree is a BST or not!
Example-I

   1

  /   \

2     3

/  \     \

4    5    6

false

Example-II

   4

  /   \

2     5

/  \     \

1    3    6

true
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

bool helper(Node* node, int min, int max){
    if(!node) return true;
    if(node->key<min or node->key>max){
        return false;
    }
    return (helper(node->left, min, node->key) and helper(node->right, node->key, max));
}

bool isBST(Node * root){
    return helper(root, INT_MIN, INT_MAX);
}
