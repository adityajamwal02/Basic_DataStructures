/*
Bubble Sort on Linked List
Given a singly linked list, sort it using bubble sort.
Input: 10->30->20->5
Output: 5->10->20->30
*/

#include <iostream>
using namespace std;
class node
{
public:
    int data;
    node *next;
    node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
};

int len(node* head){
    node* temp=head;
    int i=0;
    while(temp!=NULL){
        i++;
        temp=temp->next;
    }
return i;
}


node* bubble_sort_LinkedList_itr(node* head)
{
    int n=len(head)-1;
    while(n--){
        node* prev=NULL;
        node* curr=head;
        while(curr->next!=NULL){
            if(curr->data >= curr->next->data){
                if(prev==NULL){
                    node* nxt=curr->next;
                    curr->next=nxt->next;
                    nxt->next=curr;
                    prev=nxt;
                    head=prev;
                }else{
                    node* nxt=curr->next;
                    prev->next=nxt;
                    curr->next=nxt->next;
                    nxt->next=curr;
                    prev=nxt;
                }
            }else{
                prev=curr;
                curr=curr->next;
            }
        }
    }
    return head;
}
