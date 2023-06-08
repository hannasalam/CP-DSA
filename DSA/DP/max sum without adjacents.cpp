	int solve(int *arr, int n, vector<int> &dp){
	    if(n<0) return 0;
	    if(dp[n]!=-1) return dp[n];
	    int case1 = solve(arr,n-2,dp)+ arr[n];
	    int case2 = solve(arr,n-1,dp);
	    dp[n] = max(case1,case2);
	    return dp[n];
	}
	int findMaxSum(int *arr, int n) {
	    vector<int> dp(n,-1);
	    dp[0] = arr[0];
	    return solve(arr,n-1,dp);
	}

//tabulization

	int findMaxSum(int *arr, int n) {
	    if(n==1) return arr[0];
	    vector<int> dp(n,-1);
	    dp[0] = arr[0];
	    dp[1] = max(dp[0],arr[1]);
	    for(int i=2;i<n;i++){
	        int case1 = dp[i-2]+arr[i];
	        int case2 = dp[i-1];
	        dp[i] = max(case1,case2);
	    }
	    return dp[n-1];
	}

//tabulization constant space

	int findMaxSum(int *arr, int n) {
	    if(n==1) return arr[0];
	    vector<int> dp(n,-1);
	    int f = arr[0];
	    int s = max(f,arr[1]);
	    for(int i=2;i<n;i++){
	        int case1 = f+arr[i];
	        int case2 = s;
	        f = s;
	        s = max(case1,case2);
	    }
	    return s;
	}