/*
You are given a vector of numbers. You want to concatenate these numbers together to form the lexicographically largest number. Print that largest number number. You can't rearrange the digits of any number, however you can place the numbers next to each other in any order.
Input
10,11,20,30,3
Output
330201110
You can verify that this is the largest number that we can form.
Hint
Use Sorting.
(This is a bit tricky problem, we have discussed a similar problem in sorting & searching section - Smallest String. In case you are not able to solve it right now, you can come back and solve it later)conc
*/

#include<bits/stdc++.h>
using namespace std;

bool comp(string s1, string s2){
    return s1+s2 > s2+s1;
}
string concatenate(vector<int> numbers){
    vector<string> output;
    for(int no : numbers){
        output.push_back(to_string(no));
    }
    sort(output.begin(), output.end(), comp);
    string ans="";
    for(string x: output){
        ans+=x;
    }
return ans
}
