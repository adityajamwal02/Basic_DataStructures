/*
Maximum Subarray Sum
Implement a function that takes an input a vector of integers, and prints the maximum subarray sum that can be formed. A subarray is defined as consecutive segment of the array. If all numbers are negative, then return 0.

Input
{-1,2,3,4,-2,6,-8,3}
Output
13

Hint
Expected Time Complexity
O(N)

Space Complexity
O(1)
*/


#include<bits/stdc++.h>
using namespace std;

int maxSubarraySum(vector<int> &arr){
    int n=arr.size();
    int cs=0, ms=0;
    for(int i=0;i<n;i++){
        cs+=arr[i];
        ms=max(ms,cs);
        if(cs<0){
            cs=0;
        }
    }
    return ms;
}

int main(){
    vector<int> arr{-1,2,3,4,-2,6,-8,3};
    return maxSubarraySum(arr);
}
