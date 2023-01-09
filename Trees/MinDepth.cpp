/*
Min Depth
Given a binary tree with N nodes. Your task is to find the minimum depth.
Input Format
In the function a pointer to the root node of the binary tree is passed.
Output Format
Return an integer representing minimum depth
*/


#include <bits/stdc++.h>
using namespace std;

struct Node {
    int key;
    Node* left, *right;
};

int minDepth(Node *root) {
    int res=INT_MAX;
    queue<pair<Node*, int>> q;
    int d=1;
    q.push({root, d});
    while(!q.empty()){
        Node* temp=q.front().first;
        d=1+q.front().second;
        if(temp->left==NULL and temp->right==NULL){
            res=min(res,q.front().second);
        }
        q.pop();
        if(temp->left) q.push({temp->left, d});
        if(temp->right) q.push({temp->right, d});
    }
    return res;

}
