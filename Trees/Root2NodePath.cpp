
class Solution{

public:

    bool getPath(TreeNode *root, vector<int> &arr, int x){
        if(!root)
            return false;

        arr.push_back(root->val);
        if(root->val==x)
            return true;
        if(getPath(root->left, arr, x) or getPath(root->right, arr, x))
            return true;

        arr.pop_back();
        return false;
    }

    vector<int> solve(TreeNode* A, int x){
        vector<int> arr;
        if(A==NULL)
            retur arr;

        getPath(A, arr, x);
        return arr;
    }

};
