class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int dt) {
        int mini = n, city = 0;
        vector<vector<int>> dist(n,vector<int>(n,INT_MAX));
        for(auto e:edges){
            dist[e[0]][e[1]] = e[2];
            dist[e[1]][e[0]] = e[2];
        }
        for(int i=0;i<n;i++) dist[i][i] = 0;

        for(int k=0;k<n;k++){
            for(int i=0;i<n;i++){
                for(int j=0;j<n;j++){
                    if(dist[i][k]!=INT_MAX and dist[k][j]!=INT_MAX and dist[i][j]>dist[i][k]+dist[k][j]){
                        dist[i][j] = dist[i][k]+dist[k][j];
                    }
                }
            }
        }
        for(int i=0;i<n;i++){
            int curr=0;
            for(int j=0;j<n;j++){
                if(dist[i][j]<=dt and i!=j){
                    curr++;
                }
            }
            cout<<curr<<"\t";
            if(mini>=curr) {
                city = i;
                mini = curr;
            }
        }
        return city;
        
    }
};