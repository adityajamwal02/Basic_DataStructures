/// Print all elements in range k1 and k2

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

/// Print in Range
void printRange(Node* root, int k1, int k2){
    if(root==NULL){
        return;
    }
    if(root->key>=k1 and root->key<=k2){
        printRange(root->left,k1,k2);
        cout<<root->key<<" ";
        printRange(root->right,k1,k2);
    }else if(root->key>k2){
        printRange(root->left,k1,k2);
    }else{
        printRange(root->right,k1,k2);
    }
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
     printRange(root,5,12);

    return 0;
}
