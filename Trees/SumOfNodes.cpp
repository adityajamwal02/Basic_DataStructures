/*
Sum of Nodes
Given a binary tree with N nodes. Your task is to return the sum of all N nodes.
Input Format
In the function a pointer to the root node of the binary tree is passed.
Output Format
Return a integer representing sum of all nodes
Sample Input

Sample Output
39
*/

#include <bits/stdc++.h>
using namespace std;

struct Node {
    int key;
    Node* left, *right;
};

int sumBT(Node* root)
{
    queue<Node*> q;
    int sum=0;
    q.push(root);
    while(!q.empty()){
        Node* temp=q.front();
        q.pop();
        if(temp->left) q.push(temp->left);
        if(temp->right) q.push(temp->right);
        sum+=temp->key;
    }
    return sum;
}
