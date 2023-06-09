//memoization
    int solve(vector<vector<int>>& grid, int i, int j, vector<vector<int>> &dp){
        if(i==0 and j==0) return grid[0][0];
        if(i<0 or j<0 ) return INT_MAX;
        if(dp[i][j]!= -1) return dp[i][j];
        int top = solve(grid,i,j-1,dp);
        int left = solve(grid,i-1,j,dp);
        return dp[i][j] = grid[i][j] + min(top,left);
    }
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> dp(m,vector<int>(n,-1));
        return solve(grid,m-1,n-1,dp);
    }

//tabulation

int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> dp(m,vector<int>(n,-1));
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(i==0 and j==0){
                    dp[0][0] = grid[0][0];
                    continue;
                }
                int left = INT_MAX, top = INT_MAX;
                if(i>0)
                    left = dp[i-1][j];
                if(j>0)
                    top = dp[i][j-1];
                dp[i][j] = grid[i][j] + min(top,left);
            }
        }
        return dp[m-1][n-1];
    }