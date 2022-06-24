#include<iostream>
using namespace std;

class Stack;

class node{
public:
    char data;
    node *next;

    node(char d)
    {
        data=d;
    }
};

class Stack{
    node *head;
public:
    Stack()
    {
        head=NULL;
    }
    void push(char data)
    {
        node *n= new node (data);
        n->next=head;
        head=n;
    }

    bool empty()
    {
        return head==NULL;
    }
    char top()
    {
        return head->data;
    }

    void pop()
    {
        if(head!=NULL)
        {
            node *temp = head;
            head=head->next;
            delete temp;
        }
    }

};


int main()
{
    Stack s;
    s.push('a');
    s.push('d');
    s.push('i');
    s.push('t');
    s.push('y');
    s.push('a');

    while(!s.empty())
    {
        cout<<s.top();
        s.pop();
    }
    return 0;
}
