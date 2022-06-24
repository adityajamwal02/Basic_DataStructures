#include<vector>
#include<bits/stdc++.h>
using namespace std;


class node
{
public:
    int data;
    node(int d)
    {
        data=d;
    }
};

class Stack
{
    vector<int> arr;
public:
    void push(int data)
    {
        arr.push_back(data);
    }
    void pop()
    {
        arr.pop_back();
    }
    int top()
    {
        int lastindex=arr.size()-1;
        return arr[lastindex];
    }
    bool empty()
    {
        return arr.size()==0;
    }
};

int main()
{
    Stack s;
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);
    s.push(5);
    s.push(6);

    while(!s.empty())
    {
        cout<<s.top();
        s.pop();
    }
    return 0;
}
