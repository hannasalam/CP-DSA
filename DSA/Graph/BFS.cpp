vector<int> bfsOfGraph(int V, vector<int> adj[]) {
        queue<int> next;
        vector<int> visited(V,0);
        vector<int> bfs;
        next.push(0);
        visited[0] = 1;
        while(!next.empty())
        {
            int current = next.front();
            next.pop();
            bfs.push_back(current);
            for(auto it:adj[current])
            {
                if(!visited[it])
                {
                    visited[it]=1;
                    next.push(it);
                }
            }
        }
        return bfs;
        
        
    }