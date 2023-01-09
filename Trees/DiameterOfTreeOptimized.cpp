/// Largest distance between any two nodes of the tree

/// O(n) time

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

class HDpair{
public:
    int height;
    int diameter;
};

HDpair optDiameter(node* root){
    HDpair p;
    if(root==NULL){
        p.height=p.diameter=0;
        return p;
    }
    HDpair L=optDiameter(root->left);
    HDpair R=optDiameter(root->right);
    p.height=max(L.height, R.height)+1;
    int d1=L.height+R.height;
    int d2=L.diameter;
    int d3=R.diameter;
    p.diameter=max(d1,max(d2,d3));
    return p;
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
    cout<<"Diameter of Tree: "<<optDiameter(root)<<endl;
    return 0;
}
