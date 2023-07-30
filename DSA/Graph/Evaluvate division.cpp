class Solution {
public:
    double dfs(unordered_map<string,vector<pair<string,double>>> mp, unordered_set<string>& visited, string num, string den){
        if(mp.find(num)==mp.end() or mp.find(den)==mp.end()) return -1;
        if(num==den) return 1;
        for(auto i:mp[num]){
            if(visited.find(i.first)==visited.end()){
                visited.insert(i.first);
                double res = dfs(mp,visited,i.first, den);
                if(res!=-1) return res* i.second;
            }
        }
        return -1;
    }
    vector<double> calcEquation(vector<vector<string>>& e, vector<double>& v, vector<vector<string>>& q) {
        unordered_map<string,vector<pair<string,double>>> mp;
        for(int i=0;i<e.size();i++){
            string num = e[i][0];
            string den = e[i][1];
            double val = v[i];
            mp[num].push_back({den,val});
            mp[den].push_back({num,1/val});
        }
        vector<double> ans;
        for(int i=0;i<q.size();i++){
            string qnum = q[i][0];
            string qdim = q[i][1];
            unordered_set<string> visited;
            double res = dfs(mp, visited, qnum, qdim);
            ans.push_back(res);
        }
        return ans;
    }
};