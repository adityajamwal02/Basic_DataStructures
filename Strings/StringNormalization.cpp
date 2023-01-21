/*
You are given a sentence with words separated by spaces.

Your task is to:

Write a function that returns a copy of this sentence where all the words:

start with a capital letter

the rest of the letters are lower case

Note:

Your function should not modify the sentence given as argument.

Sample Input

This is SO MUCH FUN!
Sample Output

This Is So Much Fun!

*/


#include<bits/stdc++.h>
using namespace std;

int skip_whitespace(string &sentence, int index){
     while (index<sentence.size() and sentence[index]==' ') {
        index+=1;
    }
    return index;
}

int normalize_word(string &sentence, int index){
    if(index<sentence.size() and sentence[index]!=' '){
        sentence[index]=toupper(sentence[index]);
        index+=1;
    }
    while(index<sentence.size() and sentence[index]!=' '){
        sentence[index]=tolower(sentence[index]);
        index+=1;
    }
    return index;
}

string normalize(const string &sentence) {
    string copy=sentence;
    int index=0;
    while(index<copy.size()){
        index=skip_whitespace(copy,index);
        index=normalize_word(copy,index);
    }
}
