#include<bits/stdc++.h>
#include<stack>
using namespace std;

 int main()
 {
     stack<string> books;

     books.push("Java");
     books.push("C++");
     books.push("Python");

     while(!books.empty())
     {
         cout<<books.top();
         books.pop();
     }
     return 0;
 }
