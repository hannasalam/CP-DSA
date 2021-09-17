int minSwap(int *arr, int n, int k) {
    int sm = 0;
    for(int i=0;i<n;i++)
    {
        if(arr[i]<=k)
            sm++;
    }
    int gt = 0;
    for(int i=0;i<sm;i++)
    {
        if(arr[i]>k)
            gt++;
    }
    int ans = gt;
    for(int i=0,j=sm;j<n;i++,j++)
    {
        if(arr[i]>k) gt--;
        if(arr[j]>k) gt++;
        ans = min(ans,gt);
    }
    return ans;
}