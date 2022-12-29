/*
Sort Fruits!
Given a vector of pairs of a string and an integer representing names and prices of different fruits. A string is also passed as a parameter with name equals either "price", meaning you have to sort the fruits on the basis of their price or "name", which means you have to sort the fruit on the basis of their name.
Input Format
In the function an integer vector of pairs is passed.
Output Format
Return an integer vector of pairs in sorted order.

Sample Input
{ (Mango,100), (Guava,70), (Grapes,40), (Apple,60), (Banana,30) }, S = "price"
Sample Output
{ ("Banana", 30), ("Grapes", 40), ("Apple", 60), ("Guava", 70), ("Mango", 100) }
*/


#include<bits/stdc++.h>
using namespace std;

bool compare(pair<string, int> a, pair<string, int> b){
    return a.second<b.second;
}

vector<pair<string,int>> sortFruits(vector<pair<string,int>> v, string S){
    if(S=="name") sort(v.begin(), v.end());
    else sort(v.begin(), v.end(), compare);
    return v;
}
