class Solution {
public:
    int timer = 0;
    void dfs(vector<vector<int>>& adj, int i, int p,vector<int>& dis, vector<int>& low,vector<vector<int>>& ans,vector<int>& vis){
        vis[i] = true;
        dis[i] = time;
        low[i] = time;
        time++;
        for(auto j:adj[i]){
            if(j==p or j==i) continue;
            if(vis[j]==0){
                dfs(adj,j,i,dis,low,ans,vis);
            }
            if(j!=i){
                low[i] = min(low[i],low[j]);
            }
            if(dis[i]<low[j]) ans.push_back({i,j});
        }
    }
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        vector<vector<int>> adj(n);
        for(auto e:connections){
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }

        vector<int> vis(n,0);
        vector<int> time(n,-1);
        vector<int> low(n,-1);
        vector<vector<int>> ans;
        dfs(0,-1,adj,vis,time,low,ans);
        return ans;

    }
};