#include<bits/stdc++.h>
using namespace std;

bool isSubset(string s1, string s2){
    int i=s1.size()-1;
    int j=s2.size()-1;
    while(i>=0 and j>=0){
        if(s1[i]==s2[j]){
            i--, j--;
        }else{
            i--;
        }
    }
    if(j==-1) return true;
    return false;
}

int main(){
    string s1, s2;
    getline(cin, s1);
    getline(cin, s2);
    cout<<isSubset(s1,s2);
    return 0;
}
