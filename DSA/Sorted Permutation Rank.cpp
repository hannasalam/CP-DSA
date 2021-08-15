int fact(int n)
{
    if(n==0||n==1) return 1;
    int ans = 1;
    for(int i=2;i<=n;i++)
    {
        ans= (ans% 1000003)*(i% 1000003);
    }
    return ans% 1000003;
}
 
 
int Solution::findRank(string A) {
 
    string copy = A,s = A;
    int r = A.size();
    long long pos = 0;
    for(int i=0;i<A.size();i++)
    {  
        long long count = 0;
        for(int j = i+1;j<A.size();j++)
        {
            if(A[j]<A[i]) count++;
        }
        pos+= (count*fact(A.size()-i-1))% 1000003;
        
    }
    return (pos+1)% 1000003;
}  