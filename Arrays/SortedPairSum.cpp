#include<bits/stdc++.h>
using namespace std;

pair<int, int> closestSum(vector<int> arr, int x){
    int n=arr.size();
    int left, right;
    int i=0, j=n-1, minDiff=INT_MAX;
    while(i<j){
        if(abs(x-(arr[i]+arr[j]))<minDiff){
            left=i, right=j;
            minDiff=abs(x-(arr[i]+arr[j]));
        }
        if(arr[i]+arr[j]>x){
            j--;
        }else{
            i++;
        }
    }
    return {arr[left], arr[right]};
}
