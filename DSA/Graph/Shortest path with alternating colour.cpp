class Solution {
public:
    vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& redEdges, vector<vector<int>>& blueEdges) {
        vector<vector<pair<int,int>>> graph(n);
        for(auto e:redEdges){
            graph[e[0]].push_back({e[1],0});
        }
        for(auto e:blueEdges){
            graph[e[0]].push_back({e[1],1});
        }
        queue<vector<int>> q;
        vector<int> dist(n,-1);
        q.push({0,0,-1});
        while(!q.empty()){
            auto el = q.front();
            q.pop();
            dist[el[0]] = dist[el[0]]!=-1?min(dist[el[0]],el[1]):el[1];
            for(auto &g:graph[el[0]]){
                if(g.first!=-1 and g.second!= el[2]){
                    q.push({g.first,el[1]+1,g.second});
                    g.first = -1;
                }
            }
        }
        return dist;
        
    }
};