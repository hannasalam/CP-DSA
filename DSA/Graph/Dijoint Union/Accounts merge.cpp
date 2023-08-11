class Solution {
public:
    int findParent(int i,vector<int> &parent){
        if(parent[i]==-1) return i;
        return parent[i] = findParent(parent[i],parent);
    }
    void Union(int i,int j, vector<int> &parent, vector<int> &rank){
        int pi = findParent(i,parent);
        int pj = findParent(j,parent);
        if(pi==pj) return;
        if(rank[pi]==rank[pj]){
            parent[pj] = pi;
            rank[pi]++;
        }else if(rank[pj]>rank[pi]){
            parent[pi] = pj;
        }else{
            parent[pj] = pi;
        }
    }
    vector<vector<string>> accountsMerge(vector<vector<string>>& account) {
        int n = account.size();
        vector<int> parent(n,-1);
        vector<int> rank(n,0);
        unordered_map<string,int> mp;
        for(int i=0;i<n;i++){
            for(int j=1;j<account[i].size();j++){
                if(mp.find(account[i][j])!=mp.end()){
                    Union(mp[account[i][j]],i,parent,rank);
                }else{
                    mp[account[i][j]] = i;
                }
            }
        }
        unordered_map<int,set<string>> place;
        for(int i=0;i<n;i++){
            int k = findParent(i,parent);
            for(int j = 1;j<account[i].size();j++){
                place[k].insert(account[i][j]);
            }
        }
        vector<vector<string>> ans(place.size());
        int i = 0;
        for(auto s:place){
            string name = account[s.first][0];
            ans[i].push_back(name);
            for(auto e:s.second){
                ans[i].push_back(e);
            }
            i++;
        }
        return ans;
    }
};