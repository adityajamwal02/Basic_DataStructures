/*
Delete in BST
Given a root node reference of a BST and a key, delete the node with the given key in the BST. Return the root node reference (possibly updated) of the BST.
Basically, the deletion can be divided into two stages:
Search for a node to remove.
If the node is found, delete the node.
Example:

     7

    / \

  5    9

/ \   / \

3 6  8 10

Delete node 9
Return:

    7

    / \

  5    8

/ \     \

3 6    10
*/


#include<bits/stdc++.h>
using namespace std;

class node{
    public:
     int data;
     node*left;
     node*right;
     node(int d){
       data=d;
       left=NULL;
       right=NULL;
     }
 };

 node* deleteNode(node* root, int k)
{
   if(!root){
       return root;
   }
   if(root->data > k){
       root->left=deleteNode(root->left, k);
       return root;
   }
   else if(root->data < k){
       root->right=deleteNode(root->right, k);
       return root;
   }
   if(root->left==NULL){
       node* temp=root->right;
       delete root;
       return temp;
   }else if(root->right==NULL){
       node* temp=root->left;
       delete root;
       return temp;
   }else{
       node* parent=root;
       node* succ=root->right;
       while(succ->left!=NULL){
           parent=succ;
           succ=succ->left;
       }
       if(parent!=root){
           parent->left=succ->right;
       }else{
           parent->right=succ->right;
       }
      root->data=succ->data;

     delete succ;
     return root;
   }

}
