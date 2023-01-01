/*
Next Greater Element
Given an array, return the Next Greater Element for every element. The Next greater Element for an element x is the first greater element on the right side of x in the array. Elements for which no greater element exist, consider the next greater element as -1.
Input Format
In the function an integer vector is passed
Output Format
Return an integer vector containing the next greater element for each element

Sample Input
v = { 4, 5, 2, 25 }
Sample Output
{ 5, 25, 25, -1 }
*/

/// Stack Approach

#include<bits/stdc++.h>
using namespace std;

vector<int> nextGreaterElement(vector<int> v){
    stack<int> st;
    int n=v.size();
    vector<int> result(n,0);
    for(int i=n-1;i>=0;i--){
        while(!st.empty() and st.top()<=v[i]){
            st.pop();
        }
        if(st.empty()){
            result[i]=-1;
        }else{
            result[i]=st.top();
        }
        st.push(v[i]);
    }
    return result;
}
