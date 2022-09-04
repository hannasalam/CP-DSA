int tryer(int *arr, int n , vector<int> &dp)
    {
        if(n==0) return arr[0];
        if(n<0) return 0;
        if(dp[n]!=-1) return dp[n];
        int oneJump = arr[n]+ tryer(arr, n-2, dp);
        int secondJump = 0 + tryer(arr, n-1, dp);
        return dp[n]=max(oneJump,secondJump);
    }
	int findMaxSum(int *arr, int n) {
	    vector<int> dp(n,-1);
	    return tryer(arr, n-1, dp);
	}