/*
K-th Level
Given a binary tree with N nodes. Your task is to print its Kth level.
Input Format
In the function a pointer to the root node of the binary tree is passed.
Output Format
Return a vector containing nodes at Kth level

Input:
          60             --- Level 0
         /  \
       50    30          --- Level 1
      /  \   /
    80   10 40           --- Level 2

K = 1
Output: 30 50

Input:
           50            --- Level 0
          /  \
        60    70         --- Level 1
       /  \   / \
     90   40 40  20      --- Level 2
K = 2
Output: 20 40 90
*/

#include <bits/stdc++.h>
using namespace std;

struct Node {
    int key;
    Node* left, *right;
};

vector<int> printKthLevel(Node* root, int k){
    queue<Node*> q;
    vector<int> ans;
    q.push(root);
    int level=0, flag=0;
    while(!q.empty()){
        int size=q.size();
        while(size--){
            Node* temp=q.front();
            q.pop();
            if(level==k){
                flag=1;
                ans.push_back(temp->key);
            }else{
                if(temp->left) q.push(temp->left);
                if(temp->right) q.push(temp->right);
            }
        }
        level++;
        if(flag==1){
            break;
        }
    }
    return ans;
}
