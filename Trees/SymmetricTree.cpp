/// Symmteric Tree

/// Non-Recursive Queue Approach


#include <bits/stdc++.h>
using namespace std;

struct Node {
    int key;
    Node* left, *right;
};

bool isSymmetric(Node* root) {
    queue<Node*> q1, q2;
    if(root==NULL or (root->right==NULL and root->left==NULL)) return true;
    if(root->right==NULL or root->left==NULL) return false;
    q1.push(root->left);
    q2.push(root->right);
    while(!q1.empty() and !q2.empty()){
        Node* temp1=q1.front();
        q1.pop();
        Node* temp2=q2.front();
        q2.pop();
        if(q1.empty() and !q2.empty()) return false;
        if(q2.empty() and !q1.empty()) return false;
        if(temp1->left==NULL and temp2->right!=NULL) return false;
        if(temp1->left!=NULL and temp2->right==NULL) return false;
        if(temp1->key!=temp2->key) return false;
        if(temp1->left) q1.push(temp1->left);
        if(temp1->right) q1.push(temp1->right);
        if(temp2->right) q2.push(temp2->right);
        if(temp2->left) q2.push(temp2->left);
    }
    if(q1.empty() and q2.empty()) return true;
        return false;
}


/// Recursive case

#include <bits/stdc++.h>
using namespace std;

struct Node {
    int key;
    Node* left, *right;
};

bool helper(Node* L, Node* R){
    if(L==NULL and R==NULL){
        return true;
    }
    if((L==NULL and R!=NULL) or (L!=NULL and R==NULL) or (L->key!=R->key))
        return false;
    return (helper(L->left, R->right) and helper(L->right, R->left));
}
bool isSymmetric(Node* root) {
    return helper(root->left, root->right);
}
