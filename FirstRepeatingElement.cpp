#include<iostream>
#include<vector>
using namespace std;

int main()
{
    int n;
    cin>>n;

    const int N=1e6+2;
    int minidx=INT_MAX;

    vector<int> a(n,0);
    vector<int> idx(N,-1);

    for(int i=0;i<n;i++){
        cin>>a[i];
    }

    for(int i=0;i<n;i++)
    {
        if(idx[a[i]] != -1)
            minidx=min(minidx, idx[a[i]]);
        else
            idx[a[i]]=i;
    }
    if(minidx==INT_MAX)
        cout<<-1<<endl;
    else
        cout<<minidx+1<<endl;

    return 0;
}
