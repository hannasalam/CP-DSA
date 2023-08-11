class Solution {
public:
    int findParent(int i,vector<int> &parent){
        if(parent[i] == -1) return i;
        return parent[i] = findParent(parent[i],parent);
    }
    void Union(int i,int j, vector<int> &rank, vector<int> &parent){
        int pi = findParent(i,parent);
        int pj = findParent(j,parent);
        if(pi==pj) return;
        if(rank[pj]==rank[pi] ){
            parent[pj] = pi;
            rank[pi]++;
        }else if(rank[pj]>rank[pi]){
            parent[pi] = pj;
        }else{
            parent[pj] = pi;
        }
    }
    int removeStones(vector<vector<int>>& stones) {
        vector<int> rank(stones.size()+1,1);
        vector<int> parent(stones.size()+1,-1);
        for(int i=0;i<stones.size();i++){
            for(int j = i+1;j<stones.size();j++){
                if(stones[i][0]==stones[j][0] or stones[i][1]==stones[j][1])
                    Union(i,j,rank,parent);
            }
        }
        int ans = 0;
        for(int i=0;i<stones.size();i++){
            cout<<parent[i]<<"\t";
            if(parent[i]==-1) ans++;
        }
        return stones.size()-ans;
        
    }
};