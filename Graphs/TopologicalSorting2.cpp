/// Kahn's Algorithm (BFS Traversal)
/* Uses Indegree (no. of incoming edges to a node), queue */

vector<int> topoSort(int v, vector<int> adj[]){
    int indegree[v]={0};
    for(int i=0;i<v;i++){
        for(auto it: adj[i]){
            indegree[it]++;
        }
    }
    queue<int> q;
    for(int i=0;i<v;i++){
        if(indegree[i]==0){
            q.push(i);
        }
    }
    vector<int> ans;
    while(!q.empty()){
        int node=q.front();
        q.pop();
        ans.push_back(node);
        for(auto it: adj[node]){
            indegree[it]--;
            if(indegree[it]==0){
                q.push(it);
            }
        }
    }
    return ans;
}
