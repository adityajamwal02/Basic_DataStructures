/*
Given a string, your task is to find first non repeating character at each index otherwise return 0.
Input Format
In the function a vector of character is passed.
NOTE : it will contain only lowercase characters .
Output Format
Return a vector of character.

Sample Input
a a b c
Sample Output
a 0 b b

Explanation
at index 0 : 'a' is the first non repeating character until this index.
at index 1 : as 'a' has come once before and there is no other unique character until this index therefore '0' will be the answer
at index 2 : 'b' is the first non repeating character until this index.
at index 3 : 'b' is the first non repeating character until this index.
*/

#include <bits/stdc++.h>
using namespace std;

vector<char> firstnonrepeating(vector<char> str){
    queue<char> q;
    vector<char> result;
    int freq[26]={0};
    for(int i=0;i<str.size();i++){
        q.push(str[i]);
        freq[str[i]-'a']++;
        while(!q.empty()){
            if(freq[q.front()-'a']>1){
                q.pop();
            }else{
                result.push_back(q.front());
                break;
            }
        }
        if(q.empty()){
            result.push_back('0');
        }
    }
    return result;
}
