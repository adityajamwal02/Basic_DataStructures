#include<iostream>
#include<vector>
using namespace std;

int main()
{
    int n;
    cin>>n;

    vector<int> a(n+1,-1);

    for(int i=0;i<n;i++)
        cin>>a[i];

    int total=0;
    int mx=-1;

    if(n==1)
    {
        cout<<"1"<<endl;
        return 0;
    }

    for(int i=0;i<n;i++)
    {
        if(a[i]>mx and a[i]>a[i+1])
            total++;

        mx=max(mx, a[i]);

    }
    cout<<total<<endl;

    return 0;

}
