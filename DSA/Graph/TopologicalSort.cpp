vector<int> topoSort(int V, vector<int> adj[]) 
{
	    vector<int> topo;
	    int indegree[V] = {0};
	    for(int i=0;i<V;i++)
	    {
	        for(auto j:adj[i])
	        {
	            indegree[j]++;
	        }
	    }
	    queue<int> q;
	    for(int i=0;i<V;i++)
	    {
	       if(indegree[i]==0)
	                q.push(i);
	    }
	    while(!q.empty())
	    {
	        int x = q.front();
	        q.pop();
	        topo.push_back(x);
	        for(int i:adj[x])
	        {
	            indegree[i]--;
	            if(indegree[i]==0)
	                q.push(i);
	        }
	    }
	    return topo;
	}