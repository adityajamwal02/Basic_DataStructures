/*
Quick Recap About Strings:
String Declaration
String Functions
String Questions
String Execution
Time Complexity
*/

/// Basic Declaration and intialization

#include<iostream>
#include<string>
using namespace std;

int main(){
    string name="Aditya";
    string surname("Jamwal");   // Raw String Format;
    string age="20";

    /// Front and back
    cout<<name.front()<<endl;
    cout<<surname.back()<<endl;

    /// At function
    char ch=surname.at(3);
    if(ch>='a' and ch<='z'){
        cout<<char(ch-32)<<endl;
    }

    /// Compare Function
    string s1="Hero:";
    string s2="Hero:";
    if(s1.compare(s2)==0){
        cout<<"TRUE"<<endl;
    }else{
        cout<<"FALSE"<<endl;
    }

    /// Find Function
    string to_be_find="ro";
    cout<<s1.find(to_be_find)<<endl;

    cout<<name<<" "<<surname<<endl<<age;
    return 0;
}

