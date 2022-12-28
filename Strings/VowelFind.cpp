/*
Given a string consisting of lowercase English alphabets, return a string containing all the vowels present in S in serial order.
Input Format
In the function a string S is passed.
Output Format
Return a string.

Sample Input
S = "aeoibsddaeioudb"
Sample Output
"aeoiaeiou"
*/

#include<bits/stdc++.h>
#include<string>
using namespace std;

string vowel(string S){
    string result;
    for(int i=0;i<S.size();i++)
    {
        if(S[i]=='a' || S[i]=='e' ||S[i]=='i' ||S[i]=='o' ||S[i]=='u')
        {
            result.push_back(S[i]);
        }
    }
    return result;
}
