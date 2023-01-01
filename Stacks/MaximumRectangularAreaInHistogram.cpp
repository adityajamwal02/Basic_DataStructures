/*
Maximum Rectangular Area in Histogram
Find the largest rectangular area possible in a given histogram where the largest rectangle can be made of a number of contiguous bars. Assume that all bars have width of 1 unit.
Input Format
In the function an integer vector representing height of the bars is passed.
Output Format
Return an integer representing the maximum possible area.
Sample Input
{6, 2, 5, 4, 5, 1, 6}
Sample Output
12
*/

#include<bits/stdc++.h>
using namespace std;

int getMaxArea(vector<int> hist){
    int n=hist.size();
    stack<int> st;
    int max_area=INT_MIN;
    int tp, area_tp, i=0;
    while(i<n){
        if(st.empty() or hist[st.top()]<=hist[i]){
            st.push(i++);
        }else{
            tp=st.top();
            st.pop();
            area_tp=hist[tp]*(st.empty() ? i : i-st.top()-1);
            if(max_area<area_tp){
                max_area=area_tp;
            }
        }
    }
    while(!st.empty()){
        tp=st.top();
        st.pop();
        area_tp=hist[tp]*(st.empty() ? i : i-st.top()-1);
        if(max_area<area_tp){
            max_area=area_tp;
        }
    }
return max_area;
}
