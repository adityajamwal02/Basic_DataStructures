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

//Preorder Traversal


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

void printpreorder(Node *root)
{
    if(root==NULL)
        return;
    cout<<root->data<<" ";
    printpreorder(root->left);
    printpreorder(root->right);
}

int main()
{
    Node* root=buildtree();
    printpreorder(root);

}
