/// DFS Algorithm (visited array, stack and graph vectors)
/* Works only for DAG (Direct Acyclic Graph, linear ordering of vertices such that there is an edge between u and v
    where u appears before v in that ordering. */

void dfs(int node, int vis[], stack<int> &st, vector<int> adj[]){
    vis[node]=1;
    for(auto it: adj[node]){
        if(!vis){
            dfs(node, vis, st, adj);
        }
    }
    st.push(node);
}
vector<int> topoSort(int v, vector<int> adj[]){
    int vis[v]={0};
    stack<int> st;
    for(int i=0;i<v;i++){
        if(!vis[i]){
            dfs(i, vis, st, adj);
        }
    }
    vector<int> ans;
    while(!st.empty()){
        ans.push_back(st.top());
        st.pop();
    }
    return ans;
}

/// Time Complexity : O(V+E) for DAG graphs
/// Space Complexity: O(2N)

