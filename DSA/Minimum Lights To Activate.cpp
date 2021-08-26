int Solution::solve(vector<int> &A, int B) {
    int ans=0,i=0,n=A.size();
    while(i<n)
    {
        int id = -1;
        for(int j=max(0,i-B+1);j<min(n,i+B);j++)
        {
            if(A[j]==1) id = j;
        }
        if(id==-1) return -1;
        ans++;
        i = id+B;
    }
    return ans;
    
}