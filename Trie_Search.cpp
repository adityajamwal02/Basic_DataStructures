#include<bits/stdc++.h>
#include<unordered_map>
using namespace std;

class trie;

class node{
    char data;
    unordered_map<char,node*> m;
    bool isTerminal;

    node(char d)
    {
        data=d;
        isTerminal=false;
    }

    friend class trie;
};

class trie{
    node* root;

public:
    trie()
    {
        root= new node('\0 ');
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

    bool searching(string word)
    {
        node* temp=root;
        for(char ch:word)
        {
            if(temp->m.count(ch)==0)
            {
                return false;
            }
            temp=temp->m[ch];
        }
        return temp->isTerminal;
    }
};

int main()
{
    trie t;
    string key;
    string words[]={"hello","he","hell","hi","Hola"};
    for(auto word : words)
        t.insertion(word);

    cin>>key;
    cout<<t.searching(key)<<endl;

    return 0;

}
