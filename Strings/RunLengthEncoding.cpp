/*
Run Length Encoding
Write a function to perform basic string compression using the counts of repeated characters, also known as Run Length Encoding. Let see one example, the input string "aaaabcccccaaa" would become "a4b1c5a3". If the "compressed" string would not become smaller than the original string, your function should return the input string. You can assume the string has only uppercase and lowercase letters. You may use the to_string(int) method to convert an integer into string.
Sample Inputs
bbbaaaadexxxxxx
abc
Sample Outputs
b3a4d1e1x6
abc
*/


#include<bits/stdc++.h>
using namespace std;

string compressString(const string &str){
    string result="";
    int count=1;
    for(int i=0;i<str.size();i++){
        if(str[i]==str[i+1]){
            count++;
            continue;
        }else if(str[i]!=str[i+1]){
            result+=(str[i]+to_string(count));
            count=1;
            continue;
        }
    }
    return str.size()<result.size() ? str : result;
}
