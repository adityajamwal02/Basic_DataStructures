/// Complete BST : Creation, searching, deletion, Root To Leaf Path, Check BST or not


#include<iostream>
#include<bits/stdc++.h>
using namespace std;


/// Node Creation

class Node{
public:
    int key;
    Node* left;
    Node* right;

    Node(int key){
        this->key=key;
        left=right=NULL;
    }
};

/// Insert Function in BST

Node* insert(Node* root, int key){
    if(root==NULL){
        return new Node(key);
    }
    if(key<root->key){
        root->left=insert(root->left, key);
    }else{
        root->right=insert(root->right, key);
    }
return root;
}

/// Search Function in BST

bool search(Node* root, int key){
    if(!root){
        return false;
    }
    if(root->key==key){
        return true;
    }
    if(key<root->key){
        return search(root->left, key);
    }
    return search(root->right, key);
}

/// Find Minimum in right subtree
Node* findMin(Node* root){
    while(root->left!=NULL){
        root=root->left;
    }
    return root;
}
/// Delete Function in BST

Node* remove(Node* root, int key){
    if(root==NULL){
        return NULL;
    }
    else if(key<root->key){
        root->left=remove(root->left, key);
    }
    else if(key>root->key){
        root->right=remove(root->right, key);
    }else{
        if(root->left==NULL and root->right==NULL){
            delete root;
            root=NULL;
        }
        else if(root->left==NULL){
            Node* temp=root;
            root=root->right;
            delete temp;
        }
        else if(root->right==NULL){
            Node* temp=root;
            root=root->left;
            delete temp;
        }
        else{
            Node *temp=findMin(root->right);
            root->key=temp->key;
            root->right=remove(root->right,temp->key);
        }
    }
    return root;
}

/// Printing Nodes

void printInorder(Node* root){
    if(!root){
        return;
    }
    printInorder(root->left);
    cout<<root->key<<" ,";
    printInorder(root->right);
}

int main(){
     Node* root=NULL;
     int arr[]={8,3,10,1,6,14,4,7,13};
     for(int x: arr){
            root=insert(root, x);
     }
     printInorder(root);
     int key;
     cin>>key;

     cout<<search(root,key)<<endl;

     root=remove(root,key);
     printInorder(root);

    return 0;
}
