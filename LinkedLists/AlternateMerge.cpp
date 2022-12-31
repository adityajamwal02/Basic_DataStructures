/*
Alternate Merge
Given two linked lists, insert nodes of second list into first list at alternate positions of first list.
Input Format
In the function pointer to the start of the two linklists is passed.
Output Format
Return a pointer to the new merged list.

Sample Input
5->7->17->13->11
12->10->2->4->6
Sample Output
5->12->7->10->17->2->13->4->11->6
*/


#include<bits/stdc++.h>
using namespace std;


class node{
public:
	int data;
	node* next;

	node(int data){
		this->data = data;
		next = NULL;
	}
};

node* apend(node* root, int data){
    if(root==NULL){
        return new node(data);
    }
    node *temp=root;
    while(temp->next){
        temp=temp->next;
    }
    temp->next=new node(data);
    return root;
}
node* alternateMerge(node * root1, node* root2){
    node* root=NULL;
    if(!root1){
        return root2;
    }
    if(!root2){
        return root1;
    }
    while(root1 and root2){
        root=apend(root, root1->data);
        root=apend(root, root2->data);
        root1=root1->next;
        root2=root2->next;
    }
    if(root1){
        while(root1){
            root=apend(root,root1->data);
            root1=root1->next;
        }
    }
    if(root2){
        while(root2){
            root=apend(root,root2->data);
            root2=root2->next;
        }
    }
    return root;
}
