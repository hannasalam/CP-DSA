class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        // 1 -> <1,2>
        //<dest,weight>
        vector<vector<pair<int,int>>> adj(n+1);
        for(int i=0;i<times.size();i++){
            int source = times[i][0];
            int dest = times[i][1];
            int weight = times[i][2];
            adj[source].push_back({dest,weight});
        }
        vector<int> dis(n+1,INT_MAX);
        //wight, dest
        priority_queue<pair<int,int>,vector<pair<int,int>>, greater<pair<int,int>>> pq;
        pq.push({0,k});
        dis[k] = 0;
        while(!pq.empty()){
            auto top = pq.top();
            pq.pop();
            int curr_w = top.first;
            int curr_n = top.second;
            for(auto i:adj[curr_n]){
                if(dis[i.first]> curr_w + i.second){
                    dis[i.first] = curr_w + i.second;
                    pq.push({dis[i.first],i.first});
                }
            }
        }
        int vis = 0;
        int ans = 0;
        for(int i=1;i<=n;i++){
            if(dis[i]==INT_MAX) return -1;
            ans = max(ans,dis[i]);
        }
        return ans;

    }
};