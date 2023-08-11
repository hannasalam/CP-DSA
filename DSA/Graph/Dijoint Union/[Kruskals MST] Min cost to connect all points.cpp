class Solution {
public:
    //kruskal
    //disjoint set
    int findParent(int i, vector<int>& parent){
        if(parent[i]==-1){
            return i;
        }
        return parent[i] = findParent(parent[i],parent);
    }
    void Union(int i, int j, vector<int> & parent, vector<int> &rank){
        int pi = findParent(i,parent);
        int pj = findParent(j,parent);
        if(rank[pi]==rank[pj]){
            parent[pj] = pi;
            rank[pi]++;
        }
        else if(rank[pi]>rank[pj]){
            parent[pj] = pi;
        }else{
            parent[pi] = pj;
        }
    }
    int cost(vector<int>&p1, vector<int> &p2){
        return abs(p1[0]-p2[0])+abs(p1[1]-p2[1]);
    }
    int minCostConnectPoints(vector<vector<int>>& points) {
        vector<vector<int>> adj;
        for(int i=0;i<points.size();i++){
            for(int j=i+1;j<points.size();j++){
                if(i==j) continue;
                adj.push_back({cost(points[i],points[j]),i,j});
            }
        }
        vector<int> rank(points.size(),1);
        vector<int> parent(points.size(),-1);
        int cost = 0;
        sort(adj.begin(),adj.end());
        for(auto v:adj){
            int currcost = v[0];
            int i = v[1];
            int j = v[2];
            if(findParent(i,parent)!=findParent(j,parent)){
                Union(i,j,parent,rank);
                cost+= currcost;
            }
        }
        return cost;
    }
};