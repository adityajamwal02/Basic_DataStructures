#include<bits/stdc++.h>
using namespace std;

bool isPalindrome(string str)
{
    string temp=str;
    reverse(temp.begin(), temp.end());
    if(temp==str){
        return true;
    }
return false;
}
