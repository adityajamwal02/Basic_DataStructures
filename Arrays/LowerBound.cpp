#include<bits/stdc++.h>
using namespace std;

int lowerBound(vector<int> A, int Val) {
    int n=A.size();
    int low=0, high=n-1;
    int answer=-1;

    while(low<=high){
        int mid=low+(high-low)/2;
        if(Val<A[mid]){
            high=mid-1;
        }else{
            answer=A[mid];
            low=mid+1;
        }
    }
    return answer;
}
