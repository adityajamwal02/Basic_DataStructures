/*
Reverse a number using stack
Given a number , write a program to reverse this number using stack.
Input Format
In the function an integer is passed
Output Format
Return an integer

Sample Input
456
Sample Output
654
*/

#include <bits/stdc++.h>
using namespace std;

int reverse(int n){
    stack<int> st;
    while(n!=0){
        st.push(n%10);
        n/=10;
    }
    int rev=0, i=1;
    while(!st.empty()){
        rev+=(st.top()*i);
        st.pop();
        i=i*10;
    }
	return rev;
}
