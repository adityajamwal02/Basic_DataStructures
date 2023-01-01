/*
Duplicate Parentheses
Given a balanced expression, find if it contains duplicate parenthesis or not. A set of parenthesis are duplicate if the same subexpression is surrounded by multiple parenthesis.
Input Format
In the function a balanced string str is passed.
Output Format
Return a true if it contains duplicates else return false.

Sample Input 1
((a+b)+((c+d)))
Sample Output 1
true
Sample Input 2
(((a+(b)))+(c+d))
Sample Output 2
true
Explanation
sample 1: The subexpression "c+d" is surrounded by two
pairs of brackets.
sample 2: The subexpression "a+(b)" is surrounded by two
pairs of brackets.
*/

#include<bits/stdc++.h>
using namespace std;

bool duplicateParentheses(string str){
    stack<char> st;
    for(char ch: str){
        if(ch==')'){
            char top=st.top();
            st.pop();
            int insideElements=0;
            while(top!='('){
                insideElements++;
                top=st.top();
                st.pop();
            }
            if(insideElements<1){
                return true;
            }
        }else{
            st.push(ch);
        }
    }
return false;
}
