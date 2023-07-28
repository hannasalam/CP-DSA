    //minmax
    
    int find(vector<int>& nums,int start,int end, vector<vector<int>>& dp){
        if(start>end){
            return 0;
        }
        if(dp[start][end]!=INT_MIN) return dp[start][end]; 
        int leftf = nums[start] - find(nums,start+1,end,dp);
        int rightf = nums[end] - find(nums,start,end-1,dp);
        return dp[start][end] = max(leftf,rightf);
    }
    bool PredictTheWinner(vector<int>& nums) {
        vector<vector<int>> dp(nums.size(),vector<int>(nums.size(),INT_MIN));
        int ans = find(nums,0,nums.size()-1,dp);
        if(ans>=0) return true;
        return false;
    }