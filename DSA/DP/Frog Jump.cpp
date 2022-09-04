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