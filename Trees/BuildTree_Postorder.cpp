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

//Postorder Traversal


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

void printpostorder(Node *root)
{
    if(root==NULL)
        return;
    printpostorder(root->left);
    printpostorder(root->right);
    cout<<root->data<<" ";
}

int main()
{
    Node* root=buildtree();
    printpostorder(root);

    return 0;
}
