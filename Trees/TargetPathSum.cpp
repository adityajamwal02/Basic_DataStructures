/// Target Path Sum


/*
Target Path Sum
Given the root of a binary tree and an integer targetSum, return all root-to-leaf paths where each path's sum equals targetSum.
Return an empty vector if no such path exists.
Input Format
In the function a pointer to the root node of the binary tree is passed.
Output Format
Return a vector of vectors containing all those root to leaf paths.
*/

#include <bits/stdc++.h>
using namespace std;

struct Node {
    int val;
    Node* left, *right;
};


void helper(Node* root, int targetSum, vector<vector<int>> &result, vector<int> &v, int b){
    if(!root) return;
    if(root->left==NULL and root->right==NULL){
        if(targetSum==b+root->val){
            v.push_back(root->val);
            result.push_back(v);
            v.pop_back();
        }
    return;
    }
    if(root->left){
        v.push_back(root->val);
        helper(root->left,targetSum, result, v, b+root->val);
        v.pop_back();
    }
    if(root->right){
        v.push_back(root->val);
        helper(root->right,targetSum, result, v, b+root->val);
        v.pop_back();
    }
}

vector<vector<int>> pathSum(Node* root, int targetSum){
    vector<vector<int>> result;
    vector<int> v;
    helper(root, targetSum, result, v, 0);
    return result;
}
