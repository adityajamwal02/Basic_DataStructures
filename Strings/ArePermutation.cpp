/*
Given two strings A and B. Check if one string is permutation of the other.
A Permutation of a string is another string that contains same characters, only the order of characters can be different. For example, “abcd” and “dabc” are Permutation of each other.
Input Format
In the function two strings passed.
Output Format
Return true if B is permutation of A else false.
Sample Input
string A = "test", B = "ttew"
Sample Output
NO
*/

#include <bits/stdc++.h>
using namespace std;

bool arePermutation(string A, string B)
{
    if(A.size()!=B.size()){
        return false;
    }
    sort(A.begin(), A.end());
    sort(B.begin(), B.end());
    for(int i=0;i<A.size();i++){
        if(A[i]!=B[i]){
            return false;
        }
    }
return true;
}
