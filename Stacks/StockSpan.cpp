
#include <bits/stdc++.h>
using namespace std;

vector<int> stockSpanner(vector<int> &stocks){
    int n=stocks.size();
    stack<int> s;
    s.push(0);
    vector<int> arr(n,1);
    for(int i=1;i<n;i++){
        while(!s.empty() and stocks[s.top()]<=stocks[i]){
            s.pop();
        }
        if(!s.empty()){
            arr[i]=i-s.top();
        }else{
            arr[i]=i+1;
        }
    s.push(i);
    }
return arr;
}
