#include<vector>
#include<bits/stdc++.h>
using namespace std;

class heap
{
    vector<int> v;
public:
    heap(int default_size=10)
    {
        v.reserve(default_size+1);
        v.push_back(-1);
    }
    void push(int data)
    {
        v.push_back(data);
        int idx=v.size()-1;
        int parent=idx/2;

        while(idx>1 and v[idx]<v[parent])
        {
            swap(v[idx],v[parent]);
            idx=parent;
            parent=parent/2;
        }
    }
};

int main()
{
    heap h;
    for(int i=0;i<10;i++)
    {
        h.push(i);
    }
    return 0;
}
