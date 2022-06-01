#include<bits/stdc++.h>
#include<unordered_map>
using namespace std;

class node{
public:

    char data;
    unordered_map<char,node*> m;
    bool isTerminal;

    node(char d)
    {
        data=d;
        isTerminal=false;
    }
};

class trie{
    node* root;

public:
    trie()
    {
        root= new node('\0');
    }

    void insertion(string word)
    {
        node* temp=root;
        for(char ch : word)
        {
            if(temp->m.count(ch)==0)
            {
                node* n= new node(ch);
                temp->m[ch]=n;
            }
            temp=temp->m[ch];
        }
        temp->isTerminal=true;
    }
};

int main()
{
    trie t;
    string key;
    string words[]={"hello","he","hell","hi","Hola"};
    for(auto word : words)
        t.insertion(word);

    for(auto word: words)
        cout<<word<<endl;

    return 0;

}

