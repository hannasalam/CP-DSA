class Solution {
  private:
    void dfs(int s, vector<int> adj[], int visited[], vector<int> &ls)
    {
        if(!visited[s])
        {
            visited[s] =1;
            ls.push_back(s);
        }
        for(auto it: adj[s])
            if(!visited[it])
                dfs(it,adj,visited,ls);
    }
  public:
    // Function to return a list containing the DFS traversal of the graph.
    vector<int> dfsOfGraph(int V, vector<int> adj[]) {
        int visited[V] = {0};
        vector<int> ls;
        dfs(0,adj,visited,ls);
        return ls;
        
    }
};