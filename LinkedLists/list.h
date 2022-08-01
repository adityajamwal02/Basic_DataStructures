#include<iostream>
using namespace std;

class List;

class Node{
    int data;

public:

    Node* next;
    Node(int d):data(d),next(NULL){}        // Constructor Calling by Initialization List

    int getData(){
        return data;
    }

    ~Node(){
        if(next!=NULL)
            delete next;
    }


    friend class List;
};


class List{
    Node *head;
    Node *tail;

    int searchHelper(Node *start, int key){
        if(start==NULL)
            return -1;
        if(start->data==key){
            return 0;
        }
        int subIdx=searchHelper(start->next, key);
        if(subIdx==-1)
            return -1;

        return subIdx+1;
    }

public:

    List():head(NULL),tail(NULL){}

    Node* begin(){
        return head;
    }

// Adding Operations

    void push_front(int data){
        if(head==NULL){
                Node* n = new Node(data);
                head=tail=n;
        }
        else{
            Node* n = new Node(data);
            n->next = head;
            head=n;
        }
    }

    void push_back(int data){
        if(head==NULL){
            Node* n = new Node(data);
            head=tail=n;
        }
        else{
            Node* n = new Node(data);
            tail->next = n;
            tail=n;
        }
    }

    void insert(int data, int pos){
        if(pos==0){
            push_front(data);
            return;
        }
        Node* temp = head;
        for(int i=2;i<=pos;i++){
            temp=temp->next;
        }
        Node *n=new Node(data);
        n->next=temp->next;
        temp->next=n;
    }

// Search Operation

    int search(int key){
        Node* temp=head;
        int index=0;

        while(temp!=NULL){
            if(temp->data==key)
                return index;

            index++;
            temp=temp->next;
        }
        return -1;
    }

    int recursiveSearch(int key){
        int idx=searchHelper(head,key);
        return idx;
    }

// Delete Operations

    void pop_front(){
        Node* temp = head;
        head=head->next;
        temp->next=NULL;
        delete temp;
    }

    void pop_back(){
        if(head==NULL){
            cout<<"\n Empty List"<<endl;
        }
        else{
            Node* temp = tail;
            tail=tail->next;
            tail->next = NULL;
            delete temp;
        }
    }


    void remove(int pos){
        if(pos==0){
            pop_front();
            return;
        }
        Node* temp = head;
        for(int i=1;i<=pos;i++){
            temp=temp->next;
        }
        Node *n=temp->next;
        temp->next=n->next;
        n->next=NULL;
        delete n;
    }

    ~List(){
        if(head!=NULL){
            delete head;
            head=NULL;
        }
    }


    void reverse(Node* &head){
        Node *curr = head;
        Node *prev = NULL;
        Node *N;

        while(curr!=NULL){
            //Save next node
            N=curr->next;
            //Make the current node point to previous
            curr->next=prev;
            //Update prev and curr take them 1 step ahead
            prev=curr;
            curr=N;
        }
        head = prev;
    }

};
