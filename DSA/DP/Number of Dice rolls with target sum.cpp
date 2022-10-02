int arr[31][1001] = {};
    int numRollsToTarget(int n, int k, int target) {
        if(n==0 || target<=0) return n==target;
        if(arr[n][target]) return arr[n][target]-1;
        int ways = 0;
        for(int i=1;i<=k;i++)
        {
            ways = (ways+numRollsToTarget(n-1, k, target-i)) % 1000000007;
        }
        arr[n][target]=ways+1;
        return ways;
    }