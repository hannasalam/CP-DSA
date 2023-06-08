int findEnergyLost(vector<int> &dp, int n, vector<int> &heights)
{
    if(n==0) return 0;
    if(dp[n]!=-1) return dp[n];
    int left = findEnergyLost(dp,n-1,heights) + abs(heights[n]-heights[n-1]);
    int right = 1000;
    if(n>1){
        right = findEnergyLost(dp, n-2, heights) + abs(heights[n]-heights[n-2]);
    }
    dp[n]=min(left,right);
    return dp[n];
}

int frogJump(int n, vector<int> &heights)
{
    vector<int> dp(n,-1);
    return findEnergyLost(dp, n-1, heights);
}

//tabulization
int minimumEnergy(vector<int>& height, int n) {
        vector<int> dp(n,-1);
        // return solve(height,n-1,dp);
        dp[0] = 0;
        dp[1] = abs(height[1]-height[0]);
        for(int i=2;i<n;i++){
            dp[i] = min(dp[i-1]+abs(height[i] - height[i-1]), dp[i-2]+abs(height[i] - height[i-2]));
        }
       return dp[n-1];
}

//tabulization constant space

    int minimumEnergy(vector<int>& height, int n) {
        vector<int> dp(n,-1);
        // return solve(height,n-1,dp);
        int f = 0;
        if(n==1) return 0;
        int s = abs(height[1]-height[0]);
        for(int i=2;i<n;i++){
            int t = min(s+abs(height[i] - height[i-1]), f+abs(height[i] - height[i-2]));
            f = s;
            s = t;
            
        }
       return s;
    }