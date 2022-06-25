#include<bits/stdc++.h>
using namespace std;

class Queue
{
    int *arr;
    int ms, cs;
    int Front,Rear;

public:
    Queue(int default_size=5)
    {
        ms=default_size;
        arr=new int[ms];
        cs=0, Front=0; Rear=ms-1;
    }
    bool full()
    {
        return cs==ms;
    }
    bool Empty()
    {
        return cs==0;
    }
    void push(int data)
    {
        if(!full())
        {
            Rear=(Rear+1)%ms;
            arr[Rear]=data;
            cs++;
        }
    }
    void pop()
    {
        if(!Empty())
        {

            Front=(Front+1)%ms;
            cs--;
        }
    }

    int getfront()
    {
        return arr[Front];
    }
};

int main()
{
    Queue q(5);

    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    q.push(5);
    q.pop();
    q.pop();
    q.pop();
    q.push(6);

    while(!q.Empty())
    {
        cout<<q.getfront()<<endl;
        q.pop();
    }

    return 0;
}
