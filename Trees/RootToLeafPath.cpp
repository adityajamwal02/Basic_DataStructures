/// Root to Leaf Path

#include<vector>
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

void printRoot2LeafPaths(Node* root, vector<int> &path){
    if(!root){
        return;
    }
    if(root->left==NULL and root->right==NULL){
        for(int node: path){
            cout<<node<<"->";
        }
        cout<<root->key<<" ";
        cout<<endl;
        return;
    }
    path.push_back(root->key);
    printRoot2LeafPaths(root->left,path);
    printRoot2LeafPaths(root->right,path);
    path.pop_back();
    return;
}

int main(){
     Node* root=NULL;
     int arr[]={8,3,10,1,6,14,4,7,13};
     for(int x: arr){
            root=insert(root, x);
     }
     vector<int> path;
     printRoot2LeafPaths(root,path);

    return 0;
}

