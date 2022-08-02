#include<vector>
using namespace std;

class heap
{
    vector<int> v;

    void heapify(int i)
    {
        int left = 2*i;
        int right = 2*i+1;
        int minIndex = i;
        if(left<v.size() and v[left]<v[i])
        {
            minIndex=left;
        }
        if(right<v.size() and v[right]<v[minIndex])
        {
            minIndex=right;
        }
        if(minIndex!=i)
        {
            swap(v[i],v[minIndex]);
            heapify(minIndex);
        }
    }


public:
    heap(int default_size=10)
    {
        v.reserve(default_size+1);
        v.push_back(-1);
    }

    //Insertion

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

    //Returning Minimum element (Min heap)
    int top()
    {
        return v[1];
    }

    //Removing Mininmum element
    void pop()
    {
        int index=v.size()-1;
        swap(v[1],v[index]);
        v.pop_back();
        heapify(1);
    }

    // Empty Check
    bool isEmpty()
    {
        return v.size()==1;
    }
};

