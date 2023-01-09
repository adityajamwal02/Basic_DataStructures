/*
Expression Tree
Given a full binary expression tree consisting of basic binary operators (+ , – ,*, /) and some integers in the form of string, Your task is to evaluate the expression tree.
Note: All the nodes' data are in the form of string.
Input Format
In the function a pointer to the root node of the binary tree is passed.
Output Format
Return an integer representing the final value of the expression.
*/

#include <bits/stdc++.h>
using namespace std;

struct Node {
    string key;
    Node* left, *right;
};

bool operation(string data){
    if(data=="+" or data=="-" or data=="*" or data=="/") return true;
return false;
}
int evalTree(Node* root){
    if(!root){
        return 0;
    }
    if(!operation(root->key)){
        return stoi(root->key);
    }

    if(root->key=="+") return evalTree(root->left)+evalTree(root->right);
    if(root->key=="-") return evalTree(root->left)-evalTree(root->right);
    if(root->key=="*") return evalTree(root->left)*evalTree(root->right);
    if(root->key=="/") return evalTree(root->left)/evalTree(root->right);

}

