/*
Given a binary string as input, convert into its decimal form and return it as an integer.
Input Format
In the function a binary string is passed.
Output Format
Return an integer.
Sample Input
111
Sample Output
7
*/

/// 1st solution

#include <iostream>
#include <string>
#include<cmath>
using namespace std;

int binaryToDecimal(string s){
    int ans=0;
    int number=stoi(s), i=0;
    while(true){
        if(number%10==1){
            ans+=2^i;
            i++;
            number=number/10;
        }else{
            i++;
        }
    }
    return ans;
}


/// 2nd Solution

#include <iostream>
#include <string>
#include<cmath>
using namespace std;

int binaryToDecimal(string s){
    int ans=0, base=1;
    for(int i=s.size()-1;i>=0;i--){
        if(s[i]=='1'){
            ans+=base;
        }
        base*=2;
    }
    return ans;
}

