#include<bits/stdc++.h>
#include<iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *left;
    Node *right;

    Node(int d)
    {
        data=d;
        left=right=NULL;
    }
};

//Inorder Traversal


Node* buildtree()
{
    int d;
    cin>>d;
    if(d==-1)
        return NULL;

    Node* n= new Node(d);
    n->left=buildtree();
    n->right=buildtree();
    return n;

}

void printinorder(Node *root)
{
    if(root==NULL)
        return;
    printinorder(root->left);
    cout<<root->data<<" ";
    printinorder(root->right);
}

int main()
{
    Node* root=buildtree();
    printinorder(root);

    return 0;
}

