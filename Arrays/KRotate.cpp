#include<bits/stdc++.h>
using namespace std;

vector<int> kRotate(vector<int> a, int k){
    vector<int> temp(a.size());
    for(int i=0;i<a.size();i++){
        temp[(i+k)%a.size()]=a[i];
    }
    return temp;
}
