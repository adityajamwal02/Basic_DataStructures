
node* levelOrderBuild(){
    int d;
    cin>>d;
    node* root=new node(d);
    queue<node*> q;
    q.push(root);
    while(!q.empty()){
        node* curr=q.front();
        q.pop();
        int c1, c2;
        cin>>c1>>c2;
        if(c1!=-1){
            curr->left=new node(c1);
            q.push(curr->left);
        }
        if(c2!=-1){
            curr->right=new node(c2);
            q.push(curr-> right);
        }
    }
    return root;
}
