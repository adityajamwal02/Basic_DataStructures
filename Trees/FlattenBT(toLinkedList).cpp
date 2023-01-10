/*
Iterative approach with morris traversal
*/

curr=root;
while(curr!=NULL){
    if(curr->left!=NULL)
    {
        prev=curr->left;
        while(prev->right)
            prev=prev->right;
        prev->right=curr->right;
        curr->right=curr->left;
    }
    curr=curr->right;
}

