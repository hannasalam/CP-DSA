    int solve(vector<int>& height, int n, int k,vector<int> &dp){
        if(n<=0) return 0;
        if(dp[n]!=-1) return dp[n];
        int ans = INT_MAX;
        for(int i=1;i<=k;i++){
            if(n-i>=0)
                ans = min(ans, solve(height,n-i,k,dp)+abs(height[n]-height[n-i]));
        }
        dp[n] = ans;
        return ans;
    }
    int minimizeCost(vector<int>& height, int n, int k) {
        vector<int> dp(n,-1);
        return solve(height,n-1,k,dp);
    }
//tabulization

int minimizeCost(vector<int>& height, int n, int k) {
        vector<int> dp(n,INT_MAX);
        dp[0] = 0;
        for(int i=1;i<n;i++){
            for(int j=1;j<=k;j++){
                if(i-j>=0){
                    dp[i] = min(dp[i],dp[i-j]+abs(height[i]-height[i-j]));
                }
            }
        }
        return dp[n-1];
    }