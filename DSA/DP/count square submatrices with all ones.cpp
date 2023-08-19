    int countSquares(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        vector<vector<int>> dp(m,vector<int> (n,0));
        int count = 0;
        for(int i=0;i<m;i++){
            if(matrix[i][0]){
                dp[i][0] = 1;
                count++;
            }
        }
        cout<<count<<"\n";
        for(int i=1;i<n;i++){
            if(matrix[0][i]){
                dp[0][i] = 1;
                count++;
            }
        }
        cout<<count<<"\n";
        for(int i=1;i<m;i++){
            for(int j=1;j<n;j++){
                if(matrix[i][j]){
                    dp[i][j] = min(dp[i-1][j],min(dp[i][j-1],dp[i-1][j-1]))+1;
                    count+= dp[i][j];
                }
            }
        }
        return count;
    }