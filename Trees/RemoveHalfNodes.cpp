/*
Given A binary Tree. Your task is to remove all the half nodes (which has only one child) and return the INORDER traversal of the updated binary tree.
Input Format
In the function a pointer to the root node of the binary tree is passed.
Output Format
Return an integer vector containing INORDER traversal of the updated binary tree.

Sample Input

Sample Output
INORDER traversal of the new tree : 1 6 11 2 4
Explanation
Nodes 7, 5 and 9 are half nodes as one of their child is Null.
*/


#include <bits/stdc++.h>
using namespace std;

struct Node {
    int key;
    Node* left, *right;
};

void inorder(Node* root, vector<int> &result){
    if(!root) return;
    if(root->left) inorder(root->left, result);
    result.push_back(root->key);
    if(root->right) inorder(root->right, result);
}

Node* helper(Node* root){
    if(!root) return NULL;
    if(root->right){
        root->right=helper(root->right);
    }
    if(root->left){
        root->left=helper(root->left);
    }
    if((root->left!=NULL and root->right==NULL) or (root->left==NULL and root->right!=NULL)){
        if(root->left) root=root->left;
        else root=root->right;
        root=helper(root);
    }
    return root;
}

vector<int> removeHalfNodes(Node *root)
{
    root=helper(root);
    vector<int> result;
    inorder(root, result);
return result;
}
