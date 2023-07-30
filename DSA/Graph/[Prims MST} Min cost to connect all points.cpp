class Solution {
public:
    int cost(vector<int>&p1, vector<int> &p2){
        return abs(p1[0]-p2[0])+abs(p1[1]-p2[1]);
    }
    int minCostConnectPoints(vector<vector<int>>& points) {
        vector<bool> visited(points.size(),false);
        int n = points.size();
        //weight, vertex
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        pq.push({0,0});
        int ans = 0;
        int remaining = 0;
        while(remaining<n){
            auto top = pq.top();
            pq.pop();
            int weight = top.first;
            int node = top.second;
            if(visited[node]) continue;
            visited[node] = true;
            ans+= weight;
            remaining++;
            for(int i=0;i<n;i++){
                if(!visited[i]){
                    int w = cost(points[node],points[i]);
                    pq.push({w,i});
                }
            }
        }
        return ans;
    }
};