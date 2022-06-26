#include<iostream>
#include<queue>
#include<stack>
using namespace std;

//Making a LIFO data structure using a FIFO data structure

class Stack
{
    queue<int> q1,q2;
public:
    void push(int x)
    {
        if(!q1.empty())
        {
            q1.push(x);
        }
        else
        {
            q2.push(x);
        }
    }

    void pop()
    {
        if(q1.empty())
        {
            while(!q2.empty())
            {
                int Front=q2.front();
                q2.pop();

                if(q2.empty())
                {
                    break;
                }
                q1.push(Front);
            }
        }
        else{
             while(!q1.empty())
            {
                int Front=q1.front();
                q1.pop();
                if(q1.empty())
                {
                    break;
                }
              q2.push(Front);
        }
    }
}

    int top()
    {
        if(q1.empty())
        {
            while(!q2.empty())
            {
                int Front=q2.front();
                q2.pop();
                q1.push(Front);
                if(q2.empty())
                    return Front;
            }
        }
        else{
                while(!q1.empty())
            {
                int Front=q1.front();
                q1.pop();
                q2.push(Front);
                if(q1.empty())
                    return Front;
            }
        }
    }
    bool empty()
    {
        return q1.empty() and q2.empty();
    }
};


int main()
{
    Stack s;
    s.push(1);
    s.push(2);
    s.push(3);
    s.pop();
    s.push(4);
    s.push(5);
    s.pop();
    s.pop();
    s.push(6);

    while(!s.empty())
    {
        cout<<s.top()<<endl;
        s.pop();
    }
    return 0;
}
