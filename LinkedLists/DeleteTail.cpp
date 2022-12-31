/*
Delete Tail
Given a pointer to the root of the linklist, your task is to delete the tail of the linklist and return the head of the updated list.
Input
1->2->3->4->5->6->7->8
Output
1->2->3->4->5->6->7
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

node* deleteTail(node * head){
    if(head==NULL){
        return NULL;
    }
    if(head->next==NULL){
        delete head;
        return NULL;
    }
    node* second_last=head;
    while(second_last->next->next!=NULL){
        second_last=second_last->next;
    }
    delete (second_last->next);
    second_last->next=NULL;
    return head;
}
