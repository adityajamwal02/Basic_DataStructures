#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

bool threeSum(vector<int> a, int n, int target)
{
    bool found=0;
    sort(a.begin(), a.end());
    for(int i=0;i<n;i++)
    {
        int low=i+1, high=n-1;
        while(low<high)
        {
            int current=a[i]+a[low]+a[high];
            if(current==target)
                found=true;
            if(current<target)
                low++;
            else
                high--;
        }
    }
    if(found)
        return true;

    return false;
}


int main(){
    int n;
    cin>>n;
    vector<int> a(n);
    for(int i=0;i<n;i++)
        cin>>a[i];

    int target;
    cin>>target;

    cout<<threeSum(a,n,target);

    return 0;

}
