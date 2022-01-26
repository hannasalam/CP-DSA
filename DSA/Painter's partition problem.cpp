int Solution::paint(int A, int B, vector<int> &C) {
    long l = 1, r = 0;
    for(long i:C)
    {
        l = max(i,l);
        r+=i;
    }
    
    long ans=r;
    while(l<=r)
    {
        long m = (l+r)/2;
        long p=1, sum = 0;
        for(long i:C)
        {
            sum+=i;
            if(sum>m)
            {
                p++;
                sum = i;
            }
        }
        if(p<=A)
        {
            r = m-1;
            ans = min(ans,m);
        }
        else
        {
            l = m+1;
        }
    }
    //cout<<ans;
    return (ans%10000003*B%10000003)%10000003;
}