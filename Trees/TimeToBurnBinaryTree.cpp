
int findMaxDistance(map<TreeNode*, TreeNode*> &mp, TreeNode* target){
    queue<TreeNode*> q;
    q.push(target);
    map<TreeNode*, int> vis;
    vis[target]=1;
    int maxi=0;
    while(!q.empty()){
        int sz=q.size();int fl=0;
        for(int i=0;i<sz;i++){
            auto node=q.front();
            q.pop();
            if(node->left and !vis[node->left]){
                fl=1;
                vis[node->left]=1;
                q.push(node->left);
            }
            if(node->right and !vis[node->right]){
                fl=1;
                vis[mp[node]]=1;
                q.push(mp[node]);
            }
        }
        if(fl)
            maxi++;
    }
return maxi;
}


TreeNode* bfsToMapParents(TreeNode* root, map<TreeNode*, TreeNode*> &mp, int start){
    queue<TreeNode*> q;
    q.push(root);
    TreeNode* res;
    while(!q.empty()){
        TreeNode* node=q.front();
        if(node->data==start)
            res=node;
        q.pop();
        if(node->left){
            mp[node->left]=node;
            q.push(node->left);
        }
        if(node->right){
            mp[node->right]=node;
            q.push(node->right);
        }
    }
    return res;
}

int timeToBurnTree(TreeNode* root, int start){
    map<TreeNode*, TreeNode*> mp;
    TreeNode* target=bfsToMapParents(root,mp,start);
    int maxi=findMaxDistance(mp,target);

    return maxi;
}
