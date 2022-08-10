/*
Return the maximum length string present in the vector array
which contains all the prefixes of maximum string
*/

struct Node
{
    Node *links[26];
    bool flag=false;

    bool containsKey(char ch)
    {
        return links[ch-'a'];
    }

    Node *get(char ch)
    {
        return links[ch-'a'];
    }

    void put(char ch, Node *node)
    {
        links[ch-'a']=node;
    }

    void setEnd()
    {
        flag=true;
    }

    bool isEnd()
    {
        return flag;
    }
};

class Trie
{
    Node *root;
public:
    Trie()
    {
        root= new Node();
    }

    void Insert(string &word)
    {
        Node * node=root;
        for(int i=0;i<word.length();i++)
        {
            if(!node->containsKey())
                node->put(word[i]);

            node=node->get(word[i]);
        }
        node->setEnd();
    }

    bool checkIfPrefixExists(string word)
    {
        bool fl=true;
        Node * node= root;
        for(int i=0;i<word.length();i++)
        {
            if(node->containsKey(word[i]))
            {
                node=node->get(word[i]);
                if(node->isEnd()==false)
                    return false;
            }
            return false;
        }
        return true;
    }
};

string completeString(int n, vector<string> &a)
{
    Trie trie;
    for(auto &it:a)
        trie.Insert(it);

    string longest="";
    for(auto &it: a)
    {
        if(checkIfPrefixExists(it))
        {
            if(it.length() > longest.length())
                longest=it;
            else if(it.length()==longest.length() and it < longest)
                longest=it;
        }
    }

    if(longest=="")
        return "None";

    return longest;
}
