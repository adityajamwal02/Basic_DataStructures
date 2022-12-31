/*
Kth Last Element
Implement a function that returns the Kth last of element from the linked list, in a single pass. You can assume K will be less than / equal to length of linked list.
(Hint : Use two pointers similar to Runner Technique)
Input
You will get head of the linked list.
1 -> 2 -> 3 -> 4 -> 5 ->6 ->7
K = 3
Output
5

Explanation:
Third last element is 5.
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

int kthLastElement(node * head,int k){
    node *fast=head;
    node *slow=head;
    int count=0;
    while(count<k){
        fast=fast->next;
        count++;
    }
    while(fast!=NULL){
        slow=slow->next;
        fast=fast->next;
    }
return slow->data;
}
