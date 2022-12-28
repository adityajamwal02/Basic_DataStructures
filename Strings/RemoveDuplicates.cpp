/*
Given a string S, the task is to remove all the duplicates from the given string
and return the updated string in sorted order.
Input Format
In the function a string is passed.
Output Format
Return the updated string.
Sample Input
string s = "geeksforgeeks"
Sample Output
"efgkors"
*/

#include <bits/stdc++.h>
using namespace std;

string removeDuplicate(string s){
    string result;
    set<char> st(s.begin(), s.end());
    for(auto x: st){
        result.push_back(x);
    }
    sort(result.begin(), result.end());
return result;
}
