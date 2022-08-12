/*
Count the number of distinct substrings in a string
*/

class Node
{
    Node * links[26];
    bool containsKey(char ch)
    {
        return links[ch-'a'];
    }
    void put(char ch, Node *node)
    {
        link[ch-'a']=node;
    }
    Node * get(char ch)
    {
        return links[ch-'a'];
    }
};

int countDistinctSubstrings(string &s)
{
    int cnt=0;
    Node *root=new Node();

    for(int i=0;i<s.length();i++)
    {
        Node* node=root;
        for(int j=i;j<s.length();j++){
            if(!node->containsKey(s[j])){
                cnt++;
                node->put(s[j], new Node());
            }
            node=node->get(s[j]);
        }
    }
    return cnt+1;
}
