    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        queue<pair<int,int>> q;
        int ans = -1, unrotten = 0;
        vector<vector<int>> visited(m, vector<int>(n, 0));
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==2)
                    q.push({i,j});
                else if(grid[i][j]==1)
                    unrotten++;
            }
        }
        if(q.empty() and unrotten!=0) return -1;
        if(unrotten==0) return 0;
        while(!q.empty()){
            int s = q.size();
            ans++;
            for(int i=0;i<s;i++){
                auto curr = q.front();
                q.pop();
                int j = curr.first;
                int k = curr.second;
                cout<<j<<k<<"\t";
                if(j-1>=0 and grid[j-1][k]==1){
                    grid[j-1][k]=2;
                    q.push({j-1,k});
                    unrotten--;
                    cout<<"here";
                }
                if(k-1>=0 and grid[j][k-1]==1){
                    grid[j][k-1]=2;
                    q.push({j,k-1});
                    unrotten--;
                    cout<<"here";
                }
                if(j+1<m and grid[j+1][k]==1){
                    grid[j+1][k] = 2;
                    q.push({j+1,k});
                    unrotten--;
                }
                if(k+1<n and grid[j][k+1]==1){
                    grid[j][k+1] = 2;
                    q.push({j,k+1});
                    unrotten--;
                }
            }
        }
        cout<<unrotten;
        cout<<"ivdam vare ethi";
        if(unrotten!=0) return -1;
        return ans;
    }