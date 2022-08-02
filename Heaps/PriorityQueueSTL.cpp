#include<iostream>
#include<queue>
using namespace std;

int main()
{
    int arr[]={10,15,20,13,6,90};
    int n=sizeof(arr)/sizeof(int);

    priority_queue<int> heap;                      // By default Max-Heap

    for(int x : arr)
    {
        heap.push(x);
    }

    while(!heap.empty())
    {
        cout<<heap.top()<<endl;
        heap.pop();
    }

    cout<<endl;

    priority_queue<int, vector<int>, greater<int>> heap2;      // Min Heap

    for(auto y : arr)
    {
        heap2.push(y);
    }

    while(!heap2.empty())
    {
        cout<<heap2.top()<<endl;
        heap2.pop();
    }


    return 0;
}
