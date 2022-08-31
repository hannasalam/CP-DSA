class Solution {
    private:
    void dfs(int s, vector<int> &visited, vector<vector<int>>& isConnected){
        visited[s] = 1;
        for(int i=0;i<isConnected[s].size();i++)
        {
            if(isConnected[s][i]==1)
            {
                if(!visited[i])
                    dfs(i,visited,isConnected);
            }
        }
    }
    public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int V = isConnected.size();
        vector<int> visited(V,0);
        int flag = 0;
        int province = 0;
            for(int i=0;i<V;i++)
            {
                if(!visited[i])
                {
                    province++;
                    dfs(i,visited,isConnected);
                    continue;
                }
            }
        return province;
        
        
    }
};