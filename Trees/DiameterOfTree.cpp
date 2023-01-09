/// Largest distance between any two nodes of the tree

/// O(n^2) time

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class node{
public:
    int data;
    node* left;
    node* right;

    node(int d){
        data=d;
        left=NULL;
        right=NULL;
    }
};

node* buildTree(){
    int d;
    cin>>d;
    if(d==-1){
        return NULL;
    }
    node* n=new node(d);
    n->left=buildTree();
    n->right=buildTree();

    return n;
}

int height(node* root){
    if(root==NULL){
        return 0;
    }
    int h1=height(root->left);
    int h2=height(root->right);
    return 1+max(h1,h2);
}
int diameter(node* root){
    //Base Case
    if(root==NULL){
        return 0;
    }
    // Recursive Case
    int d1=height(root->left)+height(root->right);
    int d2=diameter(root->left);
    int d2=diameter(root->right);
    return max(d1,max(d2,d3));
}

int main(){
    node* root=buildTree();
    levelOrderPrint(root);
    cout<<"Diameter of Tree: "<<diameter(root)<<endl;
    return 0;
}
