class Solution {
public:
    int timer = 0;
    void dfs(int i,int parent, vector<vector<int>>& adj, vector<int>& vis, vector<int>& time, vector<int>& low, vector<vector<int>>& ans){
        vis[i] = 1;
        low[i] = time[i] = timer;
        timer++;
        for(auto e:adj[i]){
            if(e==parent) continue;
            if(vis[e]==0){
                dfs(e,i,adj,vis,time,low,ans);
                low[i] = min(low[i],low[e]);
                if(time[i]<low[e]){
                    ans.push_back({i,e});
                }
            }else{
                low[i] = min(low[e],low[i]);
            }
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