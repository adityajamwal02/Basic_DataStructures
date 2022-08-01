#include<iostream>
#include "list.h"
using namespace std;

int main()
{
    List l;
    l.push_front(1);
    l.push_front(2);
    l.insert(6,0);
    l.push_front(3);
    l.push_front(5);
    l.push_back(0);
    l.insert(4,1);
    l.remove(2);
    l.pop_back();

    Node* head = l.begin();
    while(head!=NULL){
        cout<<head->getData()<<"->";
        head=head->next;
    }

    cout<<endl;
/*
    int key;
    cin>>key;
    cout<<l.recursiveSearch(key);
*/
    //l.reverse(head);

    return 0;
}
