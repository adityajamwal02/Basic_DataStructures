#include<bits/stdc++.h>
#include<vector>
using namespace std;

int main()
{
    int n;
    cin>>n;

    vector<int> a(n, 0);

    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }

    int ans=2;
    int pd=a[1]-a[0]; //previous difference
    int j=2;              //Current updater, already seen till a[1]
    int curr=2;

    while(j<n)
    {
        if(pd==(a[j]-a[j-1]))
        {
            curr++;
        }
        else{
            pd=a[j]-a[j-1];
            curr=2;
        }
        ans=max(ans,curr);
        j++;
    }
    cout<<ans<<endl;

    return 0;
}
