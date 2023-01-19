#include<bits/stdc++.h>
using namespace std;


int countMinSwaps(vector<int> arr, int n){
    // know actual positions of elements
    pair<int,int> p[n];
    int ans=0;
    for(int i=0;i<n;i++){
        p[i].first=arr[i];
        p[i].second=i;
    }
    sort(p,p+n);

    vector<bool> vis(n,false);
    for(int i=0;i<n;i++){
        int old_pos=p[i].second;
        if(vis[i]==true or old_pos==i){
            continue;
        }
        int node=i;
        int cycle=0;
        while(!vis[node]){
            vis[node]=true;
            int nextNode=p[node].second;
            node=nextNode;
            cycle+=1;
        }
    ans+=cycle-1;
    }
    return ans;
}

int main(){
    vector<int> arr{5,4,3,2,1};
    int n=arr.size();
    cout<<countMinSwaps(arr,n)<<endl;
    return 0;
}
